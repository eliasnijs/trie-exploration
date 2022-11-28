/* depends on:
 * stdio.h, stdlib.h, base.h, stdint.h */

/* Implementation of an Array Trie Datastructure, more specifically a Patricia
 * Trie. The rationale and specifics of this structure can be found in the
 * following paper:
 *
 * Morrison, D. R. (1968). PATRICIA—practical algorithm to retrieve information
 * coded in alphanumeric. Journal of the ACM (JACM), 15(4), 514-534.
 *
 * */

/* enumerations, structs, unions */
struct atrie_node {
	char *s;
	size_t skip;
	struct atrie_node *next[ARRAYTRIE_ALPHASIZE];
};

struct atrie {
	size_t wc;
	struct atrie_node *root;
};

/* function definitions */
struct atrie * arraytrie_init();
void arraytrie_free(struct atrie *at);
bool8 arraytrie_add(struct atrie *at, const char *s);
bool8 arraytrie_search(struct atrie *at, const char *s);
bool8 arraytrie_remove(struct atrie *at, const char* s);
size_t arraytrie_size(struct atrie *trie);
internal void _arraytrie_free(struct atrie_node *n);
internal bool8 _arraytrie_remove(struct atrie_node **n, const char *s, int32 l,
				 int32 s_i, bool8 *is_success);

/* function implementations */
struct atrie *
arraytrie_init()
{
	struct atrie *at = (struct atrie *)calloc(1, sizeof(struct atrie));
	at->wc = 0;
	at->root = (struct atrie_node *)calloc(1, sizeof(struct atrie_node));
	return at;
}

internal void
_arraytrie_free(struct atrie_node *n)
{
	for (int32 i = 0; i < ARRAYTRIE_ALPHASIZE; ++i) {
		if (n->next[i]) {
			_arraytrie_free(n->next[i]);
		}
	}
	if (n->s) {
		free(n->s);
	}
	free(n);
}

void
arraytrie_free(struct atrie *at)
{
	_arraytrie_free(at->root);
	free(at);
}

bool8
arraytrie_search(struct atrie *at, const char *s)
{
	int32 m = strlen(s), s_i = 0;
	struct atrie_node *n = at->root;
	while (!n->s) {
		s_i += n->skip;
		n = n->next[(int8)s[s_i]];
		if (s_i > m || !n) {
			return false;
		}
		++s_i;
	}
	return (strcmp(n->s, s) == 0);
}

bool8
arraytrie_add(struct atrie *at, const char *s)
{
	int32 m = strlen(s), s_i = 0;
	struct atrie_node **n = &at->root;
	while (s[s_i]) {
		if (!*n) {
			*n = (struct atrie_node *)calloc(1,
				sizeof(struct atrie_node));
	    		(*n)->s = (char *)calloc(m + 1, sizeof(char));
	    		strcpy((*n)->s, s);
	    		++at->wc;
	    		return true;
		}
		s_i += (*n)->skip;
	  	if (!s[s_i]) {
			return false;
		}
	  	if ((*n)->s) {
			int32 s_i_start = s_i;
			while (s[s_i] == (*n)->s[s_i]
			       && s[s_i] && (*n)->s[s_i])  {
				++s_i;
			}
			if (!s[s_i] && !(*n)->s[s_i]) {
				return false;
			}
			int32 diff = s_i - s_i_start;
			struct atrie_node *n_new = (struct atrie_node *)calloc(
			    1, sizeof(struct atrie_node));
			n_new->skip = diff;
			n_new->next[(int8)((*n)->s[s_i])] = *n;
			*n = n_new;
	  	}
	  	n = &(*n)->next[(int8)s[s_i]];
	  	++s_i;
	}
	return false;
}

internal bool8
_arraytrie_remove(struct atrie_node **n, const char *s, int32 l, int32 s_i,
		  bool8 *is_success)
{
	if (s_i > l + 1 || !(*n)) {
		return false;
	}
	if ((*n)->s) {
		if (strcmp((*n)->s, s) == 0) {
			free((*n)->s);
			free(*n);
			*n = 0;
			*is_success = true;
			return true;
		} else {
			return false;
		}
	} else {
		s_i += (*n)->skip;
		bool8 is_rm = _arraytrie_remove(&(*n)->next[(int8)s[s_i]],
						s, l, s_i + 1, is_success);
		/* TODO (Elias): join nodes / rebalancing */
		bool8 is_zero_buf = true;
		for (uint8 i = 0; i < ARRAYTRIE_ALPHASIZE && is_zero_buf; ++i) {
			is_zero_buf = (*n)->next[i] == 0x0;
		}
		if (is_zero_buf) {
			return true;
		}
	}
	return false;
}

bool8
arraytrie_remove(struct atrie *at, const char* s)
{
	bool8 is_success = false;
	_arraytrie_remove(&at->root, s, strlen(s), 0, &is_success);
	if (is_success) {
		--at->wc;
	}
	return is_success;
}

size_t
arraytrie_size(struct atrie *trie)
{
	return trie->wc;
}
