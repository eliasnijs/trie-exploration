#define ALPHASIZE 0b1111111

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ncurses.h>

#include "base.c"
#include "ansii_esc_codes.c"
#include "utils.c"

#define TESTUTILS_ENABLE_TERM_COLORS 0
#define TESTUTILS_ENABLE_TUI 0
#include "testutils.c"

#include "ternarytrie.c"
#include "arraytrie.c"
#include "customtrie.c"
#include "trie.c"

#include "dataset.c"

#include "tests.c"

#include "benchmark.c"

internal int32
main_benchmark()
{
	struct trie tries[] = {
		TernaryTrieModel,
	};
	char *filepaths[] = {
		"resources/geschud_piepklein.g6",
		"resources/geschud_klein.g6",
		"resources/geschud_middelmaat.g6",
		"resources/geschud_groot.g6",
		"resources/bonzai.g6",
		"resources/geschud.g6",
		"resources/globosum.g6",
	};

	printf("\n");
	struct benchmark_sll *b_add_start = 0x0, *b_afbrm_start = 0x0;
	struct benchmark_sll **b_add_last = &b_add_start,
			     **b_afbrm_last = &b_afbrm_start;

	for (int32 i = 0; i < ArrayLength(filepaths); ++i) {
		printf("> running benchmarks for '%s'\n", filepaths[i]);
		struct dataset ds;
		dataset_file_load(filepaths[i], &ds);

		*b_add_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_add_run(&ds, tries, ArrayLength(tries), *b_add_last);
		b_add_last = &(*b_add_last)->next;

		*b_afbrm_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_afbrm_run(&ds, tries, ArrayLength(tries),
				    *b_afbrm_last);
		b_afbrm_last = &(*b_afbrm_last)->next;

		dataset_die(&ds);
	}

	FILE *f = 0x0;

	/* print to terminal */
	printf("benchmark_add results: \n");
	llist_to_file(stdout, (struct sllist *)b_add_start,
		      benchmark_sll_print);
	printf("benchmark_add_followed_by_rm results: \n");
	llist_to_file(stdout, (struct sllist *)b_afbrm_start,
		      benchmark_sll_print);

	/* save to files */
	f = fopen("data/benchmarks_add.txt", "w");
	llist_to_file(f, (struct sllist *)b_add_start, benchmark_sll_print);
	fclose(f);
	f = fopen("data/benchmarks_afbrm.txt", "w");
	llist_to_file(f, (struct sllist *)b_afbrm_start, benchmark_sll_print);
	fclose(f);

	benchmark_sll_die(b_add_start);
	benchmark_sll_die(b_afbrm_start);

	return 0;
}

internal int32
main_tests()
{
	TestsTrieModel = TernaryTrieModel;
	TestUtilsState ts = {0};
	TestUtils_RunMultiple(&ts, tests_trie);
	return 0;
}

int32
main(int32 argc, char *argv[])
{
	/* return main_benchmark(); */
	return main_tests();
}





