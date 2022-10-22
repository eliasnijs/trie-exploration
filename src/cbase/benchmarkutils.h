/* IMPORTANT(Elias): ! Requires  POSIX.1b ! */

/* NOTE(Elias): times an operation */
#define Bu_TimeNano(a,t) {\
  S64 start_t = bu_nanos();\
  a;\
  S64 end_t = bu_nanos();\
  t = end_t - start_t;\
}

/* NOTE(Elias): returns current time in nanoseconds */
internal U64 bu_nanos();
