#ifndef BASE_MEMORY_POOL_H

/* depends on:
 * stdio.h, stdlib.h, stdint.h, base.h, utils.h */

/* Memory Pool:
 * One big container of same sized chuncks. The memory is freed all at once.
 * (memory is persistent until the arena is destroyed). Memory is guaranteed to
 * be zeroed.
 * */

/* enumerations, structs, unions */
struct m_pool_freenode {
	struct m_pool_freenode *next;
};

struct m_pool {
	uint8 *buf;
	size_t buflen;
	size_t chunklen;
	struct m_pool_freenode *head;
};

/* function definitions */
internal void m_pool_init(struct m_pool *p, void *b, size_t bl, size_t cl,
			size_t ca);
internal void m_pool_reset(struct m_pool *p);
internal void * m_pool_alloc(struct m_pool *p);
internal void m_pool_free(struct m_pool *p, void *ptr);

/* function implementations */
internal void
m_pool_init(struct m_pool *p, void *b, size_t bl, size_t cl, size_t ca)
{
	uintptr_t is = (uintptr_t)b;
	uintptr_t s = ptr_align_forward(is, (uintptr_t)ca);
	bl -= (size_t)(s - is);
	cl = ptr_align_forward(cl, ca);

	Assert(cl >= sizeof(struct m_pool_freenode));
	Assert(bl >= cl);

	p->buf = (uint8 *)b;
	p->buflen = bl;
	p->chunklen = cl;
	p->head = 0x0;

	m_pool_reset(p);
}

internal void
m_pool_reset(struct m_pool *p)
{
	size_t ccnt = p->buflen / p->chunklen;
	for (size_t i = 0; i < ccnt; ++i) {
		void *ptr = &p->buf[i * p->chunklen];
		struct m_pool_freenode *node = (struct m_pool_freenode *)ptr;
		node->next = p->head;
		p->head = node;
	}
}

internal void *
m_pool_alloc(struct m_pool *p)
{
	struct m_pool_freenode *n = p->head;
	Assert(n != 0 && "pool allocator has no memory left");
	p->head = p->head->next;
	return memset(n, 0, p->chunklen);
}

internal void
m_pool_free(struct m_pool *p, void *ptr)
{
	Assert((void *)p->buf <= ptr && ptr < (void *)(p->buf + p->buflen)
	       && "ptr is out of bounds");
	struct m_pool_freenode *n = (struct m_pool_freenode *)ptr;
	n->next = p->head;
	p->head = n;
}

#define BASE_MEMORY_POOL_H
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
