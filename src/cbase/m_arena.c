//////////////////////////////////////////////////////////////////////////////////////
//// NOTE(Elias): Memory Arena

/* NOTE(Elias): initialise an arena */
internal void 
m_arena_init(Mem_Arena *a, void *backing_buffer, U16 backing_buffer_length)
{
  a->buf = (U8 *)backing_buffer;
  a->len = backing_buffer_length;
  a->offset_curr = 0;
  a->offset_prev = 0;
}

/* NOTE(Elias): destroy an arena */
internal inline void 
m_arena_reset(Mem_Arena *a)
{
  a->offset_curr = 0;
  a->offset_prev = 0;
}

/* NOTE(Elias): allocate memory in a memory arena with alignment specified */
/* IMPORTANT(Elias): memory is not guaranteed to be 0! */
internal void *
m_arena_alloc_align(Mem_Arena *a, U16 len, U16 align)
{
  void *ptr;
  uintptr_t ptr_curr, offset;
  
  ptr = 0x0;
  ptr_curr = (uintptr_t)a->buf + (uintptr_t)a->offset_curr;
  offset = align_forward(ptr_curr, align) - (uintptr_t)a->buf; 
  
  if (offset + len <= a->len)
  {
    ptr = &a->buf[offset];
    a->offset_prev = offset;
    a->offset_curr = offset + len;
  }

  return ptr;
}

/* NOTE(Elias): allocate memory in a memory arena */
/* IMPORTANT(Elias): memory is not guaranteed to be 0! */
internal void *
m_arena_alloc(Mem_Arena *a, U16 len)
{
  return m_arena_alloc_align(a, len, MEM_DEFAULT_ALIGNMENT);
}

//////////////////////////////////////////////////////////////////////////////////////
//// Helper Functions 

/* NOTE(Elias): returns if an address is on a power off 2 */
internal B32
is_pow_of_two(uintptr_t addr)
{
  return (addr & (addr - 1)) == 0;
}

/* NOTE(Elias): push a pointer to the next aligned value */
internal uintptr_t 
align_forward(uintptr_t p, U16 align)
{
  uintptr_t a, m;
  
  Assert( is_pow_of_two(align) );
 
  a = (uintptr_t)align;
  /* NOTE(Elias): equivalent to p % a, but faster. (works because 'a' is a power of 2) */
  m = p & (a - 1); 
  if (m)
    p += a - m;
  
  return p;
}

