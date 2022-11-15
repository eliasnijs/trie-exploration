#include "arraytrie.h"

struct atrie
{
  size_t wc;
};

/**
 * Allocate and initialize an empty Trie.
 *
 * @return a pointer to an empty Trie struct
 */
ArrayTrie *
arraytrie_init()
{
  return 0x0;
}

/**
 * De-allocate a trie by freeing the memory occupied by this trie.
 *
 * @param trie which should be freed
 */
void
arraytrie_free(ArrayTrie* trie)
{
  return;
}

/**
 * Search whether a string is contained in this trie.
 *
 * @param trie
 * @param string
 * @return true if the string is contained within this trie, false otherwise
 */
bool
arraytrie_search(ArrayTrie* trie, const char* string)
{
  return false;
}

/**
 * Add a string to this trie.
 *
 * @param trie
 * @param string
 * @return true if the trie was changed by this operation, false if it was already present
 */
bool
arraytrie_add(ArrayTrie* trie, const char* string)
{
  return false;
}

/**
 * Remove a string from this trie.
 *
 * Note: strings added to this trie are considered to be "owned" by the caller.
 * Removing the string from the trie should not free the string's memory.
 *
 * @param trie
 * @param string
 * @return true if the string was present and has been removed, false if it was not present
 */
bool
arraytrie_remove(ArrayTrie* trie, const char* string)
{
  return false;
}

/**
 * Returns the number of strings in this trie.
 *
 * @param trie
 * @return the number of strings in this trie
 */
size_t
arraytrie_size(ArrayTrie* trie)
{
  return -1;
}

