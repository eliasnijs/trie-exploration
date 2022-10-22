static int 
tu_run_multiple(char *name, Tu_Test tests[], int testc)
{
  S32 i, s, succount;
  S64 time;

  printf("%s (%d tests, %s %s): \n", name, testc, __DATE__, __TIME__);
  for (i = 0, succount = 0; i < testc; ++i) {
    printf("%2d. ", i + 1);
    Bu_TimeNano(s = tests[i].run(), time);
    if (s == 0)
      ++succount;
#if TU_ENABLE_ASSERT_MSG
    if (s == -1)
      printf("    ");
#endif
    printf("%s | %s (%f sec)\n", 
        (s == 0) ? ESC_GREEN"success"ESC_RESET : ESC_RED"failed "ESC_RESET, 
        tests[i].name, time/10e9);
  }
  printf("%d test(s) finished: %d test(s) succeeded, %d test(s) failed\n", testc, succount, testc - succount);
  printf("\n");
  
  return (succount == testc);
}
