/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "utils/base.h"

/* #include "utils/m_utils.c" */
/* #include "utils/m_pool.c" */

/* Implementation of the Ternary Trie Datastructure. The rationale and specifics
 * of this structure can be found in the following paper:
 *
 * Bentley, J. L., & Sedgewick, R. (1997, January). Fast algorithms for sorting
 * and searching strings. In Proceedings of the eighth annual ACM-SIAM
 * symposium on Discrete algorithms (pp. 360-369).
 *
 * This implementation of the Patricia Trie is for ASCII strings.
 * */

/* IMPORTANT(Elias): A pooling allocator was defined. However at the moment all
 * statements related to this allocator are commented out. This is because we do
 * not have any information about the data upfront in our assignment.
 * Using this allocator can deliver a significant speedup since memory is less
 * fragmented.*/

/* macros */

/* enumerations, structs, unions */
struct ttrie_node  {
	char *s;		/* if the node is a leafe, complete string,
				 * otherwise a zero-pointer */
	char splitchar;
	union {			/* a union was used so it's possible to index
				 * lo and hi from a compare statement */
		struct ttrie_node *cs[3];
		struct {
			struct ttrie_node  *lo, *hi, *eq;
		};
	};
};

struct ttrie {
	struct ttrie_node *root;
	size_t wc;
	/* struct m_pool pool; */
};

/* function definitions */
struct ttrie * ternarytrie_init_wmem(size_t backbufferlen);
struct ttrie * ternarytrie_init();
void ternarytrie_free(struct ttrie *tst);
void ternarytrie_print(FILE *f, struct ttrie *tst);
bool ternarytrie_add(struct ttrie *tst, const char* s);
bool ternarytrie_search(struct ttrie *tst, const char* s);
bool ternarytrie_remove(struct ttrie *tst, const char *s);
size_t ternarytrie_size(struct ttrie *tst);
internal void _ternarytrie_print(FILE *f, struct ttrie_node *n, int32 j,
				 int32 w, bool32 enter);
/* internal void _ternarytrie_remove(struct ttrie_node **n, const char *c, */
/* 				  const char *s, bool *is_success, */
/* 				  struct m_pool *pool); */
internal void _ternarytrie_remove(struct ttrie_node **n, const char *c,
				  const char *s, bool *is_success);
/* internal void _ternarytrie_die(struct ttrie_node *n, struct m_pool *pool); */
internal void _ternarytrie_die(struct ttrie_node *n);


/* function implementations */

/* struct ttrie * */
/* ternarytrie_init_wmem(size_t backbufferlen) */
/* { */
/* 	struct ttrie *tst = (struct ttrie *)calloc(1, sizeof(struct ttrie)); */
/* 	uint8 *bb = (uint8 *)malloc(backbufferlen); */
/* 	m_pool_init(&tst->pool, bb, backbufferlen, */
/* 		    sizeof(struct ttrie_node), MEM_DEFAULT_ALIGNMENT); */
/* 	return tst; */
/* } */

struct ttrie *
ternarytrie_init()
{
	struct ttrie *tst = (struct ttrie *)calloc(1, sizeof(struct ttrie));
	return tst;
}

internal void
_ternarytrie_die(struct ttrie_node *n)
{
	if (!n) {
		return;
	}
	_ternarytrie_die(n->lo);
	_ternarytrie_die(n->hi);
	_ternarytrie_die(n->eq);
        free(n->s);
	/* m_pool_free(pool, n); */
	free(n);
}

void ternarytrie_free(struct ttrie *tst)
{
	_ternarytrie_die(tst->root);
	/* free(tst->pool.buf); */
	free(tst);
}

internal void
_ternarytrie_print(FILE *f, struct ttrie_node *n, int32 j, int32 w,
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
	if (enter == 0) {
		fprintf(f, " ── ");
	} else if (enter == 1) {
		fprintf(f, "└H─ ");
	} else {
		fprintf(f, "└L─ ");
	}
	if (n->s) {
		fprintf(f, "'[%sØ]'", n->s);
	} else {
		char c = n->splitchar;
		if (c) {
			fprintf(f, "'%c'", c);
		} else {
			fprintf(f, "'%s'", "Ø");
		}
		_ternarytrie_print(f, n->eq, j + 7, w + 7, 0);
		_ternarytrie_print(f, n->lo, 0, w + 7, 2);
		_ternarytrie_print(f, n->hi, 0, w + 7, 1);
	}
}

void
ternarytrie_print(FILE *f, struct ttrie *tst)
{
	_ternarytrie_print(f, tst->root, 0, 0, false);
	fputs("\n", f);
}

bool
ternarytrie_search(struct ttrie *tst, const char* s)
{
	const char *c = s;
	struct ttrie_node *n = tst->root;
	while (n) {
		/* check if we reached a leave and the strings are the same */
		if (n->s) {
			return strcmp(n->s, s) == 0;
		}
		/* go to next node */
		if (*c == n->splitchar) {
			++c;
			n = n->eq;
		} else {
			n = n->cs[*c > n->splitchar];
		}
	}
	return false;
}

bool
ternarytrie_add(struct ttrie *tst, const char* s)
{
	int32 i_s = 0, m = strlen(s);
	struct ttrie_node **n = &tst->root;
	while (*n) {
		/* split the current node in two if we reached a leave */
		if ((*n)->s) {
			/* check if we reached a leave and the strings are the
			 * same, if so, return false, otherwise continue with
			 * the split */
			if (strcmp(s, (*n)->s) == 0) {
				return false;
			}
			struct ttrie_node *n_end = *n;
			*n = (struct ttrie_node *)calloc(
			    1, sizeof(struct ttrie_node));
			/* *n = m_pool_alloc(&tst->pool); */
			(*n)->splitchar = n_end->s[i_s];
			(*n)->eq = n_end;
		}
		/* go to next node */
		if (s[i_s] == (*n)->splitchar) {
			n = &(*n)->eq;
			++i_s;
		} else {
			n = &(*n)->cs[s[i_s] > (*n)->splitchar];
		}
	}
	/* create a node for our string */
	*n = (struct ttrie_node *)calloc(1, sizeof(
		struct ttrie_node));
	/* *n = m_pool_alloc(&tst->pool); */
	(*n)->splitchar = s[i_s];
	(*n)->s = (char *)calloc(m + 1, 1);
	strcpy((*n)->s, s);
	++tst->wc;
	return true;
}

internal void
_ternarytrie_remove(struct ttrie_node **n, const char *c, const char *s,
		    bool *is_success)
{
	if (!*n) {
		return;
	}
	/* recurse down to the next node */
	if (!(*n)->s) {
		if (*c == (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->eq, ++c, s, is_success);
		} else {
			_ternarytrie_remove(&(*n)->cs[*c > (*n)->splitchar], c,
					    s, is_success);
		}
	}
	/* if the node has no eq child, do a basic binary tree remove
	 * operation */
	if (!(*n)->eq) {
		/* check if *n is a leave and the string is not same, if so,
		 * return */
		if ((*n)->s && strcmp((*n)->s, s) != 0) {
			return;
		}
		/* basic binary tree remove operation */
		struct ttrie_node *t = *n;
		if ((*n)->lo && (*n)->hi) {
			struct ttrie_node **iter = &(*n)->lo;
			while ((*iter)->hi) {
				iter = &(*iter)->hi;
			}
			*n = *iter;
			*iter = (*n)->lo;
			(*n)->lo = t->lo;
			(*n)->hi = t->hi;
			if ((*n)->s) {
				char *ns = (*n)->s;
				(*n)->s = 0x0;
				(*n)->eq = (struct ttrie_node *)calloc(
				    1, sizeof(struct ttrie_node));
				/* (*n)->eq = m_pool_alloc(pool); */
				(*n)->eq->s = ns;
			}
		} else {
			*n = t->cs[(*n)->lo == 0];
		}
		if (t->s) {
                        free(t->s);
                }
		free(t);
		/* m_pool_free(pool, t); */
		*is_success = true;
	}
}

bool
ternarytrie_remove(struct ttrie *tst, const char *s)
{
	bool is_success = false;
	_ternarytrie_remove(&tst->root, s, s, &is_success);
	if (is_success) {
		--tst->wc;
	}
	return is_success;
}

size_t
ternarytrie_size(struct ttrie *tst)
{
	return tst->wc;
}
