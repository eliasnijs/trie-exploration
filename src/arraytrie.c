#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "cbase/cbase.h"

typedef struct atrie ArrayTrie;
struct atrie {
    S32 size;
};

ArrayTrie* 
arraytrie_init();

void 
arraytrie_free(ArrayTrie* trie)
{
  return;
}

B32 
arraytrie_search(ArrayTrie* trie, const char* string)
{
  return true;
}

B32 
arraytrie_add(ArrayTrie* trie, const char* string)
{
  return true;
}

B32 
arraytrie_remove(ArrayTrie* trie, const char* string)
{
  return true;
}

U16 
arraytrie_size(ArrayTrie* trie)
{
  return 0;
}
