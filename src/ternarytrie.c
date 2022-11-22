#include "ternarytrie.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct ttrie_node  {
        char splitchar;
	struct ttrie_node  *lo, *eq, *hi;
};

struct ttrie {
	struct ttrie_node *root;
	size_t wc;
};

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
	free(n);
}

void ternarytrie_free(struct ttrie *tst)
{
  _ternarytrie_die(tst->root);
  free(tst);
}

bool8
ternarytrie_search(struct ttrie *tst, const char* s)
{
	struct ttrie_node *n = tst->root;
	while (n) {
		if (!*s && !n->splitchar) {
			return 1;
		}
		if (*s < n->splitchar) {
			n = n->lo;
		} else if (*s > n->splitchar) {
			n = n->hi;
		} else {
			++s;
			n = n->eq;
		}
	}
	return 0;
}

bool8
ternarytrie_add(struct ttrie *tst, const char* s)
{
	bool8 completed = false, already_present = true;
	struct ttrie_node **n = &tst->root;
	while (!completed) {
		if (!*n) {
			*n = (struct ttrie_node *)calloc(1, sizeof(
				struct ttrie_node));
			if (!*n) {
				return false;
			}
			(*n)->splitchar = *s;
			already_present = false;
		}
		if (!*s) {
			completed = true;
		}
		if (*s < (*n)->splitchar) {
			n = &(*n)->lo;
		} else if (*s > (*n)->splitchar) {
			n = &(*n)->hi;
		} else {
			++s;
			n = &(*n)->eq;
		}
	}
	if (!already_present) {
		++tst->wc;
		return true;
	}
	return false;
}

internal void
_ternarytrie_remove(struct ttrie_node **n, const char *s, bool8 *is_success)
{
	if (!(*n)) {
		return;
	}
	if (*s != 0) {
		if (*s < (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->lo, s, is_success);
		} else if (*s > (*n)->splitchar) {
			_ternarytrie_remove(&(*n)->hi, s, is_success);
		} else {
			_ternarytrie_remove(&(*n)->eq, ++s, is_success);
		}
	}
	if (!(*n)->eq) {
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
		free(t);
		*is_success = true;
	}
}

bool8
ternarytrie_remove(struct ttrie *tst, const char *s)
{
	bool8 is_success = false;
	_ternarytrie_remove(&tst->root, s, &is_success);
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
