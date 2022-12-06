/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "base/base.c"
#include "base/utils.c"
#include "base/m_pool.c"

/* Implementation of the Ternary Trie Datastructure. The rationale and specifics
 * of this structure can be found in the following paper:
 *
 * Bentley, J. L., & Sedgewick, R. (1997, January). Fast algorithms for sorting
 * and searching strings. In Proceedings of the eighth annual ACM-SIAM
 * symposium on Discrete algorithms (pp. 360-369).
 *
 * */

/* TODO:
* - add arena allocator for strings.
 * */

/* macros */
#define TRIE_TERNARY_DEFAULT_POOL_SIZE Kilobytes(1)

/* enumerations, structs, unions */
struct ttrie_node  {
	char *s;
	char splitchar;
	union {
		struct ttrie_node *cs[3];
		struct {
			struct ttrie_node  *lo, *hi, *eq;
		};
	};
};

struct ttrie {
	struct ttrie_node *root;
	struct m_pool pool;
	size_t wc;
};

/* function definitions */
struct ttrie * ternarytrie_init_wmem(size_t backbufferlen);
struct ttrie * ternarytrie_init();
void ternarytrie_free(struct ttrie *tst);
internal void _ternarytrie_print(FILE *f, struct ttrie_node *n, int32 j,
				 int32 w, bool32 enter);
void ternarytrie_print(FILE *f, struct ttrie *tst);
bool8 ternarytrie_add(struct ttrie *tst, const char* s);
bool8 ternarytrie_search(struct ttrie *tst, const char* s);
bool8 ternarytrie_remove(struct ttrie *tst, const char *s);
size_t ternarytrie_size(struct ttrie *tst);
internal void _ternarytrie_remove(struct ttrie_node **n, const char *c,
				  const char *s, bool8 *is_success,
				  struct m_pool *pool);
internal void _ternarytrie_die(struct ttrie_node *n, struct m_pool *pool);


/* function implementations */
struct ttrie *
ternarytrie_init_wmem(size_t backbufferlen)
{
	struct ttrie *tst = (struct ttrie *)calloc(1, sizeof(struct ttrie));
	/* uint8 *bb = (uint8 *)malloc(backbufferlen); */
	/* m_pool_init(&tst->pool, bb, backbufferlen, */
	/* 	    sizeof(struct ttrie_node), MEM_DEFAULT_ALIGNMENT); */
	return tst;
}

struct ttrie *
ternarytrie_init()
{
	return ternarytrie_init_wmem(TRIE_TERNARY_DEFAULT_POOL_SIZE);
}

internal void
_ternarytrie_die(struct ttrie_node *n, struct m_pool *pool)
{
	if (!n) {
		return;
	}
	_ternarytrie_die(n->lo, pool);
	_ternarytrie_die(n->hi, pool);
	_ternarytrie_die(n->eq, pool);
        if (n->s) {
                free(n->s);
        }
	/* m_pool_free(pool, n); */
	free(n);
}

void ternarytrie_free(struct ttrie *tst)
{
	_ternarytrie_die(tst->root, &tst->pool);
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

bool8
ternarytrie_search(struct ttrie *tst, const char* s)
{
	const char *c = s;
	struct ttrie_node *n = tst->root;
	while (n) {
		if (n->s) {
			return strcmp(n->s, s) == 0;
		}
		if (*c == n->splitchar) {
			++c;
			n = n->eq;
		} else {
			n = n->cs[*c > n->splitchar];
		}
	}
	return 0;
}

bool8
ternarytrie_add(struct ttrie *tst, const char* s)
{
	int32 s_i = 0, m = strlen(s);
	struct ttrie_node **n = &tst->root;
	while (s_i <= m) {
		if (!*n) {
			*n = (struct ttrie_node *)calloc(1, sizeof(
				struct ttrie_node));
			/* *n = m_pool_alloc(&tst->pool); */
			if (!*n) {
				return false;
			}
			(*n)->splitchar = s[s_i];
			(*n)->s = (char *)calloc(m + 1, 1);
                        strcpy((*n)->s, s);
			++tst->wc;
			return true;
		}
		if ((*n)->s) {
			if (strcmp(s, (*n)->s) == 0) {
				return false;
			}
			struct ttrie_node *n_end = *n;
			*n = (struct ttrie_node *)calloc(
			    1, sizeof(struct ttrie_node));
			/* *n = m_pool_alloc(&tst->pool); */
			(*n)->splitchar = n_end->s[s_i];
			(*n)->eq = n_end;
		}
		if (s[s_i] == (*n)->splitchar) {
			++s_i;
			n = &(*n)->eq;
		} else {
			n = &(*n)->cs[s[s_i] > (*n)->splitchar];
		}
	}
	return false;
}

internal void
_ternarytrie_remove(struct ttrie_node **n, const char *c, const char *s,
		    bool8 *is_success, struct m_pool *pool)
{
	if (!*n) {
		return;
	}
	if (!(*n)->s) {
		if (*c == (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->eq, ++c, s, is_success,
					    pool);
		} else {
			_ternarytrie_remove(&(*n)->cs[*c > (*n)->splitchar], c,
					    s, is_success, pool);
		}
	}
	if (!(*n)->eq) {
		if ((*n)->s && strcmp((*n)->s, s) != 0) {
			return;
		}
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

bool8
ternarytrie_remove(struct ttrie *tst, const char *s)
{
	bool8 is_success = false;
	_ternarytrie_remove(&tst->root, s, s, &is_success, &tst->pool);
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
