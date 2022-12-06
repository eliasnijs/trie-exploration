#ifndef AD3_TERNARYTRIE
#define AD3_TERNARYTRIE

/**
 * The implementation of a Ternary Trie.
 *
 * Each node should be represented by a binary tree in order to reduce the memory usage.
 */

#include <stdbool.h>
#include <stddef.h>

/**
 * Type definition for the struct representing the current Trie.
 *
 * You can (and should) redefine this in your c-file with the concrete fields.
 */
typedef struct ttrie TernaryTrie;

/**
 * Allocate and initialize an empty Trie.
 *
 * @return a pointer to an empty Trie struct
 */
TernaryTrie* ternarytrie_init();

/**
 * Allocate and initialize an empty Trie with initial memory size.
 *
 * @param initial memory size
 * @return a pointer to an empty Trie struct
 */
TernaryTrie* ternarytrie_init_wmem(size_t backbufferlen);

/**
 * De-allocate a trie by freeing the memory occupied by this trie.
 *
 * @param trie which should be freed
 */
void ternarytrie_free(TernaryTrie* trie);

/**
 * Print a a trie to the given file
 *
 * @param file
 * @param trie
 */
void ternarytrie_print(FILE *f, struct ttrie *at);

/**
 * Search whether a string is contained in this trie.
 *
 * @param trie
 * @param string
 * @return true if the string is contained within this trie, false otherwise
 */
bool ternarytrie_search(TernaryTrie* trie, const char* string);

/**
 * Add a string to this trie.
 *
 * @param trie
 * @param string
 * @return true if the trie was changed by this operation, false if it was already present
 */
bool ternarytrie_add(TernaryTrie* trie, const char* string);

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
bool ternarytrie_remove(TernaryTrie* trie, const char* string);

/**
 * Returns the number of strings in this trie.
 *
 * @param trie
 * @return the number of strings in this trie
 */
size_t ternarytrie_size(TernaryTrie* trie);

#endif //AD3_TERNARYTRIE
