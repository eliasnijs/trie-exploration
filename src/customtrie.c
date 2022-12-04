
/* depends on:
 * stdio.h, stdlib.h, base.c, stdint.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "base/base.c"
#include "base/utils.c"
#include "base/m_pool.c"

/* Implementation of the Ternary Trie Datastructure. The rationale and specifics
 * of this structure can be found in the following paper:
 * Bentley, J. L., & Sedgewick, R. (1997, January). Fast algorithms for sorting
 * and searching strings. In Proceedings of the eighth annual ACM-SIAM
 * symposium on Discrete algorithms (pp. 360-369).
 * */

/* TODO:
 * - use custom allocator to ensure more coherent memory
 * */

/* macros */
#define TRIE_CUSTOM_DEFAULT_POOL_SIZE Kilobytes(1)

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
	struct m_pool pool;
	struct ctrie_node *root;
	size_t wc;
	struct ctrie_splay_node *splayhead; /* lifo */
	size_t splaycnt;
	struct ctrie_node **splayroot;
};

/* function definitions */
struct ctrie * customtrie_init_wmem(size_t backbufferlen);
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
internal void _customtrie_remove(struct ctrie *ct, struct ctrie_node **n,
				 const char *c, const char *s,
				 bool8 *is_success);
internal void _customtrie_die(struct ctrie_node *n, struct m_pool *pool);


/* function implementations */
struct ctrie *
customtrie_init_wmem(size_t backbufferlen)
{
	struct ctrie *ct = (struct ctrie *)calloc(1, sizeof(struct ctrie));
	uint8 *bb = (uint8 *)malloc(backbufferlen);
	m_pool_init(&ct->pool, bb, backbufferlen,
		    sizeof(struct ctrie_node), MEM_DEFAULT_ALIGNMENT);
	return ct;
}
struct ctrie *
customtrie_init()
{
	return customtrie_init_wmem(TRIE_TERNARY_DEFAULT_POOL_SIZE);
}

internal void
_customtrie_die(struct ctrie_node *n, struct m_pool *pool)
{
	if (!n) {
		return;
	}
	_customtrie_die(n->lo, pool);
	_customtrie_die(n->hi, pool);
	_customtrie_die(n->eq, pool);
	if (n->s) {
		free(n->s);
	}
	m_pool_free(pool, n);
	/* free(n); */
}

void customtrie_free(struct ctrie *ct)
{
	customtrie_splay_clear(ct);
	_customtrie_die(ct->root, &ct->pool);
	free(ct->pool.buf);
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
			/* free(temp); */
			 m_pool_free(&ct->pool, temp);
		}
		if (t->hi->eq && !t->hi->hi && !t->hi->lo &&t->hi->eq->s
		    && t->hi != n) {
			struct ctrie_node *temp = t->hi;
			t->hi = temp->eq;
			t->hi->splitchar = temp->splitchar;
			/* free(temp); */
			 m_pool_free(&ct->pool, temp);
		}
		if (t->s) {
			char *ns = n->s;
			n->s = 0x0;
			/* n->eq = (struct ctrie_node *)calloc( */
			/*     1, sizeof(struct ctrie_node)); */
			n->eq = m_pool_alloc(&ct->pool);
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

bool8
customtrie_search(struct ctrie *ct, const char* s)
{
	const char *c = s;
	struct ctrie_node *n = ct->root;
	ct->splayroot = &ct->root;
	while (n) {
		customtrie_splay_push(ct, n);
		if (n->s) {
			bool32 result = strcmp(n->s, s) == 0;
			customtrie_splay(ct);
			return result;
		}
		if (*c < n->splitchar) {
			n = n->lo;
		} else if (*c > n->splitchar) {
			n = n->hi;
		} else {
			customtrie_splay(ct);
			ct->splayroot = &n->eq;
			++c;
			n = n->eq;
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
	ct->splayroot = &ct->root;

	while (s_i <= m) {
		if (!*n) {
			/* *n = (struct ctrie_node *)calloc(1, sizeof( */
			/* 	struct ctrie_node)); */
			*n = m_pool_alloc(&ct->pool);
			if (!*n) {
				return false;
			}
			(*n)->splitchar = s[s_i];
			(*n)->s = (char *)calloc(m + 1, 1);
			strcpy((*n)->s, s);
			++ct->wc;
			customtrie_splay_push(ct, *n);
			customtrie_splay(ct);
			return true;
		}
		if ((*n)->s) {
			if (strcmp(s, (*n)->s) == 0) {
				customtrie_splay_push(ct, *n);
				customtrie_splay(ct);
				return false;
			}
			struct ctrie_node *n_end = *n;
			/* *n = (struct ctrie_node *)calloc( */
			/*     1, sizeof(struct ctrie_node)); */
			*n = m_pool_alloc(&ct->pool);
			(*n)->splitchar = n_end->s[s_i];
			(*n)->eq = n_end;
		}
		customtrie_splay_push(ct, *n);
		if (s[s_i] < (*n)->splitchar) {
			n = &(*n)->lo;
		} else if (s[s_i] > (*n)->splitchar) {
			n = &(*n)->hi;
		} else {
			struct ctrie_node *t = *n;
			customtrie_splay(ct);
			n = ct->splayroot = &t->eq;
			++s_i;
		}
	}
	customtrie_splay_push(ct, *n);
	customtrie_splay(ct);
	return false;
}

internal void
_customtrie_remove(struct ctrie *ct, struct ctrie_node **n, const char *c,
		   const char *s, bool8 *is_success)
{
	if (!*n) {
		return;
	}
	if (!(*n)->s) {
		if (*c < (*n)->splitchar) {
			_customtrie_remove(ct, &(*n)->lo, c, s, is_success);
		} else if (*c > (*n)->splitchar) {
			_customtrie_remove(ct, &(*n)->hi, c, s, is_success);
		} else {
			_customtrie_remove(ct, &(*n)->eq, ++c, s, is_success);
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
				/* (*n)->eq = (struct ctrie_node *)calloc( */
				/*     1, sizeof(struct ctrie_node)); */
				(*n)->eq = m_pool_alloc(&ct->pool);
				(*n)->eq->s = ns;
			}
		} else {
			*n = ((*n)->lo) ? t->lo : t->hi;
		}
		if (t->s) {
			free(t->s);
		}
		/* free(t); */
		m_pool_free(&ct->pool, t);
		*is_success = true;
	}
}

bool8
customtrie_remove(struct ctrie *ct, const char *s)
{
	bool8 is_success = false;
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
