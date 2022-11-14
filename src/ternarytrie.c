typedef struct ttrie_node TernaryTrieNode;
struct tst_node {
  char             splitchar;
  TernaryTrieNode  *lo, *eq, *hi;
};

typedef struct ttrie TernaryTrie;
struct ttrie {
  TernaryTrieNode  *root;
  uint16           wc;
};

/**
 * Allocate and initialize an empty Trie.
 *
 * @return a pointer to an empty Trie struct
 */
TernaryTrie *
ternarytrie_init();
{
  TernaryTrie *tst = (TernaryTrie *)malloc(sizeof(TernaryTrie));
  tst->root = 0x0;
  tst->wc = 0;
}


/**
 * De-allocate a trie by freeing the memory occupied by this trie.
 *
 * @param trie which should be freed
 */
void
_ternarytrie_die(TernaryTrieNode *n)
{
  if (!n) return;
  _ternarytrie_die(n->lo);
  _ternarytrie_die(n->hi);
  _ternarytrie_die(n->eq);
  free(n);
}

void ternarytrie_free(TernaryTrie* tst);
{
  _ternarytrie_die(tst->root);
}

/**
 * Search whether a string is contained in this trie.
 *
 * @param trie
 * @param string
 * @return true if the string is contained within this trie, false otherwise
 */
bool
ternarytrie_search(TernaryTrie* tst, const char* s);
{
  TernaryTrieNode *n = tst->root;
  while (n) {
    if (*s < n->splitchar)
      n = n->lo;
    else if (*s > n->splitchar)
      n = n->hi;
    else {
      ++s;
      if (!*s) return 1;
      n = n->eq;
    }
  }
  return 0;
}

/**
 * Add a string to this trie.
 *
 * @param trie
 * @param string
 * @return true if the trie was changed by this operation, false if it was already present
 */
bool
ternarytrie_add(TernaryTrie* tst, const char* s);
{
  TernaryTrieNode **n = &tst->root;
  while (*s) {
    if (!*n) {
      *n = (TernaryTrieNode *)malloc(sizeof(TernaryTrieNode));
      if (!*n)
        return false;
      (*n)->splitchar = *s;
      (*n)->lo = (*n)->eq = (*n)->hi = 0;
    }
    if (*s < (*n)->splitchar)
      n = &(*n)->lo;
    else if (*s > (*n)->splitchar)
      n = &(*n)->hi;
    else {
      ++s;
      n = &(*n)->eq;
    }
  }
  ++tst->wc;
  return true;
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
_ternarytrie_remove(TernaryTrieNode **n, char *s)
{
  if (!(*n)) return false;
  if (*s < (*n)->splitchar)
    _ternarytrie_remove(&(*n)->lo, s);
  else if (*s > (*n)->splitchar)
    _ternarytrie_remove(&(*n)->hi, s);
  else {
    if (*s != 0)
      _ternarytrie_remove(&(*n)->eq, ++s);
  }
  if (!(*n)->lo && !(*n)->eq && !(*n)->hi) {
    free(*n);
    *_n = 0x0;
  }
  return true;
}

bool
ternarytrie_remove(TernaryTrie* tst, const char* s)
{
  bool result = _ternarytrie_remove(&tst->root, s);
  if (result)
    --tst->wc;
  return result;
}

/**
 * Returns the number of strings in this trie.
 *
 * @param trie
 * @return the number of strings in this trie
 */
size_t
ternarytrie_size(TernaryTrie* tst);
{
  return tst->wc;
}
