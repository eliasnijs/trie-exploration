#ifndef BASE_UTILS_H

/* depends on:
 * stdio.h, stdlib.h, base.h, time.h
 * */

/* macros and typedefs */

/* enumerations, structs, unions */

/* function definitions */
internal uint32 filelen(FILE *f);
internal uint64 nanos(); /* IMPORTANT(Elias): only valid if _POSIX_C_SOURCE is
			    199309 */

/* function implementations */
internal uint32
filelen(FILE *f)
{
	uint32 len = 0;
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, 0);
	return len;
}

internal uint64
nanos()
{
	struct timespec t;
  	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
  	return((uint64)t.tv_sec*10e9 + (uint64)t.tv_nsec);
}

#define BASE_UTILS_H
#endif
