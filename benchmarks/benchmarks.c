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

/* Trie Benchmarking Program
 *
 * Syntax:
 * benchmark <trie> <filepath> <benchmark index>
 * <trie>                  name of the trie
 * <filepath>              path to a dataset file
 * <benchmark index>       index of the benchmark
 * */


/* helpers */
#define Benchmark_Make(b) {#b, b}
typedef uint64 (* benchmark_fptr)(struct trie *t, struct dataset *ds);

struct benchmark {
	char *name;
	benchmark_fptr run;
};

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

/*
add 500k lijnen,
search ze allemaal eens,
remove ze allemaal,
add in omgekeerde volgorde,
search ze in omgekeerde
remove ze in omgekeerde volgorde
*/
internal uint64
benchmark_add_srch_rem_add_srch_rem(struct trie *trie, struct dataset *ds)
{
	trie_init(trie);
	uint64 start_t = nanos();
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_add(trie, ds->words[i]);
	}
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_search(trie, ds->words[i]);
	}
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		trie_remove(trie, ds->words[i]);
	}
	for (int32 i = ds->wordcount - 1; i >= 0; --i) {
		trie_add(trie, ds->words[i]);
	}
	for (int32 i = ds->wordcount - 1; i >= 0; --i) {
		trie_search(trie, ds->words[i]);
	}
	for (int32 i = ds->wordcount - 1; i >= 0; --i) {
		trie_remove(trie, ds->words[i]);
	}
	uint64 end_t = nanos();
	trie_free(trie);
	return end_t - start_t;
}

/* benchmarks batch */
global_variable struct benchmark benchmarks[] = {
	Benchmark_Make(benchmark_add),
	Benchmark_Make(benchmark_search),
	Benchmark_Make(benchmark_remove),
	Benchmark_Make(benchmark_add_srch_rem_add_srch_rem),
};

/* main */
int32
main(int32 argc, char *argv[])
{
	/* handle commandline arguments */
	argc -= 1;
	argv = &argv[1];
	if (argc > 0 && !strcmp(argv[0], "-h")) {
		printf("\n");
		printf("Trie Benchmarking Program\n");
		printf("\n");
		printf("syntax: ./benchmark <trie> <filepath> <benchmark index>\n");
		printf("<trie>			name of the trie\n");
		printf("<filepath>		path to a dataset file\n");
		printf("<benchmark index>	index of the benchmark\n");
		printf("\n");
		printf("available benchmarks: \n");
		for (uint32 i = 0; i < ArrayLength(benchmarks); ++i) {
			printf("%2d. %s\n", i + 1, benchmarks[i].name);
		}
		printf("\n");
		return 0;
	}
	if (argc != 3) {
		fprintf(stderr, "wrong number of arguments\n");
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
		fprintf(stderr, "unknown trie\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "cannot open provided file\n");
		return 1;
	}
	fclose(f);
	uint32 i_benchmark = atoi(argv[2]);
	if (i_benchmark < 1 || i_benchmark > ArrayLength(benchmarks)) {
		fprintf(stderr, "wrong benchmark index\n");
		return 1;
	}
	/* run benchmark */
	struct dataset ds = {0};
	dataset_file_load(argv[1], &ds);
	uint64 result = benchmarks[i_benchmark - 1].run(&trie, &ds);
	/* printf("%-40s\t%12d\t%12f\n", argv[1], ds.wordcount, result/10e9); */
	printf("%ld", result);
	dataset_die(&ds);
	return 0;
}
