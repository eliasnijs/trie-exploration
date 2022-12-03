#ifndef BASE_UTILS_H

/* depends on:
 * stdio.h, stdlib.h, base.h, time.h
 * */

/* macros and typedefs */
typedef void (* printelem_fptr)(FILE *f, const void *ptr);

/* enumerations, structs, unions */
struct sllist {
	struct sllist *next;
};

/* function definitions */
internal uint64 nanos(); /* IMPORTANT(Elias): only valid if _POSIX_C_SOURCE is
			    199309 */
internal int8 getbit(const char *w, size_t size);
internal uint32 filelen(FILE *f);
internal void shuffle_ptr(void **buffer, uint32 count);
internal void llist_to_file(FILE *f, const struct sllist *elem,
			    printelem_fptr printelem_fptr);
internal bool32 is_pow_of_two(uintptr_t addr);
internal uintptr_t ptr_align_forward(uintptr_t p, size_t align);

/* function implementations */
#if _POSIX_C_SOURCE == 199309
internal uint64
nanos()
{
	struct timespec t;
  	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
  	return((uint64)t.tv_sec*10e9 + (uint64)t.tv_nsec);
}
#else
internal uint64
nanos()
{
	Assert(_POSIX_C_SOURCE == 199309);
	return 0;
}
#endif

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
/* Implements Fisher–Yates shuffle algorithm */
	srand(nanos()); /* TODO(Elias): set random seed based on the current
			 * time, not sure if this is a legitimate way to
			 * randomize. */
	for (uint32 i1 = count - 1; i1 > 0; --i1) {
		int32 i2 = rand() % (i1 + 1);
		void *temp = buffer[i2];
		buffer[i2] = buffer[i1];
		buffer[i1] = temp;
	}
}

internal void
llist_to_file(FILE *f, const struct sllist *elem,
	      printelem_fptr printelem_fptr)
{
	while (elem) {
		printelem_fptr(f, elem);
		elem = elem->next;
	}
}

internal bool32
is_pow_of_two(uintptr_t addr)
{
  return (addr & (addr - 1)) == 0;
}

internal uintptr_t
ptr_align_forward(uintptr_t p, size_t align)
{
  Assert(is_pow_of_two(align));
  uintptr_t a = (uintptr_t)align;
  /* NOTE(Elias): equivalent to p % a, but faster. (works because 'a' is a
   * power of 2) */
  uintptr_t m = p & (a - 1);
  if (m)
    p += a - m;
  return p;
}

#define BASE_UTILS_H
#endif
