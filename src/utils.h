/* depends on:
 * stdio.h, stdlib.h, base.h */

#include <stdio.h>
#include <stlib.h>
#include "base.h"

/* function definitions */
internal int8 getbit(const char *w, size_t size);
internal uint32 filelen(FILE *f);
internal void shuffle_ptr(void **buffer, uint32 count);

/* function implementations */
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
	srand(nanos()); // TODO(Elias): set random seed based on the current
			// time, not sure if this is a legitimate way to set
			// a seed
	for (uint32 i1 = 0; i1 < count - 1; ++i1) {
		int32 i2 = i1 + (rand() % (count - i1));
		Swap(buffer[i1], buffer[i2], void*);
	}
}
