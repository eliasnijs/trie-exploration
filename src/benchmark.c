/* depends on:
 * stdio.h, stdlib.h, time.h
 * base.h, utils.h, trie.h */

/* helpers */
typedef uint64 (* benchmark_fptr)(struct trie *t, struct dataset *ds);

/* benchmarks */
internal uint64
benchmark_add(struct trie *trie, struct dataset *ds)
{
	trie_init(trie);
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		/* DebugLogString(ds->words[i]); */
		trie_add(trie, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

/* benchmarks batch */
global_variable benchmark_fptr benchmarks[] = {
	benchmark_add
};


