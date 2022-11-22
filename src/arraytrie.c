#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "base.h"

#define ALPHASIZE 0b1111111

struct atrie_node {
	char *s;
	uint16 skip;
	struct atrie_node *next[ALPHASIZE];
};

struct atrie {
	size_t wc;
	struct atrie_node *root;
};

struct atrie *
arraytrie_init()
{
	struct atrie *at = (struct atrie *)malloc(sizeof(struct atrie));
	at->wc = 0;
	at->root = (struct atrie_node *)calloc(1, sizeof(struct atrie_node));
	return at;
}

internal void
_arraytrie_free(struct atrie_node *n)
{
	for (int32 i = 0; i < ALPHASIZE; ++i) {
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

bool
arraytrie_search(struct atrie *at, const char *s)
{
	int32 m = strlen(s), s_i = 0;
	struct atrie_node *n = at->root;
	while (!n->s) {
		s_i += n->skip;
		n = n->next[(int8)s[s_i]];
		if (s_i > m || !n) {
			return false;
		}
		++s_i;
	}
	return (strcmp(n->s, s) == 0);
}

bool
arraytrie_add(struct atrie *at, const char *s)
{
	int32 m = strlen(s), s_i = 0;
	struct atrie_node **n = &at->root;
	while (s[s_i]) {
		if (!*n) {
			*n = (struct atrie_node *)calloc(1,
				sizeof(struct atrie_node));
	    		(*n)->s = (char *)malloc(m + 1);
	    		strcpy((*n)->s, s);
	    		++at->wc;
	    		return true;
		}
		s_i += (*n)->skip;
	  	if (!s[s_i]) {
			return false;
		}
	  	if ((*n)->s) {
			int32 s_i_start = s_i;
			while (s[s_i] == (*n)->s[s_i]
			       && s[s_i] && (*n)->s[s_i])  {
				++s_i;
			}
			if (!s[s_i] && !(*n)->s[s_i]) {
				return false;
			}
			int32 diff = s_i - s_i_start;
			struct atrie_node *n_new = (struct atrie_node *)calloc(
			    1, sizeof(struct atrie_node));
			n_new->skip = diff;
			n_new->next[(int8)((*n)->s[s_i])] = *n;
			*n = n_new;
	  	}
	  	n = &(*n)->next[(int8)s[s_i]];
	  	++s_i;
	}
	return false;
}

internal bool
_arraytrie_remove(struct atrie_node **n, const char *s, int32 l, int32 s_i,
		  bool *is_success)
{
	if (s_i > l + 1 || !(*n)) {
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
		s_i += (*n)->skip;
		bool is_rm = _arraytrie_remove(&(*n)->next[(int8)s[s_i]],
						s, l, s_i + 1, is_success);

		// TODO (Elias): join nodes / rebalancing
		bool is_zero_buf = true;
		for (uint8 i = 0; i < ALPHASIZE && is_zero_buf; ++i) {
			is_zero_buf = (*n)->next[i] == 0x0;
		}
		if (is_zero_buf) {
			return true;
		}
	}
	return false;
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
