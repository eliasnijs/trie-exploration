#define ALPHASIZE 0b1111111

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

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

internal void
print_error_msg(char *systemname, char *msg)
{
	fprintf(stderr, "%s: %s\n", systemname, msg);
}

internal int32
main_benchmark(int32 argc, char *argv[])
{
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
	if (access(argv[1], F_OK)) {
		print_error_msg("benchmarks", "cannot open provided file");
		return 1;
	}
	int32 i_benchmark = atoi(argv[2]);
	if (i_benchmark < 1 || i_benchmark > ArrayLength(benchmarks)) {
		print_error_msg("benchmarks", "wrong benchmark index");
		return 1;
	}
	struct dataset ds = {0};
	dataset_file_load(argv[1], &ds);
	uint64 result = benchmarks[i_benchmark - 1](&trie, &ds);
	printf("%f\n", result/10e9);
	dataset_die(&ds);
	return 0;
}

internal int32
main_tests()
{
	/* TestUtils_Tui(tests_trie); */

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
	/* main_tests(); */
	main_benchmark(argc - 1, &argv[1]);
	return 0;
}
