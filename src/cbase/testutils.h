typedef struct Tu_Test Tu_Test;
struct Tu_Test {
  char *name;
  int (* run)(void);
};

#define Tu_TestInit(f) {#f, f}

#ifdef ENABLE_TERM_COLORS
#define ESC_GREEN   "\x1b[32m"
#define ESC_RED     "\x1b[31m"
#define ESC_RESET   "\x1b[0m"
#else
#define ESC_GREEN
#define ESC_RED
#define ESC_RESET
#endif

#if TU_ENABLE_ASSERT_MSG
#define Tu_Assert(c) \
  Stmnt(\
    if (!(c)) {\
      printf("Assertion `%s` at %s:%d failed!\n", #c, __FILE__, __LINE__);\
      return -1;\
  });
#else
#define Tu_Assert(c); if (!(c)) return -1;
#endif

static int tu_run_multiple(char *name, Tu_Test tests[], int testc);
#define Tu_RunMultiple(a) tu_run_multiple(#a, a, sizeof(a)/sizeof(*(a)));

