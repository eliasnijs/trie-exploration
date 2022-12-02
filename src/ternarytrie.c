/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "base.c"

/* Implementation of the Ternary Trie Datastructure. The rationale and specifics
 * of this structure can be found in the following paper:
 *
 * Bentley, J. L., & Sedgewick, R. (1997, January). Fast algorithms for sorting
 * and searching strings. In Proceedings of the eighth annual ACM-SIAM
 * symposium on Discrete algorithms (pp. 360-369).
 *
 * */

/* enumerations, structs, unions */
struct ttrie_node  {
	union {
		char *s;
		bool16 is_end;
	};
	char splitchar;
	struct ttrie_node  *lo, *eq, *hi;
};

struct ttrie {
	struct ttrie_node *root;
	size_t wc;
};

/* function definitions */
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
				  const char *s, bool8 *is_success);
internal void _ternarytrie_die(struct ttrie_node *n);


/* function implementations */
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
	if (n->s) {
		free(n->s);
	}
	free(n);
}

void ternarytrie_free(struct ttrie *tst)
{
	_ternarytrie_die(tst->root);
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
	if (n->is_end) {
		fprintf(f, " -- '%sØ'", n->s);
	} else {
		char c = n->splitchar;
		if (c) {
			fprintf(f, " -- '%c'", c);
		} else {
			fprintf(f, " -- '%s'", "Ø");
		}
		_ternarytrie_print(f, n->eq, j + 7, w + 7, false);
		_ternarytrie_print(f, n->hi, 0, w + 7, true);
		_ternarytrie_print(f, n->lo, 0, w + 7, true);
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
		if (n->is_end) {
			return strcmp(n->s, s) == 0;
		}
		if (*c < n->splitchar) {
			n = n->lo;
		} else if (*c > n->splitchar) {
			n = n->hi;
		} else {
			++c;
			n = n->eq;
		}
	}
	return 0;
}

bool8
ternarytrie_add(struct ttrie *tst, const char* s)
{
	bool8 completed = false, already_present = true;
	int32 s_i = 0, m = strlen(s);
	struct ttrie_node **n = &tst->root;
	while (s_i <= m) {
		if (!*n) {
			*n = (struct ttrie_node *)calloc(1, sizeof(
				struct ttrie_node));
			if (!*n) {
				return false;
			}
			(*n)->s = (char *)calloc(m + 1, 1);
			strcpy((*n)->s, s);
			++tst->wc;
			return true;
		}
		if ((*n)->is_end) {
			struct ttrie_node *n_end = *n;
			*n = (struct ttrie_node *)calloc(
			    1, sizeof(struct ttrie_node));
			(*n)->splitchar = n_end->s[s_i];
			(*n)->eq = n_end;
		}
		if (s[s_i] < (*n)->splitchar) {
			n = &(*n)->lo;
		} else if (s[s_i] > (*n)->splitchar) {
			n = &(*n)->hi;
		} else {
			++s_i;
			n = &(*n)->eq;
		}
	}
	return false;
}

internal void
_ternarytrie_remove(struct ttrie_node **n, const char *c, const char *s,
		    bool8 *is_success)
{
	if (!(*n)) {
		return;
	}
	if (!(*n)->is_end) {
		if (*c < (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->lo, c, s, is_success);
		} else if (*c > (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->hi, c, s, is_success);
		} else {
			_ternarytrie_remove(&(*n)->eq, ++c, s, is_success);
		}
	}
	if (!(*n)->eq) {
		if ((*n)->is_end && strcmp((*n)->s, s) != 0) {
			return;
		}
		struct ttrie_node *t = *n;
		if ((*n)->lo && (*n)->hi) {
			*n = t->lo;
			struct ttrie_node *l = (*n)->hi;
			(*n)->hi = t->hi;
			struct ttrie_node *iter = (*n)->hi;
			while (iter->lo != 0) {
				iter = iter->lo;
			}
			iter->lo = l;
		} else {
			*n = ((*n)->lo) ? t->lo : t->hi;
		}
		if (t->s) {
			free(t->s);
		}
		free(t);
		*is_success = true;
	}
}

bool8
ternarytrie_remove(struct ttrie *tst, const char *s)
{
	bool8 is_success = false;
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
