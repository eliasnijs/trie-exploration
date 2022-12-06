#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#include "../utils/base.h"
#include "../utils/ansii_esc_codes.h"
#include "../utils/utils.c"
#include "../utils/dataset.c"

#include "../include/ternarytrie_extended.h"
#include "../include/arraytrie_extended.h"
#include "../include/customtrie_extended.h"

#include "../utils/trie.c"

/* helpers */
typedef uint64 (* benchmark_fptr)(struct trie *t, struct dataset *ds);

internal void
print_error_msg(char *systemname, char *msg)
{
	fprintf(stderr, "%s: %s\n", systemname, msg);
}

/* benchmarks */
internal uint64
benchmark_add(struct trie *trie, struct dataset *ds)
{
	trie_init(trie);
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_add(trie, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

internal uint64
benchmark_search(struct trie *trie, struct dataset *ds)
{
	trie_init(trie);
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_add(trie, ds->words[i]);
	}
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_search(trie, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

internal uint64
benchmark_remove(struct trie *trie, struct dataset *ds)
{
	trie_init(trie);
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_add(trie, ds->words[i]);
	}
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_remove(trie, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

internal uint64
benchmark_mix(struct trie *trie, struct dataset *ds)
{
	srand(nanos());
	trie_init(trie);
	for (uint32 i = 0; i < ds->wordcount; i += 2) {
		trie_add(trie, ds->words[i]);
	}
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		int32 operation = rand() % 3;
		trie->oper[i](trie->t, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

/* benchmarks batch */
global_variable benchmark_fptr benchmarks[] = {
	benchmark_add,
	benchmark_search,
	benchmark_remove
};

/* main */
int32
main(int32 argc, char *argv[])
{
	argc -= 1;
	argv = &argv[1];
	if (argc != 3) {
		print_error_msg("benchmarks", "wrong number of arguments");
		return 1;
	}
	struct trie trie = {0};
	if (!strcmp(argv[0], "ternary")) {
		trie = TernaryTrieModel;
	} else if (!strcmp(argv[0], "array")) {
		trie = ArrayTrieModel;
	} else if (!strcmp(argv[0], "custom")) {
		trie = CustomTrieModel;
	} else {
		print_error_msg("benchmarks", "unknown trie");
		return 1;
	}
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		printf("%s\n", argv[1]);
		print_error_msg("benchmarks", "cannot open provided file");
		return 1;
	}
	fclose(f);
	uint32 i_benchmark = atoi(argv[2]);
	if (i_benchmark < 1 || i_benchmark > ArrayLength(benchmarks)) {
		print_error_msg("benchmarks", "wrong benchmark index");
		return 1;
	}
	struct dataset ds = {0};
	dataset_file_load(argv[1], &ds);
	uint64 result = benchmarks[i_benchmark - 1](&trie, &ds);
	printf("%-22s\t%12d\t%12f\n", argv[1], ds.wordcount, result/10e9);
	dataset_die(&ds);
	return 0;
}
