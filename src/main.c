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

#include "tests_tst.c"
#include "tests_arrt.c"
#include "tests_ct.c"

#include "dataset.c"
#include "statistics.c"
#include "benchmark.c"

int32
main_benchmark()
{
	struct dataset ds;
	/* dataset_generate(4, 12, 21000, &ds); */
	dataset_file_load("resources/geschud_klein.g6", &ds);

	struct benchmark_sll *b_start = benchmark_run(&ds);

	llist_to_file(stdout, (struct sllist *)b_start, benchmark_sll_print);
	FILE *f = fopen("data/benchmarks.txt", "w");
	llist_to_file(f, (struct sllist *)b_start, benchmark_sll_print);
	fclose(f);

	dataset_die(&ds);
	benchmark_sll_die(b_start);

	return 0;
}

int32
main(int32 argc, char *argv[])
{
	main_benchmark();
	return 0;
}
