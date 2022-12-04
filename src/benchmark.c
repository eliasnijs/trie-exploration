/* depends on:
 * stdio.h, stdlib.h, time.h
 * base.h, utils.h, trie.h */

/* macros and typedefs */

/* enumerations, structs, unions */
struct benchmark_sll {
	struct benchmark_sll *next;
	union {
		uint64 results[3];
		struct {
			uint64 ternary_ns;
			uint64 array_ns;
			uint64 custom_ns;
		};
	};
};

/* function definitions */
internal void benchmark_sll_print(FILE *f, const void *ptr);
internal void benchmark_sll_die(struct benchmark_sll *b);
internal struct benchmark_sll * benchmark_run(struct dataset *ds,
					      struct trie *tries, int32 tcnt,
					      struct benchmark_sll *b);
/* function implementations */
internal void
benchmark_sll_print(FILE *f, const void *ptr)
{
	struct benchmark_sll *b = (struct benchmark_sll *)ptr;
	fprintf(f, "%8.4f, %8.4f, %8.4f\n", b->ternary_ns / 10e9,
		b->array_ns / 10e9, b->custom_ns / 10e9);
}

internal void
benchmark_sll_die(struct benchmark_sll *b)
{
	struct benchmark_sll *ptr = b, *t;
	while (ptr) {
		t = ptr;
		ptr = ptr->next;
		free(t);
	}
}

internal struct benchmark_sll *
benchmark_add_run(struct dataset *ds, struct trie *tries, int32 tcnt,
		  struct benchmark_sll *b, size_t memlen)
{
	for (int32 i_trie = 0; i_trie < tcnt; ++i_trie) {
		struct trie *trie = &tries[i_trie];
		trie_init_wmem(trie, memlen);
		uint64 start_t = nanos();
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_add(trie, ds->words[i]);
		}
		uint64 end_t = nanos();
		b->results[i_trie] = (real64)end_t - (real64)start_t;
		trie_free(trie);
	}
	return b;
}

internal struct benchmark_sll *
benchmark_afbrm_run(struct dataset *ds, struct trie *tries, int32 tcnt,
		    struct benchmark_sll *b, size_t memlen)
{
	for (int32 i_trie = 0; i_trie < tcnt; ++i_trie) {
		struct trie *trie = &tries[i_trie];
		trie_init_wmem(trie, memlen);
		uint64 start_t = nanos();
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_add(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_remove(trie, ds->words[i]);
		}
		uint64 end_t = nanos();
		b->results[i_trie] = (real64)end_t - (real64)start_t;
		trie_free(trie);
	}
	return b;
}

internal struct benchmark_sll *
benchmark_afbsfbrm_run(struct dataset *ds, struct trie *tries, int32 tcnt,
		       struct benchmark_sll *b, size_t memlen)
{
	for (int32 i_trie = 0; i_trie < tcnt; ++i_trie) {
		struct trie *trie = &tries[i_trie];
		trie_init_wmem(trie, memlen);
		uint64 start_t = nanos();
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_add(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_remove(trie, ds->words[i]);
		}
		uint64 end_t = nanos();
		b->results[i_trie] = (real64)end_t - (real64)start_t;
		trie_free(trie);
	}
	return b;
}

internal struct benchmark_sll *
benchmark_afbsfbrm_splay_run(struct dataset *ds, struct trie *tries, int32 tcnt,
			 struct benchmark_sll *b, size_t memlen)
{
	for (int32 i_trie = 0; i_trie < tcnt; ++i_trie) {
		struct trie *trie = &tries[i_trie];
		trie_init_wmem(trie, memlen);
		uint64 start_t = nanos();
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_add(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount/2; ++i) {
			trie_search(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount/4; ++i) {
			trie_search(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount/8; ++i) {
			trie_search(trie, ds->words[i]);
		}
		for (uint32 i = 0; i < ds->wordcount/16; ++i) {
			trie_search(trie, ds->words[i]);
		}
		uint64 end_t = nanos();
		b->results[i_trie] = (real64)end_t - (real64)start_t;
		trie_free(trie);
	}
	return b;
}
