/* depends on: stdint.h, trie_ternary.h, trie_array.h, trie_custom.h */

/* Wrapper for different trie implementations */

/* macros and typedefs */
typedef void * (* trie_init_fptr)();
typedef void   (* trie_free_fptr)(void *t);
typedef bool8  (* trie_oper_fptr)(void *t, const char *s);
typedef size_t (* trie_size_fptr)(void *t);

/* enumerations, structs, unions */
struct trie {
	void *t;
	trie_init_fptr init;
	trie_free_fptr free;
	union {
		trie_oper_fptr oper[3];
		struct {
			trie_oper_fptr add;
			trie_oper_fptr search;
			trie_oper_fptr remove;
		};
	};
	trie_size_fptr size;
};

/* function definitions */
internal void trie_setfunc(trie_init_fptr init, trie_free_fptr free,
			   trie_oper_fptr add, trie_oper_fptr search,
			   trie_oper_fptr remove, trie_size_fptr size,
			   struct trie *t);
internal void trie_init(struct trie *t);
internal void trie_free(struct trie *t);
internal bool8 trie_add(struct trie *t, const char *s);
internal bool8 trie_search(struct trie *t, const char *s);
internal bool8 trie_remove(struct trie *t, const char *s);

/* global variables */
global_variable struct trie TernaryTrie = {
	0x0,
	(trie_init_fptr)ternarytrie_init,
	(trie_free_fptr)ternarytrie_free,
	{{
		(trie_oper_fptr)ternarytrie_add,
		(trie_oper_fptr)ternarytrie_search,
		(trie_oper_fptr)ternarytrie_remove
	}},
	(trie_size_fptr)ternarytrie_size
};

global_variable struct trie ArrayTrie = {
	0x0,
	(trie_init_fptr)arraytrie_init,
	(trie_free_fptr)arraytrie_free,
	{{
		(trie_oper_fptr)arraytrie_add,
		(trie_oper_fptr)arraytrie_search,
		(trie_oper_fptr)arraytrie_remove
	}},
	(trie_size_fptr)arraytrie_size
};

global_variable struct trie CustomTrie = {
	0,
	(trie_init_fptr)customtrie_init,
	(trie_free_fptr)customtrie_free,
	{{
		(trie_oper_fptr)customtrie_add,
		(trie_oper_fptr)customtrie_search,
		(trie_oper_fptr)customtrie_remove
	}},
	(trie_size_fptr)customtrie_size
};

/* function implementations */
internal void
trie_init(struct trie *t)
{
	t->t = t->init();
}

internal void
trie_free(struct trie *t)
{
	t->free(t->t);
}

internal bool8
trie_add(struct trie *t, const char *s)
{
	return t->add(t->t, s);
}

internal bool8
trie_search(struct trie *t, const char *s)
{
	return t->search(t->t, s);
}

internal bool8
trie_remove(struct trie *t, const char *s)
{
	return t->remove(t->t, s);
}

internal void
trie_setfunc(trie_init_fptr init, trie_free_fptr free, trie_oper_fptr add,
	     trie_oper_fptr search, trie_oper_fptr remove, trie_size_fptr size,
	     struct trie *t)
{
	t->init = init;
	t->free = free;
	t->add = add;
	t->search = search;
	t->remove = remove;
	t->size = size;
}