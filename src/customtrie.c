/* depends on:
 * stdio.h, stdlib.h, stdint.h, string.h, utils.c, base.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "base.c"
#include "utils.c"

/* enumerations, structs, unions */
struct ctrie_node {
	struct ctrie_node *l, *r;
};

struct ctrie {
	size_t wc;
	size_t nc;
	struct ctrie_node *root;
};

/* function definitions */
struct ctrie * customtrie_init();
void customtrie_free(struct ctrie *ct);
bool8 customtrie_add(struct ctrie *at, const char *w);
bool8 customtrie_search(struct ctrie *at, const char *w);
bool8 customtrie_remove(struct ctrie *at, const char *w);
bool8 customtrie_size(struct ctrie *at);
internal void _customtrie_free(struct ctrie_node *n);
internal void _customtrie_remove(struct ctrie_node **n, const char *w, int32 l,
				 int32 i, int32 *rm_nc);

/* function implementations */
struct ctrie *
customtrie_init()
{
	struct ctrie *ct = (struct ctrie *)calloc(1, sizeof(struct ctrie));
	ct->root = (struct ctrie_node *)calloc(1, sizeof(struct ctrie_node));
	return ct;
}

internal void
_customtrie_free(struct ctrie_node *n)
{
	if (!n) {
		return;
	}
	_customtrie_free(n->l);
	_customtrie_free(n->r);
	free(n);
}

void
customtrie_free(struct ctrie *ct)
{
	_customtrie_free(ct->root);
	free(ct);
}

bool8
customtrie_search(struct ctrie *at, const char *w)
{
	int32 l = (strlen(w) + 1) * 8;
	struct ctrie_node *n = at->root;
	for (int32 i = 0; i < l; ++i) {
		if (!n) {
			return false;
		}
		n = (!getbit(w, i)) ? n->l : n->r;
	}
	return true;
}

bool8
customtrie_add(struct ctrie *at, const char *w)
{
	int32 added_nc = 0;
	int32 l = (strlen(w) + 1) * 8;
	struct ctrie_node **n = &at->root;
	for (int32 i = 0; i < l; ++i) {
		if (!*n) {
			*n = (struct ctrie_node *)calloc(1, sizeof(
				struct ctrie_node));
			if (!*n) {
				return false;
			}
			++added_nc;
		}
		if (!getbit(w, i)) {
			n = &(*n)->l;
		} else {
			n = &(*n)->r;
		}
	}
	if (added_nc) {
		at->nc += added_nc;
		at->wc += 1;
		return true;
	}
	return false;
}

internal void
_customtrie_remove(struct ctrie_node **n, const char *w, int32 l, int32 i,
		   int32 *rm_nc)
{
	if (!*n) {
		return;
	}
	if (!getbit(w, i)) {
		_customtrie_remove(&(*n)->l, w, l, i + 1, rm_nc);
	} else {
		_customtrie_remove(&(*n)->r, w, l, i + 1, rm_nc);
	}
	if (!(*n)->l && !(*n)->r) {
		free(*n);
		*n = 0x0;
		*rm_nc += 1;
	}
}

bool8
customtrie_remove(struct ctrie *at, const char *w)
{
	int32 l = 8 * (strlen(w) + 1);
	int32 rm_nc = 0;
	_customtrie_remove(&at->root, w, l, 0, &rm_nc);
	if (rm_nc > 0) {
		at->nc -= rm_nc;
		--at->wc;
		return true;
	}
	return false;
}

bool8
customtrie_size(struct ctrie *at)
{
	return at->wc;
}
