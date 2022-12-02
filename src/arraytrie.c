/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h, string.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "base.c"

/* Implementation of an Array Trie Datastructure, more specifically a Patricia
 * Trie. The rationale and specifics of this structure can be found in the
 * following paper:
 *
 * Morrison, D. R. (1968). PATRICIA—practical algorithm to retrieve information
 * coded in alphanumeric. Journal of the ACM (JACM), 15(4), 514-534.
 *
 * */

/* macros and typedefs */
#define ARRAYTRIE_ALPHASIZE 0b1111111

/* enumerations, structs, unions */
struct atrie_node {
	int16 m;
	char *s;
	size_t skip;
	struct atrie_node *next[ARRAYTRIE_ALPHASIZE];
};

struct atrie {
	size_t wc;
	struct atrie_node *root;
};

/* function definitions */
struct atrie * arraytrie_init();
void arraytrie_free(struct atrie *at);
internal void _arraytrie_print(FILE *f, struct atrie_node *n, char c, int32 j,
			       int32 w, bool32 enter);
void arraytrie_print(FILE *f, struct atrie *at);
bool8 arraytrie_add(struct atrie *at, const char *s);
bool8 arraytrie_search(struct atrie *at, const char *s);
bool8 arraytrie_remove(struct atrie *at, const char* s);
size_t arraytrie_size(struct atrie *trie);
internal void _arraytrie_free(struct atrie_node *n);
internal bool8 _arraytrie_remove(struct atrie_node **n, const char *s, int32 l,
				 int32 i_s, bool8 *is_success);

/* function implementations */
struct atrie *
arraytrie_init()
{
	struct atrie *at = (struct atrie *)calloc(1, sizeof(struct atrie));
	at->wc = 0;
	at->root = (struct atrie_node *)calloc(1, sizeof(struct atrie_node));
	return at;
}

internal void
_arraytrie_free(struct atrie_node *n)
{
	for (int32 i = 0; i < ARRAYTRIE_ALPHASIZE; ++i) {
		if (n->next[i]) {
			_arraytrie_free(n->next[i]);
		}
	}
	if (n->s) {
		free(n->s);
	}
	free(n);
}

void
arraytrie_free(struct atrie *at)
{
	_arraytrie_free(at->root);
	free(at);
}

/* TODO: clean this up */
internal void
_arraytrie_print(FILE *f, struct atrie_node *n, char c, int32 j, int32 w,
		 bool32 enter)
{
	if (!n) {
		return;
	}
	if (enter) {
		fputs("\n", f);
	}
	while (j < w) {
		fputs(" ", f);
		++j;
	}
	if (c) {
		printf(":%c -- ", c);
	} else {
		printf(":Ø -- ");
	}
	if (n->s) {
		fprintf(f, "['%sØ']", n->s);
	} else {
		fprintf(f, "%2ld", n->skip);
		int32 j2 = j + 8;
		for (int32 i = 0; i < ARRAYTRIE_ALPHASIZE; ++i) {
			if (n->next[i]) {
				_arraytrie_print(f, n->next[i], (char)i, j2,
						 w + 8, j2 == 0);
				j2 = 0;
			}
		}
	}
}

void
arraytrie_print(FILE *f, struct atrie *at)
{
	_arraytrie_print(f, at->root, 0, 2, 0, false);
	fputs("\n", f);
}

bool8
arraytrie_search(struct atrie *at, const char *s)
{
	int32 m = strlen(s), i_s = 0;
	struct atrie_node *n = at->root;
	while (!n->s) {
		i_s += n->skip;
		n = n->next[(int8)s[i_s]];
		if (i_s > m || !n) {
			return false;
		}
		++i_s;
	}
	return (strcmp(n->s, s) == 0);
}

bool8
arraytrie_add(struct atrie *at, const char *s)
{
	bool8 completed = false;
	int32 m = strlen(s) + 1, i_s = 0;
	struct atrie_node **n = &at->root;
	struct atrie_node **np = 0x0;
	while (!completed) {
		if (!*n) {
			*n = (struct atrie_node *)calloc(1,
				sizeof(struct atrie_node));
	    		(*n)->m = m;
	    		(*n)->s = (char *)calloc(m, sizeof(char));
	    		strcpy((*n)->s, s);
	    		++at->wc;
	    		return true;
		}
		i_s += (*n)->skip;
		if ((*n)->s) {
			if (!strcmp((*n)->s, s)) {
				return false;
			}
			if (i_s < (*n)->m && i_s < m) {
				int32 i_s_b = i_s;
				while ((*n)->s[i_s] == s[i_s]) {
					++i_s;
				}
				struct atrie_node *n_new =
					(struct atrie_node *)calloc(
					    1, sizeof(struct atrie_node));
				n_new->skip = i_s - i_s_b;
				n_new->next[(int8)(*n)->s[i_s]] = *n;
				*n = n_new;
			} else if (i_s >= (*n)->m && i_s <= m){
				i_s = (*n)->m - 1;
				int32 i_s_b = i_s;
				while ((*n)->s[i_s] == s[i_s] && i_s > 0) {
					--i_s;
				}
				struct atrie_node *n_new =
					(struct atrie_node *)calloc(
					    1, sizeof(struct atrie_node));
				n_new->skip = (*np)->skip - (i_s_b - i_s);
				(*np)->skip = (i_s_b - i_s) - 1;
				n_new->next[(int8)(*n)->s[i_s]] = *np;
				*np = n_new;
				n = np;
			} else {
				DebugLogError("not implemented yet");
				return false;
			}
		}
		np = n;
	  	n = &(*n)->next[(int8)s[i_s]];
	  	++i_s;
	}
	return false;
}

internal bool8
_arraytrie_remove(struct atrie_node **n, const char *s, int32 l, int32 i_s,
		  bool8 *is_success)
{
	if (i_s > l + 1 || !(*n)) {
		return false;
	}
	if ((*n)->s) {
		if (strcmp((*n)->s, s) == 0) {
			free((*n)->s);
			free(*n);
			*n = 0;
			*is_success = true;
			return true;
		} else {
			return false;
		}
	} else {
		i_s += (*n)->skip;
		bool8 is_rm = _arraytrie_remove(&(*n)->next[(int8)s[i_s]],
						s, l, i_s + 1, is_success);
		/* TODO (Elias): join nodes / rebalancing */
		bool8 is_zero_buf = true;
		for (uint8 i = 0; i < ARRAYTRIE_ALPHASIZE && is_zero_buf; ++i) {
			is_zero_buf = (*n)->next[i] == 0x0;
		}
		if (is_zero_buf) {
			return true;
		}
	}
	return false;
}

bool8
arraytrie_remove(struct atrie *at, const char* s)
{
	bool8 is_success = false;
	_arraytrie_remove(&at->root, s, strlen(s), 0, &is_success);
	if (is_success) {
		--at->wc;
	}
	return is_success;
}

size_t
arraytrie_size(struct atrie *trie)
{
	return trie->wc;
}
