#ifndef BASE_MEMORY_ARENA_H

/* depends on:
 * stdio.h, stdlib.h, stdint.h, base.h, utils.h */

/* Memory Arena:
 * One big container, allocations always happen at the end. The memory is freed
 * all at once. (memory is persistent until the arena is destroyed). Memory is
 * not guaranteed to be zeroed.
 * */

/* macros */

/* enumerations, structs, unions */
struct m_arena {
  uint8  *buf;
  size_t len;
  size_t offset_curr;
  size_t offset_prev;
};

/* function declarations */
internal void m_arena_init(struct m_arena *a, void *backing_buffer,
			   size_t backing_buffer_length);
internal void * m_arena_alloc(struct m_arena *a, size_t len);
internal void * m_arena_zalloc(struct m_arena *a, size_t len);
internal void * m_arena_alloc_align(struct m_arena *a, size_t len,
				    size_t align);
internal void m_arena_reset(struct m_arena *a);
internal void m_arena_free(struct m_arena *a, void *ptr);

/* function implementations */
internal void
m_arena_init(struct m_arena *a, void *backing_buffer,
	     size_t backing_buffer_length)
{
	a->buf = (uint8 *)backing_buffer;
  	a->len = backing_buffer_length;
  	a->offset_curr = 0;
  	a->offset_prev = 0;
}

internal inline void
m_arena_reset(struct m_arena *a)
{
	a->offset_curr = 0;
  	a->offset_prev = 0;
}

internal void *
m_arena_alloc(struct m_arena *a, size_t len)
{
	return m_arena_alloc_align(a, len, MEM_DEFAULT_ALIGNMENT);
}

internal void *
m_arena_alloc_align(struct m_arena *a, size_t len, size_t align)
{
	void *ptr = 0x0;
  	uintptr_t ptr_curr = (uintptr_t)a->buf + (uintptr_t)a->offset_curr;
  	uintptr_t offset = ptr_align_forward(ptr_curr, align) - (uintptr_t)a->buf;
	Assert(offset + len <= a->len);
  	if (offset + len <= a->len)
  	{
		ptr = &a->buf[offset];
  		a->offset_prev = offset;
  		a->offset_curr = offset + len;
  	}
  	return ptr;
}

internal void
m_arena_free(struct m_arena *a, void *ptr)
{
/* Does nothing. Is here for completeness */
}

#define BASE_MEMORY_ARENA_H
#endif

/* references */

/* TODO(Elias): Put these references in a decent format xd */

/* (c) This code is based on ideas and code from:
 * 1. Base [4]: Memory Management, Mr. 4th Programming by Allen Webster
 *    https://www.youtube.com/watch?v=L79vSP8yV2g
 * 2. Memory Allocation Strategies by GingerBill,
 *    https://www.gingerbill.org/series/memory-allocation-strategies/
 * 3. Handmade Hero eps034 by Casey Muratori
 *    https://www.youtube.com/watch?v=IJYTwhqfKLg
 * 4. Untangling Lifetimes: The Arena Allocator by Ryan Fleury
 *    https://www.rfleury.com/p/untangling-lifetimes-the-arena-allocator */

