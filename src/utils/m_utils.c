#ifndef BASE_UTILS_H

/* depends on:
 * stdio.h, stdlib.h, base.h, time.h
 * */

/* macros and typedefs */

/* enumerations, structs, unions */

/* function definitions */
internal bool32 is_pow_of_two(uintptr_t addr);
internal uintptr_t ptr_align_forward(uintptr_t p, size_t align);

/* function implementations */

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
	/* NOTE(Elias): equivalent to p % a, but faster. (works because 'a' is
	 * a power of 2) */
	uintptr_t m = p & (a - 1);
	if (m) {
		p += a - m;
	}
	return p;
}

#define BASE_UTILS_H
#endif
