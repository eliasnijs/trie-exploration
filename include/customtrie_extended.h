#ifndef AD3_CUSTOMTRIE
#define AD3_CUSTOMTRIE

/**
 * The implementation of a Custom Trie.
 *
 * The only requirement for this trie is that while performing operations on this tree, only one character of the string
 * can be compared per node of the trie.
 */


#include <stdbool.h>
#include <stddef.h>

/**
 * Type definition for the struct representing the current Trie.
 *
 * You can (and should) redefine this in your c-file with the concrete fields.
 */
typedef struct ctrie CustomTrie;

/**
 * Allocate and initialize an empty Trie.
 *
 * @return a pointer to an empty Trie struct
 */
CustomTrie* customtrie_init();

/**
 * Allocate and initialize an empty Trie with initial memory size.
 *
 * @param initial memory size
 * @return a pointer to an empty Trie struct
 */
CustomTrie* customtrie_init_wmem(size_t backbufferlen);

/**
 * De-allocate a trie by freeing the memory occupied by this trie.
 *
 * @param trie which should be freed
 */
void customtrie_free(CustomTrie* trie);

/**
 * Print a a trie to the given file
 *
 * @param file
 * @param trie
 */
void customtrie_print(FILE *f, struct ctrie *at);

/**
 * Search whether a string is contained in this trie.
 *
 * @param trie
 * @param string
 * @return true if the string is contained within this trie, false otherwise
 */
bool customtrie_search(CustomTrie* trie, const char* string);

/**
 * Add a string to this trie.
 *
 * @param trie
 * @param string
 * @return true if the trie was changed by this operation, false if it was already present
 */
bool customtrie_add(CustomTrie* trie, const char* string);

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
bool customtrie_remove(CustomTrie* trie, const char* string);

/**
 * Returns the number of strings in this trie.
 *
 * @param trie
 * @return the number of strings in this trie
 */
size_t customtrie_size(CustomTrie* trie);

#endif //AD3_CUSTOMTRIE
