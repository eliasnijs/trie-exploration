
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

/* Implementation of a combination of a Ternary Trie Datastructure and Binary
 * Semi Spay tree. More specifically this means that when searching a node,
 * the path followd in every subtree will be splayed. The rationale behind this
 * structure is that more common prefixes will be moved closer to the root thus
 * giving us a better optimzed trie for the current dataset. We will call this
 * a Ternary Semi Splay Trie in our program.
 *
 * This implementation of the Ternary Semi Splay Trie is for ASCII strings.
 * */

/* IMPORTANT(Elias): A pooling allocator was defined. However at the moment all
 * statements related to this allocator are commented out. This is because we do
 * not have any information about the data upfront in our assignment.
 * Using this allocator can deliver a significant speedup since memory is less
 * fragmented.*/

/* enumerations, structs, unions */
struct ctrie_splay_node {
	struct ctrie_splay_node *next;
	struct ctrie_node *node;
};

struct ctrie_node  {
	char *s;		/* if the node is a leafe, complete string,
				 * otherwise a zero-pointer */
	char splitchar;
	union {			/* a union was used so it's possible to index
				 * lo and hi from a compare statement */
		struct ctrie_node *cs[3];
		struct {
			struct ctrie_node  *lo, *hi, *eq;
		};
	};
};

struct ctrie {
	struct ctrie_node *root;
	size_t wc;
	size_t splaycnt;
	struct ctrie_splay_node *splayhead;	/* lifo-head */
	struct ctrie_node **splayroot;		/* root of the current subtree
						 * while doing an operation */
	/* struct m_pool pool; */
};

/* function definitions */
struct ctrie * customtrie_init_wmem(size_t backbufferlen);
struct ctrie * customtrie_init();
void customtrie_free(struct ctrie *ct);
void customtrie_print(FILE *f, struct ctrie *ct);
bool customtrie_add(struct ctrie *ct, const char* s);
bool customtrie_search(struct ctrie *ct, const char* s);
bool customtrie_remove(struct ctrie *ct, const char *s);
size_t customtrie_size(struct ctrie *ct);
internal void _customtrie_remove(struct ctrie *ct, struct ctrie_node **n,
				 const char *c, const char *s,
				 bool *is_success);
internal void _customtrie_die(struct ctrie_node *n);
internal void customtrie_splay_push(struct ctrie *ct, struct ctrie_node *n);
internal struct ctrie_node * customtrie_splay_pop(struct ctrie *ct);
internal void customtrie_splay_clear(struct ctrie *ct);
internal void _customtrie_print(FILE *f, struct ctrie_node *n, int32 j,
				 int32 w, bool32 enter);


/* function implementations */

/* struct ctrie * */
/* customtrie_init_wmem(size_t backbufferlen) */
/* { */
/* 	struct ctrie *ct = (struct ctrie *)calloc(1, sizeof(struct ctrie)); */
/* 	uint8 *bb = (uint8 *)malloc(backbufferlen); */
/* 	m_pool_init(&ct->pool, bb, backbufferlen, */
/* 		    sizeof(struct ctrie_node), MEM_DEFAULT_ALIGNMENT); */
/* 	return ct; */
/* } */

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
	free(n->s);
	/* m_pool_free(pool, n); */
	free(n);
}

void customtrie_free(struct ctrie *ct)
{
	customtrie_splay_clear(ct);
	_customtrie_die(ct->root);
	/* free(ct->pool.buf); */
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
	ct->splaycnt = 0;
	ct->splayhead = 0x0;
	ct->splayroot = 0x0;
}

internal void
customtrie_splay_print(struct ctrie *ct, FILE *f)
{
	int32 i = 0;
	struct ctrie_splay_node *head = ct->splayhead;
	while (head) {
		fprintf(f, "'%c' <- ", head->node->splitchar);
		head = head->next;
		++i;
	}
	printf("\n");
}

internal void
customtrie_splay(struct ctrie *ct)
{
	while (ct->splaycnt >= 3) {
		struct ctrie_node *n = customtrie_splay_pop(ct);
		struct ctrie_node *m = customtrie_splay_pop(ct);
		struct ctrie_node *p = customtrie_splay_pop(ct);
		Assert(n && m && p);
		struct ctrie_node *t = m;
		if (p->splitchar < m->splitchar &&
		    p->splitchar < n->splitchar) {
			if (m->splitchar < n->splitchar) {
				p->hi = m->lo;
				m->lo = p;
				t = m;
			} else {
				p->hi = n->lo;
				n->lo = p;
				m->lo = n->hi;
				n->hi = m;
				t = n;
			}
		} else {
			if (m->splitchar > n->splitchar) {
				p->lo = m->hi;
				m->hi = p;
				t = m;
			} else {
				p->lo = n->hi;
				n->hi = p;
				m->hi = n->lo;
				n->lo = m;
				t = n;
			}
		}
		Assert(t && t->lo && t->hi);
		if (t->lo->eq && !t->lo->hi && !t->lo->lo &&t->lo->eq->s
		    && t->lo != n) {
			struct ctrie_node *temp = t->lo;
			t->lo = temp->eq;
			t->lo->splitchar = temp->splitchar;
			free(temp);
			 /* m_pool_free(&ct->pool, temp); */
		}
		if (t->hi->eq && !t->hi->hi && !t->hi->lo &&t->hi->eq->s
		    && t->hi != n) {
			struct ctrie_node *temp = t->hi;
			t->hi = temp->eq;
			t->hi->splitchar = temp->splitchar;
			free(temp);
			 /* m_pool_free(&ct->pool, temp); */
		}
		if (t->s) {
			char *ns = n->s;
			n->s = 0x0;
			n->eq = (struct ctrie_node *)calloc(
			    1, sizeof(struct ctrie_node));
			/* n->eq = m_pool_alloc(&ct->pool); */
			n->eq->s = ns;
		}
		if (ct->splaycnt == 0) {
			*ct->splayroot = t;
		} else {
			struct ctrie_node *parent = customtrie_splay_pop(ct);
			if (t->splitchar < parent->splitchar) {
				parent->lo = t;
			} else {
				parent->hi = t;
			}
			customtrie_splay_push(ct, parent);
			customtrie_splay_push(ct, t);
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

bool
customtrie_search(struct ctrie *ct, const char* s)
{
	const char *c = s;
	struct ctrie_node *n = ct->root;
	ct->splayroot = &ct->root;
	while (n) {
		customtrie_splay_push(ct, n);
		/* check if we reached a leave and the strings are the same */
		if (n->s) {
			bool32 result = strcmp(n->s, s) == 0;
			customtrie_splay(ct);
			return result;
		}
		/* go to next node */
		if (*c == n->splitchar) {
			customtrie_splay(ct);
			ct->splayroot = &n->eq;
			++c;
			n = n->eq;
		} else {
			n = n->cs[*c > n->splitchar];
		}
	}
	customtrie_splay(ct);
	return 0;
}

bool
customtrie_add(struct ctrie *ct, const char* s)
{
	int32 i_s = 0, m = strlen(s);
	struct ctrie_node **n = &ct->root;
	ct->splayroot = &ct->root;

	while (*n) {
		/* split the current node in two if we reached a leave */
		if ((*n)->s) {
			/* check if we reached a leave and the strings are the
			 * same, if so, return false, otherwise continue with
			 * the split */
			if (strcmp(s, (*n)->s) == 0) {
				customtrie_splay_push(ct, *n);
				customtrie_splay(ct);
				return false;
			}
			struct ctrie_node *n_end = *n;
			*n = (struct ctrie_node *)calloc(
			    1, sizeof(struct ctrie_node));
			/* *n = m_pool_alloc(&ct->pool); */
			(*n)->splitchar = n_end->s[i_s];
			(*n)->eq = n_end;
		}
		customtrie_splay_push(ct, *n);
		/* go to next node */
		if (s[i_s] == (*n)->splitchar) {
			struct ctrie_node *t = *n;
			customtrie_splay(ct);
			n = ct->splayroot = &t->eq;
			++i_s;
		} else {
			n = &(*n)->cs[s[i_s] > (*n)->splitchar];
		}
	}
	/* create a node for our string */
	*n = (struct ctrie_node *)calloc(1, sizeof(
		struct ctrie_node));
	/* *n = m_pool_alloc(&ct->pool); */
	(*n)->splitchar = s[i_s];
	(*n)->s = (char *)calloc(m + 1, 1);
	strcpy((*n)->s, s);
	++ct->wc;
	customtrie_splay_push(ct, *n);
	customtrie_splay(ct);
	return true;
}

internal void
_customtrie_remove(struct ctrie *ct, struct ctrie_node **n, const char *c,
		   const char *s, bool *is_success)
{
	if (!*n) {
		return;
	}
	/* recurse down to the next node */
	if (!(*n)->s) {
		if (*c == (*n)->splitchar) {
			_customtrie_remove(ct, &(*n)->eq, ++c, s, is_success);
		} else {
			_customtrie_remove(ct, &(*n)->cs[*c > (*n)->splitchar],
					    c, s, is_success);
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
				/* (*n)->eq = m_pool_alloc(&ct->pool); */
				(*n)->eq->s = ns;
			}
		} else {
			*n = ((*n)->lo) ? t->lo : t->hi;
		}
		if (t->s) {
			free(t->s);
		}
		free(t);
		/* m_pool_free(&ct->pool, t); */
		*is_success = true;
	}
}

bool
customtrie_remove(struct ctrie *ct, const char *s)
{
	bool is_success = false;
	_customtrie_remove(ct, &ct->root, s, s, &is_success);
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
