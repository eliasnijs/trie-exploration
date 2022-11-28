/* depends on:
 * stdio.h, stdlib.h, time.h
 * base.h, utils.h
 * ternarytrie.h, arraytrie.h, customtrie.h */

/* macros and typedefs */

/* enumerations, structs, unions */
struct benchmark_sll {
	struct benchmark_sll *next;
	union {
		struct {
			uint64 ternary_ns;
			uint64 array_ns;
			uint64 custom_ns;
		};
		uint64 results[3];
	};
};

/* function definitions */
internal void benchmark_sll_print(FILE *f, const void *ptr);
internal void benchmark_sll_die(struct benchmark_sll *b);
internal struct benchmark_sll * benchmark_run(struct dataset *ds);

/* function implementations */
internal void
benchmark_sll_print(FILE *f, const void *ptr)
{
	struct benchmark_sll *b = (struct benchmark_sll *)ptr;
	fprintf(f, "%.2fs, %.2fs, %.2fs\n", b->ternary_ns / 10e9,
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
benchmark_run(struct dataset *ds)
{
	struct trie tries[3];
	tries[0] = TernaryTrie;
	tries[1] = ArrayTrie;
	tries[2] = CustomTrie;
	struct benchmark_sll *b_start;
	struct benchmark_sll **b_last = &b_start;
	*b_last = (struct benchmark_sll *)calloc(
	    1, sizeof(struct benchmark_sll));
	char **words = ds->words;
	shuffle_ptr((void **)words, ds->wordcount);
	for (int32 i_trie = 0; i_trie < ArrayLength(tries); ++i_trie) {
		if (i_trie == 1) {
			continue;
		}
		struct trie *trie = &tries[i_trie];
		trie_init(trie);
		uint64 start_t = nanos();
		for (uint32 i = 0; i < ds->wordcount; ++i) {
			trie_add(trie, words[i]);
		}
		uint64 end_t = nanos();
		(*b_last)->results[i_trie] = (real64)end_t - (real64)start_t;
		trie_free(trie);
	}
	b_last = &(*b_last)->next;
	return b_start;
}
