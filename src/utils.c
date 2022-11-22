/* depends on:
 * stdio.h, stdlib.h, time.h, base.h */

#include <stdio.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 199309L
#include <time.h>

#include "base.h"

/* function definitions */
/* internal uint64 nanos(); */
internal int8 getbit(const char *w, size_t size);
internal uint32 filelen(FILE *f);
internal void shuffle_ptr(void **buffer, uint32 count);

/* internal uint64 */
/* nanos() */
/* { */
/*   struct timespec start; */
/*   clock_gettime(CLOCK_MONOTONIC_RAW, &start); */
/*   return((uint64)start.tv_sec*1000000000 + (uint64)start.tv_nsec); */
/* } */

internal int8
getbit(const char *w, size_t i)
{
	return (w[i/8] >> (i % 8)) & 0b1;
}

internal uint32
filelen(FILE *f)
{
	uint32 len = 0;
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, 0);
	return len;
}

internal void
shuffle_ptr(void **buffer, uint32 count)
{
	//srand(nanos());
	for (uint32 i1 = 0; i1 < count - 1; ++i1) {
		int32 i2 = i1 + (rand() % (count - i1));
		Swap(buffer[i1], buffer[i2], void*);
	}
}
