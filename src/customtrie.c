
/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "base/base.c"

/* Implementation of the Ternary Trie Datastructure. The rationale and specifics
 * of this structure can be found in the following paper:
 * Bentley, J. L., & Sedgewick, R. (1997, January). Fast algorithms for sorting
 * and searching strings. In Proceedings of the eighth annual ACM-SIAM
 * symposium on Discrete algorithms (pp. 360-369).
 * */

/* TODO:
 * - use custom allocator to ensure more coherent memory
 * */

/* enumerations, structs, unions */
struct ctrie_splay_node {
	struct ctrie_splay_node *next;
	struct ctrie_node *node;
};

struct ctrie_node  {
	char *s;
	char splitchar;
	struct ctrie_node *lo, *eq, *hi;
};

struct ctrie {
	struct ctrie_node *root;
	size_t wc;
	struct ctrie_splay_node *splayhead; /* lifo */
	size_t splaycnt;
};

/* function definitions */
struct ctrie * customtrie_init();
void customtrie_free(struct ctrie *ct);
internal struct ctrie_node * customtrie_splay_pop(struct ctrie *ct);
internal void customtrie_splay_push(struct ctrie *ct, struct ctrie_node *n);
internal void customtrie_splay_clear(struct ctrie *ct);
internal void _customtrie_print(FILE *f, struct ctrie_node *n, int32 j,
				 int32 w, bool32 enter);
void customtrie_print(FILE *f, struct ctrie *ct);
bool8 customtrie_add(struct ctrie *ct, const char* s);
bool8 customtrie_search(struct ctrie *ct, const char* s);
bool8 customtrie_remove(struct ctrie *ct, const char *s);
size_t customtrie_size(struct ctrie *ct);
internal void _customtrie_remove(struct ctrie_node **n, const char *c,
				  const char *s, bool8 *is_success);
internal void _customtrie_die(struct ctrie_node *n);


/* function implementations */
struct ctrie *
customtrie_init()
{
	struct ctrie *ct = (struct ctrie *)calloc(1, sizeof(struct ctrie));
	return ct;
}

internal void
_customtrie_die(struct ctrie_node *n)
{
	if (!n) {
		return;
	}
	_customtrie_die(n->lo);
	_customtrie_die(n->hi);
	_customtrie_die(n->eq);
	if (n->s) {
		free(n->s);
	}
	free(n);
}

void customtrie_free(struct ctrie *ct)
{
	customtrie_splay_clear(ct);
	_customtrie_die(ct->root);
	free(ct);
}

internal struct ctrie_node *
customtrie_splay_pop(struct ctrie *ct)
{
	struct ctrie_splay_node *head = ct->splayhead;
	ct->splayhead = head->next;
	struct ctrie_node *n = head->node;
	free(head);
	--ct->splaycnt;
	return n;
}

internal void
customtrie_splay_push(struct ctrie *ct, struct ctrie_node *n)
{
	if (!n) {
		return;
	}
	struct ctrie_splay_node *head = (struct ctrie_splay_node *)calloc(
	    1, sizeof(struct ctrie_splay_node));
	head->next = ct->splayhead;
	head->node = n;
	ct->splayhead = head;
	++ct->splaycnt;
}

internal void
customtrie_splay_clear(struct ctrie *ct)
{
	struct ctrie_splay_node *head = ct->splayhead;
	while (head) {
		struct ctrie_splay_node *t = head;
		head = t->next;
		free(t);
	}
	ct->splayhead = 0x0;
	ct->splaycnt = 0;
}

internal void
customtrie_splay(struct ctrie *ct)
{
	while (ct->splaycnt >= 3) {
		struct ctrie_node *n = customtrie_splay_pop(ct);
		struct ctrie_node *m = customtrie_splay_pop(ct);
		struct ctrie_node *p = customtrie_splay_pop(ct);
		struct ctrie_node *t = m;
		if (p->splitchar < m->splitchar &&
		    p->splitchar < n->splitchar) {
			if (m->splitchar < n->splitchar) {
				p->hi = m->lo;
				m->lo = p;
				customtrie_splay_push(ct, m);
				t = m;
			} else {
				p->hi = n->lo;
				n->lo = p;
				m->lo = n->hi;
				n->hi = m;
				customtrie_splay_push(ct, n);
				t = n;
			}
		} else {
			if (m->splitchar > n->splitchar) {
				p->lo = m->hi;
				m->hi = p;
				customtrie_splay_push(ct, m);
				t = m;
			} else {
				p->lo = n->hi;
				n->hi = p;
				m->hi = n->lo;
				n->lo = m;
				customtrie_splay_push(ct, n);
				t = n;
			}
		}
		if (t->lo->eq && !t->lo->hi && !t->lo->lo &&t->lo->eq->s) {
			struct ctrie_node *temp = t->lo;
			t->lo = temp->eq;
			t->lo->splitchar = temp->splitchar;
			free(temp);
		}
		if (t->hi->eq && !t->hi->hi && !t->hi->lo &&t->hi->eq->s) {
			struct ctrie_node *temp = t->hi;
			t->hi = temp->eq;
			t->hi->splitchar = temp->splitchar;
			free(temp);
		}
		if (t->s) {
			char *ns = n->s;
			n->s = 0x0;
			n->eq = (struct ctrie_node *)calloc(
			    1, sizeof(struct ctrie_node));
			n->eq->s = ns;
		}
		if (ct->splaycnt > 1) {
			struct ctrie_node *child = customtrie_splay_pop(ct);
			struct ctrie_node *parent = customtrie_splay_pop(ct);
			if (child->splitchar < parent->splitchar) {
				parent->lo = child;
			} else {
				parent->hi = child;
			}
			customtrie_splay_push(ct, parent);
			customtrie_splay_push(ct, child);
		} else {
			ct->root = customtrie_splay_pop(ct);
		}
	}
	customtrie_splay_clear(ct);
}

internal void
_customtrie_print(FILE *f, struct ctrie_node *n, int32 j, int32 w, bool32 enter)
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
		_customtrie_print(f, n->eq, j + 7, w + 7, 0);
		_customtrie_print(f, n->lo, 0, w + 7, 2);
		_customtrie_print(f, n->hi, 0, w + 7, 1);
	}
}

void
customtrie_print(FILE *f, struct ctrie *ct)
{
	_customtrie_print(f, ct->root, 0, 0, false);
	fputs("\n", f);
}

bool8
customtrie_search(struct ctrie *ct, const char* s)
{
	const char *c = s;
	struct ctrie_node *n = ct->root;
	if (n) {
		customtrie_splay_push(ct, n);
	}
	while (n) {
		if (n->s) {
			bool32 result = strcmp(n->s, s) == 0;
			customtrie_splay(ct);
			return result;
		}
		if (*c < n->splitchar) {
			n = n->lo;
			customtrie_splay_push(ct, n);
		} else if (*c > n->splitchar) {
			n = n->hi;
			customtrie_splay_push(ct, n);
		} else {
			++c;
			n = n->eq;
			customtrie_splay_clear(ct);
		}
	}
	customtrie_splay(ct);
	return 0;
}

bool8
customtrie_add(struct ctrie *ct, const char* s)
{
	int32 s_i = 0, m = strlen(s);
	struct ctrie_node **n = &ct->root;
	while (s_i <= m) {
		if (!*n) {
			*n = (struct ctrie_node *)calloc(1, sizeof(
				struct ctrie_node));
			if (!*n) {
				return false;
			}
			(*n)->splitchar = s[s_i];
			(*n)->s = (char *)calloc(m + 1, 1);
			strcpy((*n)->s, s);
			++ct->wc;
			return true;
		}
		if ((*n)->s) {
			if (strcmp(s, (*n)->s) == 0) {
				return false;
			}
			struct ctrie_node *n_end = *n;
			*n = (struct ctrie_node *)calloc(
			    1, sizeof(struct ctrie_node));
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
_customtrie_remove(struct ctrie_node **n, const char *c, const char *s,
		    bool8 *is_success)
{
	if (!*n) {
		return;
	}
	if (!(*n)->s) {
		if (*c < (*n)->splitchar) {
			_customtrie_remove(&(*n)->lo, c, s, is_success);
		} else if (*c > (*n)->splitchar) {
			_customtrie_remove(&(*n)->hi, c, s, is_success);
		} else {
			_customtrie_remove(&(*n)->eq, ++c, s, is_success);
		}
	}
	if (!(*n)->eq) {
		if ((*n)->s && strcmp((*n)->s, s) != 0) {
			return;
		}
		struct ctrie_node *t = *n;
		if ((*n)->lo && (*n)->hi) {
			struct ctrie_node **iter = &(*n)->lo;
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
				(*n)->splitchar = (*n)->splitchar;
				(*n)->eq = (struct ctrie_node *)calloc(
				    1, sizeof(struct ctrie_node));
				(*n)->eq->s = ns;
			}
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
customtrie_remove(struct ctrie *ct, const char *s)
{
	bool8 is_success = false;
	_customtrie_remove(&ct->root, s, s, &is_success);
	if (is_success) {
		--ct->wc;
	}
	return is_success;
}

size_t
customtrie_size(struct ctrie *ct)
{
	return ct->wc;
}
