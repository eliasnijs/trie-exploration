#ifndef AD3_ARRAYTRIE
#define AD3_ARRAYTRIE

/**
 * The implementation of a Patricia Trie.
 *
 * This defines the implementation of a Patricia Trie where the nodes contain arrays to their children.
 * Paths should also be "compacted": if all children of a node have a common prefix, this prefix can be skipped.
 */

#include <stdbool.h>
#include <stddef.h>

/**
 * Type definition for the struct representing the current Trie.
 *
 * You can (and should) redefine this in your c-file with the concrete fields.
 */
typedef struct atrie ArrayTrie;

/**
 * Allocate and initialize an empty Trie.
 *
 * @return a pointer to an empty Trie struct
 */
ArrayTrie* arraytrie_init();

/**
 * De-allocate a trie by freeing the memory occupied by this trie.
 *
 * @param trie which should be freed
 */
void arraytrie_free(ArrayTrie* trie);

/**
 * Search whether a string is contained in this trie.
 *
 * @param trie
 * @param string
 * @return true if the string is contained within this trie, false otherwise
 */
bool arraytrie_search(ArrayTrie* trie, const char* string);

/**
 * Add a string to this trie.
 *
 * @param trie
 * @param string
 * @return true if the trie was changed by this operation, false if it was already present
 */
bool arraytrie_add(ArrayTrie* trie, const char* string);

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
bool arraytrie_remove(ArrayTrie* trie, const char* string);

/**
 * Returns the number of strings in this trie.
 *
 * @param trie
 * @return the number of strings in this trie
 */
size_t arraytrie_size(ArrayTrie* trie);

#endif //AD3_ARRAYTRIE
