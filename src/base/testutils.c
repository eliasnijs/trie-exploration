#ifndef BASE_TESTUTILS_H

/* depends upon:
 * stdio.h, stdlib.h, ncurses.h, base.h
 * */

/* TODO(Elias):
 * 1. reduce amount of macros, less macros is better
 * 2. switch to frame based instead of event based approach
 * 3. add backbuffers for each test (allows for saving results
 *    and running multiple tests at once)
 * 4. someway to reload to reload functions binary (might have to
 *     do a drastic change in architecture)
 * 4. color
 * 5. better explanation of everything at the beginning of the file.
 * */

/* Testutils are several functions for creating tests. I won't go into detail
 * here, look at an example to figure out how it works. There is also a tui
 * option. This option will let you render a nice interface in terminal. This
 * is espcially usefull when you have a large number of tests. The tui uses
 * vim keybinds to navigate and enter to run a test. (This is still in
 * development!)
 *
 * IMPORTANT(Elias): TESTUTILS_ENABLE_TERM_COLORS must be 0 when using
 * TESTUTILS_ENABLE_TUI.
 * */

/* macros */
#define TestUtils_Make_Test(f) {#f, f}
#define TestUtils_RunMultiple(ts,a) testutils_run_multiple(\
					ts, #a, a, sizeof(a)/sizeof(*(a)));
#define TestUtils_RunMultiple2(ts,a) testutils_run_multiple2(\
					ts, #a, a, sizeof(a)/sizeof(*(a)));
#define TestUtils_Assert(c) \
  Stmnt(\
    if (!(c)) {\
      printf("%s:%d, Assertion `%s` failed\n", __FILE__, __LINE__, #c);\
      if (testutilsstate->cleanup)\
        testutilsstate->cleanup(testutilsstate->cleanupargs);\
      return -1;\
  });

#if TESTUTILS_ENABLE_TERM_COLORS
#define ESC_GREEN   "\x1b[32m"
#define ESC_RED     "\x1b[31m"
#define ESC_RESET   "\x1b[0m"
#else
#define ESC_GREEN  ""
#define ESC_RED    ""
#define ESC_RESET  ""
#endif


#if TESTUTILS_ENABLE_TUI
#define INPUT_BUFFER_LEN 4
#define SELECT_PANEL_WIDTH 50
#define TestUtils_Tui_Bold(w,p) Stmnt(wattron(w, A_BOLD); p; wattroff(w, A_BOLD);)
#define TestUtils_Tui_Dim(w,p) Stmnt(wattron(w, A_DIM); p; wattroff(w, A_DIM);)
global_variable WINDOW *term_output_window = 0x0;
global_variable int32 term_output_window_y = 1;
#define printf(f, ...) Stmnt(mvwprintw(term_output_window, term_output_window_y,\
				       2, f, ##__VA_ARGS__);\
                             ++term_output_window_y;\
                             wrefresh(term_output_window);\
                            )
#define TestUtils_Tui(a) testutils_tui(#a, a, sizeof(a)/sizeof(*(a)))
#else
#define TestUtils_Tui(a) printf("Testutils tui is not enabled!\n"\
                                "Enable it by defining TESTUTILS_ENABLE_TUI"\
				"as 1 before including testutils.h.\n");
#endif


/* enumerations */
enum keys {
	TESTUTILS_KEY_QUIT     = 'q',
	TESTUTILS_KEY_CANCEL   = 'c',
	TESTUTILS_KEY_MOV_UP   = 'k',
	TESTUTILS_KEY_MOV_DOWN = 'j',
  	TESTUTILS_KEY_MOV_TO   = 'g',
  	TESTUTILS_KEY_MOV_END  = 'G',
  	TESTUTILS_KEY_RUN_TST  = '\n',
};

typedef struct TestUtilsState TestUtilsState;
struct TestUtilsState {
	void *cleanupargs;
	void (* cleanup)(void *);
};

typedef struct TestUtilsTest TestUtilsTest;
struct TestUtilsTest {
	char *name;
	int32 (* run)(TestUtilsState *testutilsstate);
};

/* function declartations */
#if TESTUTILS_ENABLE_TUI
internal void testutils_tui(char *name, TestUtilsTest *tests, int32 testcount);
internal void testutils_tui_handle_input(char *input, TestUtilsTest *tests,
				       int32 testcount, int32 *selected_index);
internal void testutils_tui_render_select(WINDOW *win, TestUtilsTest *tests,
					int32 testcount, int32 *selected_index);
internal void testutils_tui_render_output(WINDOW *win);
#endif
internal int32  testutils_run_single(TestUtilsState *testutils, TestUtilsTest *test);
internal int32  testutils_run_multiple(TestUtilsState *testutilsstate, char *name,
				   TestUtilsTest tests[], int32 testc);
internal int32  testutils_run_multiple2(TestUtilsState *testutilsstate, char *name,
				    TestUtilsTest tests[], int32 testc);

/* function ipmlementations */
#if TESTUTILS_ENABLE_TUI
internal void
testutils_tui_handle_input(char *input, TestUtilsTest *tests, int32 testcount,
			   int32 *selected_index)
{
	switch (input[0]) {
	case TESTUTILS_KEY_CANCEL:
		memset(input, 0, INPUT_BUFFER_LEN + 1);
                break;
	case TESTUTILS_KEY_MOV_UP:
		*selected_index = (*selected_index - 1);
		if (*selected_index < 0) {
			*selected_index = testcount;
		}
		memset(input, 0, INPUT_BUFFER_LEN + 1);
		break;
	case TESTUTILS_KEY_MOV_DOWN:
		*selected_index = (*selected_index + 1) % (testcount + 1);
		memset(input, 0, INPUT_BUFFER_LEN + 1);
		break;
	case TESTUTILS_KEY_MOV_TO:
		if (input[1] == 'g') {
			*selected_index = Clamp(0, atoi(input + 2) - 1,
						testcount);
			memset(input, 0, INPUT_BUFFER_LEN + 1);
		}
		break;
	case TESTUTILS_KEY_MOV_END:
		*selected_index = testcount;
		memset(input, 0, INPUT_BUFFER_LEN + 1);
		break;
	case TESTUTILS_KEY_RUN_TST:
		// TODO(Elias): consider the following...
		// Should we run the test in a child process, in the child
		// process we can then render the output to a backbuffer and
		// then render this buffer in the parent process. This way we
		// will prevent a glitchy terminal... If we decide to go this
		// way, we will have to change to a frame based approach
		// instead of event based approach (we would do this in order
		// to not freeze the terminal during the execution of a test).
		term_output_window_y = 1;
		TestUtilsState testutils;
		werase(term_output_window);
		testutils_tui_render_output(term_output_window);
		if (*selected_index > 0) {
			testutils_run_single(&testutils,
					     &tests[*selected_index - 1]);
		} else {
			testutils_run_multiple2(&testutils, "All tests", tests,
						testcount);
		}
		memset(input, 0, INPUT_BUFFER_LEN + 1);
		break;
  }
}

internal void
testutils_tui_render_select(WINDOW *win, TestUtilsTest *tests, int32 testcount,
			    int32 *selected_index)
{
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  	TestUtils_Tui_Bold(win, mvwprintw(win, 0, 2, "TESTS(%d)", testcount));
  	if (*selected_index == 0) {
		TestUtils_Tui_Bold(win, mvwprintw(win, 1, 1, ">     All tests"));
  	} else {
		TestUtils_Tui_Dim(win, mvwprintw(win, 1, 1, "      All tests"));
  	}
  	for (uint32 i = 0; i < testcount; ++i) {
		if (*selected_index == i + 1) {
			TestUtils_Tui_Bold(win, mvwprintw(win, 2 + i, 1,
					"> %2d. %s", i + 1, tests[i].name));
		} else {
			TestUtils_Tui_Dim(win, mvwprintw(win, 2 + i, 1,
					"  %2d. %s", i + 1, tests[i].name));
		}
  	}
  	wrefresh(win);
}

internal void
testutils_tui_render_output(WINDOW *win)
{
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	TestUtils_Tui_Bold(win, mvwprintw(win, 0, 2, "OUTPUT"));
	wrefresh(win);
}

internal void
testutils_tui(char *name, TestUtilsTest *tests, int32 testcount)
{
	int32 screen_width = 0, screen_height = 0, selected_index = 0;
  	WINDOW *win_select = 0x0, *win_output = 0x0;
  	char input[INPUT_BUFFER_LEN + 1] = {0};
  	initscr();
  	noecho();
  	keypad(stdscr, true);
  	getmaxyx(stdscr, screen_height, screen_width);
  	win_select = newwin(screen_height, SELECT_PANEL_WIDTH, 0, 0);
  	win_output = newwin(screen_height, screen_width - SELECT_PANEL_WIDTH, 0,
			    SELECT_PANEL_WIDTH);
  	scrollok(win_output, true);
  	refresh();
  	testutils_tui_render_output(win_output);
  	wrefresh(win_output);
  	term_output_window = win_output;
  	while (input[0] != TESTUTILS_KEY_QUIT) {
		getmaxyx(stdscr, screen_height, screen_width);
  	  	win_select = newwin(screen_height, SELECT_PANEL_WIDTH, 0, 0);
  	  	win_output = newwin(screen_height,
				    screen_width - SELECT_PANEL_WIDTH, 0,
				    SELECT_PANEL_WIDTH);
  	  	refresh();
  	  	testutils_tui_handle_input(input, tests, testcount,
					   &selected_index);
  	  	testutils_tui_render_output(term_output_window);
  	  	testutils_tui_render_select(win_select, tests, testcount,
					    &selected_index);
  	  	for (int32 i = INPUT_BUFFER_LEN - 2; i >= 0; --i) {
  	  	  input[i + 1] = input[i];
		}
  	  	input[0] = getch();
  	}
  	delwin(win_select);
  	delwin(win_output);
  	endwin();
}
#endif

internal int
testutils_run_single(TestUtilsState *testutils, TestUtilsTest *test)
{
	printf("> %s (%s %s) \n", test->name, __DATE__, __TIME__);
  	int32 s = test->run(testutils);
  	printf("> %s%s%s\n", (!s)?ESC_GREEN:ESC_RED, (!s)?"[OK]":"FAILED ",
	       ESC_RESET);
  	return s == 0;
}

internal int
testutils_run_multiple2(TestUtilsState *testutilsstate, char *name,
			TestUtilsTest tests[], int32 testc)
{
	int32 i, succount;
  	printf("> %s (%d tests, %s %s): \n", name, testc, __DATE__, __TIME__);
  	for (i = 0, succount = 0; i < testc; ++i) {
		printf("\n");
  	  	testutilsstate->cleanupargs = 0x0;
  	  	testutilsstate->cleanup     = 0x0;
  	  	printf("> %2d. %s \n", i + 1, tests[i].name);
  	  	int32 s = tests[i].run(testutilsstate);
  	  	if (s == 0) {
  	  	  ++succount;
		}
  	  	printf("> %s%s%s\n", (!s)?ESC_GREEN:ESC_RED,
		       (!s)?"[OK]":"[FAILED]", ESC_RESET);
  	}
  	printf("\n");
  	printf("> %d test(s) finished: %d test(s) succeeded,"\
	       "%d test(s) failed\n", testc, succount, testc - succount);
  	printf("\n");
  	return succount == testc;
}

internal int32
testutils_run_multiple(TestUtilsState *testutilsstate, char *name,
		       TestUtilsTest tests[], int32 testc)
{
	int32 i, succount;
  	printf("%s (%d tests, %s %s): \n", name, testc, __DATE__, __TIME__);
  	for (i = 0, succount = 0; i < testc; ++i) {
		testutilsstate->cleanupargs = 0x0;
		testutilsstate->cleanup     = 0x0;
  	  	printf("%2d. ", i + 1);
  	  	int32 s = tests[i].run(testutilsstate);
  	  	if (s == 0) {
  	  	  ++succount;
		}
  	  	if (s == -1) {
  	  	  printf("    ");
		}
  	  	printf("%s%s%s | %s\n", (!s)?ESC_GREEN:ESC_RED,
		       (!s)?"SUCCESS":"FAILED ", ESC_RESET, tests[i].name);
  	}
  	printf("%d test(s) finished: %d test(s) succeeded, %d test(s) failed\n",
	       testc, succount, testc - succount);
  	printf("\n");
  	return succount == testc;
}


#define BASE_TESTUTILS_H
#endif
