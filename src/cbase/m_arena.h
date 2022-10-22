//////////////////////////////////////////////////////////////////////////////////////
//// Memory Arena

/* Memory Arena:
 * One big container, allocations always happen at the end.
 * The memory is freed all at once. (memory is persistent until 
 * the arena is destroyed) */

typedef struct Mem_Arena Mem_Arena;
struct Mem_Arena {
  U8  *buf;          /* ptr to the reserved memory bufer for the arena */
  U16 len;           /* length of the reserved memory */
  U16 offset_curr;   /* current offset into the bufer */
  U16 offset_prev;   /* previous offset into the bufer */
};

/* NOTE(Elias): initialise an arena */
internal void m_arena_init(Mem_Arena *a, void *backing_buffer, U16 backing_buffer_length);

/* NOTE(Elias): destroy an arena */
internal void m_arena_reset(Mem_Arena *a);

/* NOTE(Elias): allocate memory in a memory arena with alignment 
 * specified (memory is NOT zeroed) */
internal void * m_arena_alloc_align(Mem_Arena *a, U16 len, U16 align);

/* NOTE(Elias): default memory alignment, = 16, checkout (`Streaming SIMD Extensions` for the why) */
#ifndef MEM_DEFAULT_ALIGNMENT
#define MEM_DEFAULT_ALIGNMENT (2*sizeof(void *))
#endif

/* NOTE(Elias): allocate memory in a memory arena */
internal void * m_arena_alloc(Mem_Arena *a, U16 len);

/* NOTE(Elias): free allocated memory in the arena ( ! does nothing ) */
internal void m_arena_free(Mem_Arena *a, void *ptr);

//////////////////////////////////////////////////////////////////////////////////////
//// Helper Functions

/* NOTE(Elias): returns if an address is on a power off 2 */
internal B32 is_pow_of_two(uintptr_t addr);

/* NOTE(Elias): push a pointer to the next aligned value */
internal uintptr_t align_forward(uintptr_t p, U16 align);

//////////////////////////////////////////////////////////////////////////////////////
//// References 

/* (c) This code is based on ideas and code from: 
 * 1. Base [4]: Memory Management, Mr. 4th Programming by Allen Webster 
 *    https://www.youtube.com/watch?v=L79vSP8yV2g 
 * 2. Memory Allocation Strategies by GingerBill, 
 *    https://www.gingerbill.org/series/memory-allocation-strategies/  
 * 3. Handmade Hero eps034 by Casey Muratori
 *    https://www.youtube.com/watch?v=IJYTwhqfKLg
 * 4. Untangling Lifetimes: The Arena Allocator by Ryan Fleury
 *    https://www.rfleury.com/p/untangling-lifetimes-the-arena-allocator */


