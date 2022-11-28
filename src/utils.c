/* depends on:
 * stdio.h, stdlib.h, base.h, time.h */

/* macros and typedefs */
typedef void (* printelem_fptr)(FILE *f, const void *ptr);

/* enumerations, structs, unions */
struct sllist {
	struct sllist *next;
};

/* function definitions */
internal uint64 nanos();
internal int8 getbit(const char *w, size_t size);
internal uint32 filelen(FILE *f);
internal void shuffle_ptr(void **buffer, uint32 count);
internal void llist_to_file(FILE *f, const struct sllist *elem,
			    printelem_fptr printelem_fptr);

/* function implementations */
internal uint64
nanos()
{
	struct timespec t;
  	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
  	return((uint64)t.tv_sec*10e9 + (uint64)t.tv_nsec);
}

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
	srand(nanos()); /* TODO(Elias): set random seed based on the current
			 * time, not sure if this is a legitimate way to
			 * randomize. */
	for (uint32 i1 = 0; i1 < count - 1; ++i1) {
		int32 i2 = i1 + (rand() % (count - i1));
		Swap(buffer[i1], buffer[i2], void*);
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
