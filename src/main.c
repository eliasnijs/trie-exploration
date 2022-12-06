#define ALPHASIZE 0b1111111

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ncurses.h>

#include "base/base.c"
#include "base/ansii_esc_codes.c"
#include "base/utils.c"
#include "base/m_arena.c"
#include "base/m_pool.c"
#define TESTUTILS_ENABLE_TERM_COLORS 1
#define TESTUTILS_ENABLE_TUI 0
#include "base/testutils.c"

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
		CustomTrieModel,
		TernaryTrieModel,
		ArrayTrieModel,
	};
	char *filepaths[] = {
		"resources/geschud_piepklein.g6",
		"resources/geschud_klein.g6",
		"resources/geschud_middelmaat.g6",
		"resources/geschud_groot.g6",
		"resources/bonzai.g6",
		"resources/geschud.g6",
		"resources/globosum.g6",
		"resources/words.txt",
	};
	int32 memamount[] = {
		/* Kilobytes(300), */
		/* Megabytes(4), */
		/* Megabytes(500), */
		/* Megabytes(500), */
	};

	printf("\n");
	struct benchmark_sll *b_add_start = 0x0, *b_afbrm_start = 0x0,
			     *b_afbsfbrm_start = 0x0,
			     *b_afbsfbrm_splay_start = 0x0;
	struct benchmark_sll **b_add_last = &b_add_start,
			     **b_afbrm_last = &b_afbrm_start,
			     **b_afbsfbrm_last = &b_afbsfbrm_start,
			     **b_afbsfbrm_splay_last = &b_afbsfbrm_splay_start;

	for (int32 i = 0; i < ArrayLength(filepaths); ++i) {
		printf("> running benchmarks for '%s'\n", filepaths[i]);
		struct dataset ds = {0};
		dataset_file_load(filepaths[i], &ds);

		*b_add_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_add_run(&ds, tries, ArrayLength(tries), *b_add_last,
				  memamount[i]);
		b_add_last = &(*b_add_last)->next;

		*b_afbrm_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_afbrm_run(&ds, tries, ArrayLength(tries),
				    *b_afbrm_last, memamount[i]);
		b_afbrm_last = &(*b_afbrm_last)->next;

		*b_afbsfbrm_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_afbsfbrm_run(&ds, tries, ArrayLength(tries),
				    *b_afbsfbrm_last, memamount[i]);
		b_afbsfbrm_last = &(*b_afbsfbrm_last)->next;

		*b_afbsfbrm_splay_last = (struct benchmark_sll *)calloc(
		    1, sizeof(struct benchmark_sll));
		benchmark_afbsfbrm_splay_run(&ds, tries, ArrayLength(tries),
				    *b_afbsfbrm_splay_last, memamount[i]);
		b_afbsfbrm_splay_last = &(*b_afbsfbrm_splay_last)->next;

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
	printf("benchmark_add_followed_by_search_followed_by_rm results: \n");
	llist_to_file(stdout, (struct sllist *)b_afbsfbrm_start,
		      benchmark_sll_print);
	printf("benchmark_add_followed_by_search_followed_by_rm_splay"\
	       "results: \n");
	llist_to_file(stdout, (struct sllist *)b_afbsfbrm_splay_start,
		      benchmark_sll_print);

	/* save to files */
	f = fopen("data/benchmarks_add.txt", "w");
	llist_to_file(f, (struct sllist *)b_add_start, benchmark_sll_print);
	fclose(f);
	f = fopen("data/benchmarks_afbrm.txt", "w");
	llist_to_file(f, (struct sllist *)b_afbrm_start, benchmark_sll_print);
	fclose(f);
	f = fopen("data/benchmarks_afbsfbrm.txt", "w");
	llist_to_file(f, (struct sllist *)b_afbsfbrm_start,
		      benchmark_sll_print);
	fclose(f);
	f = fopen("data/benchmarks_afbsfbrm_splay.txt", "w");
	llist_to_file(f, (struct sllist *)b_afbsfbrm_splay_start,
		      benchmark_sll_print);
	fclose(f);

	benchmark_sll_die(b_add_start);
	benchmark_sll_die(b_afbrm_start);
	benchmark_sll_die(b_afbsfbrm_start);
	benchmark_sll_die(b_afbsfbrm_splay_start);

	return 0;
}

internal int32
main_tests()
{
	TestUtilsState ts = {0};
	printf(ANSII_ESC_BOLD\
	       ANSII_ESC_RGB_FG(240, 150, 30)\
	       ">>> Testing Ternary\n");
	TestsTrieModel = TernaryTrieModel;
	TestUtils_RunMultiple(&ts, tests_trie);
	printf(ANSII_ESC_BOLD\
	       ANSII_ESC_RGB_FG(240, 150, 30)\
	       ">>> Testing Array\n");
	TestsTrieModel = ArrayTrieModel;
	TestUtils_RunMultiple(&ts, tests_trie);
	printf(ANSII_ESC_BOLD\
	       ANSII_ESC_RGB_FG(240, 150, 30)\
	       ">>> Testing Custom\n");
	TestsTrieModel = CustomTrieModel;
	TestUtils_RunMultiple(&ts, tests_trie);
	return 0;
}

int32
main(int32 argc, char *argv[])
{
	main_tests();
	/* main_benchmark(); */
	return 0;
}
