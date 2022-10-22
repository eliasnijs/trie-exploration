/* NOTE(Elias): returns current time in nanoseconds */
internal U64
bu_nanos()
{
  struct timespec start;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  return((S64)start.tv_sec*1000000000 + (S64)start.tv_nsec);
}
