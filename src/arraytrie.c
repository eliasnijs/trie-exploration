/* depends on:
 * stdio.h, stdlib.h, stdint.h, stddef.h, stdbool.h, string.h,
 * base/base.c, base/utils.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "utils/base.h"

/* Implementation of an Array Trie Datastructure, more specifically a Patricia
 * Trie. The rationale and specifics of this structure can be found in the
 * following paper:
 *
 * Morrison, D. R. (1968). PATRICIA—practical algorithm to retrieve information
 * coded in alphanumeric. Journal of the ACM (JACM), 15(4), 514-534.
 *
 * This implementation of the Patricia Trie is for ASCII strings.
 * */

/* macros and typedefs */
#ifndef ARRAYTRIE_ALPHASIZE
#define ARRAYTRIE_ALPHASIZE 0b1111111
#endif

/* enumerations, structs, unions */
struct atrie_node {
	char *ls;	/* if the node is a leafe, complete string,
			   otherwise a zero-pointer */
	char *s;	/* substring represented by the node */
	int16 m;	/* the length of s */
	struct atrie_node *next[ARRAYTRIE_ALPHASIZE];
};

struct atrie {
	struct atrie_node *root;
	size_t wc;
};

/* function definitions */
struct atrie * arraytrie_init();
void arraytrie_free(struct atrie *at);
void arraytrie_print(FILE *f, struct atrie *at);
bool arraytrie_add(struct atrie *at, const char *s);
bool arraytrie_search(struct atrie *at, const char *s);
bool arraytrie_remove(struct atrie *at, const char* s);
size_t arraytrie_size(struct atrie *trie);

internal void _arraytrie_free(struct atrie_node *n);
internal void _arraytrie_remove(struct atrie_node **n, const char *s, int32 l,
				 int32 i_s, bool *is_success);
internal void _arraytrie_print(FILE *f, struct atrie_node *n, int32 j, int32 w,
			       bool32 enter);
internal struct atrie_node * node_new(const char *s, int32 m);
internal void node_die(struct atrie_node *n);

/* function implementations */
internal struct atrie_node *
node_new(const char *s, int32 m)
{
	struct atrie_node *n = (struct atrie_node *)calloc(
	    1, sizeof(struct atrie_node));
	if (m > 0) {
		n->m = m;
		n->s = (char *)calloc(m + 1, 1);
		memcpy(n->s, s, m);
	}
	return n;
}

internal void
node_die(struct atrie_node *n)
{
	free(n->s);
	free(n->ls);
	free(n);
}

struct atrie *
arraytrie_init()
{
	struct atrie *at = (struct atrie *)calloc(1, sizeof(struct atrie));
	at->root = (struct atrie_node *)calloc(1, sizeof(struct atrie_node));
	return at;
}

internal void
_arraytrie_free(struct atrie_node *n)
{
	if (!n) {
		return;
	}
	for (int32 i = 0; i < ARRAYTRIE_ALPHASIZE; ++i) {
		_arraytrie_free(n->next[i]);
	}
	node_die(n);
}

void
arraytrie_free(struct atrie *at)
{
	_arraytrie_free(at->root);
	free(at);
}

internal void
_arraytrie_print(FILE *f, struct atrie_node *n, int32 j, int32 w, bool32 enter)
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
	if (enter == 0) {
		fprintf(f, " ──── ");
	} else {
		fprintf(f, "└ %c ─ ", enter);
	}
	fprintf(f, "'%s'", (n->s)?n->s:"Ø");
	if (n->ls) {
		fprintf(f, "  ──── '[%sØ]'", n->ls);
	}
	for (int32 i = 1; i < ARRAYTRIE_ALPHASIZE; ++i) {
		_arraytrie_print(f, n->next[i], 0,
				 w + 10 + n->m, i);
	}
}

void
arraytrie_print(FILE *f, struct atrie *at)
{
	_arraytrie_print(f, at->root, 0,  0, 0);
	fprintf(f, "\n");
}

bool
arraytrie_search(struct atrie *at, const char *s)
{
	int32 i_s = 0, m = strlen(s);
	struct atrie_node *n = at->root;
	while (n) {
		/* check if we reached a leave and the strings are the same */
		if (n->ls && !strcmp(s, n->ls)) {
			return true;
		}
		/* check the difference between the given string and the
		 * substring in the current node */
		int32 i_diff = 0;
		while (i_diff < m && i_diff < n->m
		       && s[i_s] == n->s[i_diff]) {
			++i_diff;
			++i_s;
		}
		/* go to next node */
		n = n->next[(uint8)s[i_s]];
		++i_s;
	}
	return false;
}

bool
arraytrie_add(struct atrie *at, const char *s)
{
	int32 i_s = 0, m = strlen(s);
	struct atrie_node **n = &at->root;
	/* loop until we have a free spot for a node for the given string */
	while (*n) {
		/* check if we reached a leave and the strings are the same */
		if ((*n)->ls && !strcmp(s, (*n)->ls)) {
			return false;
		}
		/* check the difference between the given string and the
		 * substring in the current node */
		int32 i_diff = 0;
		while (i_diff < m && i_diff < (*n)->m
		       && s[i_s] == (*n)->s[i_diff]) {
			++i_diff;
			++i_s;
		}
		/* split the current node in two if the string and substring of
		 * the current node differ */
		if (i_diff < (*n)->m) {
			char splitchar = (*n)->s[i_diff];
			struct atrie_node *n2 = node_new((*n)->s, i_diff);
			char *t = (char *)calloc((*n)->m - i_diff, 1);
			memcpy(t, (*n)->s + i_diff + 1, (*n)->m - i_diff - 1);
			free((*n)->s);
			(*n)->s = t;
			(*n)->m = (*n)->m - i_diff - 1;
			n2->next[(uint8)splitchar] = *n;
			*n = n2;
		}
		/* go to next node */
		n = &(*n)->next[(uint8)s[i_s]];
		++i_s;
	}
	/* create a node for our string */
	*n = node_new(&s[i_s], m - i_s);
	(*n)->ls = (char *)calloc(m + 1, 1);
	memcpy((*n)->ls, s, m);
	++at->wc;
	return true;
}

internal void
_arraytrie_remove(struct atrie_node **n, const char *s, int32 m, int32 i_s,
		  bool *is_success)
{
	if (!*n) {
		return;
	}
	/* check the difference between the given string and the
	 * substring in the current node */
	int32 i_diff = 0;
	while (i_diff < m && i_diff < (*n)->m
	       && s[i_s] == (*n)->s[i_diff]) {
		++i_diff;
		++i_s;
	}
	/* check if we reached our string, if so, remove leave status, else
	 * recurse down to the next node */
	if ((*n)->ls && !strcmp((*n)->ls, s)) {
		free((*n)->ls);
		(*n)->ls = 0x0;
		*is_success = true;
	} else {
		_arraytrie_remove(&(*n)->next[(uint8)s[i_s]], s, m, i_s + 1,
				  is_success);
	}
	/* if the current node is not a leave and is not root, check if we
	 * can merge paths or remove nodes. */
	if (!(*n)->ls && i_s > 0) {
		int32 childcount = 0, i_repl  = 0;
		struct atrie_node *repl_n = 0x0;
		for (int32 i = 0; i < ARRAYTRIE_ALPHASIZE; ++i) {
			if ((*n)->next[i]) {
				++childcount;
				i_repl = i;
			}
		}
		switch (childcount) {
		case 1:
			repl_n = (*n)->next[i_repl];
			repl_n->m += (*n)->m + 1;
			char *newstr = (char *)calloc(repl_n->m + 1, 1);
			if ((*n)->s) {
				strcpy(newstr, (*n)->s);
			}
			newstr[(*n)->m] = (char)i_repl;
			if (repl_n->s) {
				strcpy(newstr + (*n)->m + 1, repl_n->s);
			}
			free(repl_n->s);
			repl_n->s = newstr;
			/* fallthrough */
		case 0:
			node_die(*n);
			*n = repl_n;
		}
	}
}

bool
arraytrie_remove(struct atrie *at, const char* s)
{
	bool is_success = false;
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
