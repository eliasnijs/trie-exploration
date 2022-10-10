#include "test.h"
#include "arraytrie.h"

#define TEST_SIZE(ct, size) \
    TEST_CHECK(arraytrie_size(ct) == size); \
    TEST_MSG("Size: %zu", arraytrie_size(ct))
                                \
void test_init() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);
    TEST_SIZE(ct, 0);
    arraytrie_free(ct);
}

void test_add_one() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    const char* string = "this is a test";
    TEST_CHECK(arraytrie_add(ct, string));
    TEST_CHECK(arraytrie_search(ct, string));
    TEST_SIZE(ct, 1);
    arraytrie_free(ct);
}

void test_search_not_present() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    TEST_CHECK(arraytrie_add(ct, "this string exists"));
    TEST_CHECK(!arraytrie_search(ct, "this string does not exist"));
    arraytrie_free(ct);
}

void test_add_more() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    const char* one = "one";
    const char* two = "two";
    const char* twenty = "twenty";
    const char* twentytwo = "twentytwo";

    TEST_CHECK(arraytrie_add(ct, one));
    TEST_CHECK(arraytrie_add(ct, two));
    TEST_CHECK(arraytrie_add(ct, twenty));
    TEST_CHECK(arraytrie_add(ct, twentytwo));

    TEST_SIZE(ct, 4);

    TEST_CHECK(arraytrie_search(ct, one));
    TEST_CHECK(arraytrie_search(ct, two));
    TEST_CHECK(arraytrie_search(ct, twenty));
    TEST_CHECK(arraytrie_search(ct, twentytwo));

    TEST_CHECK(!arraytrie_add(ct, one));
    TEST_CHECK(!arraytrie_add(ct, two));
    TEST_CHECK(!arraytrie_add(ct, twenty));
    TEST_CHECK(!arraytrie_add(ct, twentytwo));

    arraytrie_free(ct);
}

void test_remove_one() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    const char* string = "this is a test";
    TEST_CHECK(arraytrie_add(ct, string));
    TEST_SIZE(ct, 1);

    TEST_CHECK(arraytrie_remove(ct, string));
    TEST_SIZE(ct, 0);

    arraytrie_free(ct);
}

void test_remove_more() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    const char* one = "one";
    const char* two = "two";
    const char* twenty = "twenty";
    const char* twentytwo = "twentytwo";
    TEST_CHECK(arraytrie_add(ct, one));
    TEST_CHECK(arraytrie_add(ct, two));
    TEST_CHECK(arraytrie_add(ct, twenty));
    TEST_CHECK(arraytrie_add(ct, twentytwo));

    TEST_SIZE(ct, 4);

    TEST_CHECK(arraytrie_remove(ct, one));
    TEST_CHECK(arraytrie_remove(ct, two));
    TEST_CHECK(arraytrie_remove(ct, twenty));
    TEST_CHECK(arraytrie_remove(ct, twentytwo));

    TEST_SIZE(ct, 0);

    arraytrie_free(ct);
}

void test_remove_not_present() {
    ArrayTrie* ct = arraytrie_init();
    TEST_CHECK(ct != NULL);

    TEST_CHECK(arraytrie_add(ct, "this string exists"));
    TEST_CHECK(!arraytrie_remove(ct, "this string does not exist"));

    arraytrie_free(ct);
}

TEST_LIST = {
        {"arraytrie init",test_init },
        { "arraytrie add one",test_add_one },
        { "arraytrie add more",test_add_more },
        { "arraytrie search not present",test_search_not_present},

        { "arraytrie remove one",test_remove_one },
        { "arraytrie remove more",test_remove_more },
        { "arraytrie remove not present",test_remove_not_present},
        { NULL, NULL}
};
