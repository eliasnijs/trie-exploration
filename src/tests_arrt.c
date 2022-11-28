internal int32
tests_arraytrie_init(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;
	TestUtils_Assert(ct->wc == 0);
	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_add_one(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	const char* string = "this is a test";
	TestUtils_Assert(arraytrie_add(ct, string));
	TestUtils_Assert(arraytrie_search(ct, string));
	TestUtils_Assert(ct->wc == 1);
	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_search_not_present(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	TestUtils_Assert(arraytrie_add(ct, "this string exists"));
	TestUtils_Assert(!arraytrie_search(ct, "this string does not exist"));
	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_add_more(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	const char* tomorrow = "tomorow";

	TestUtils_Assert(arraytrie_add(ct, one));
	TestUtils_Assert(arraytrie_add(ct, two));
	TestUtils_Assert(arraytrie_add(ct, twenty));
	TestUtils_Assert(arraytrie_add(ct, twentytwo));
	TestUtils_Assert(arraytrie_add(ct, tomorrow));

	TestUtils_Assert(ct->wc == 5);

	TestUtils_Assert(arraytrie_search(ct, one));
	TestUtils_Assert(arraytrie_search(ct, two));
	TestUtils_Assert(arraytrie_search(ct, twenty));
	TestUtils_Assert(arraytrie_search(ct, twentytwo));
	TestUtils_Assert(arraytrie_search(ct, tomorrow));

	TestUtils_Assert(!arraytrie_add(ct, one));
	TestUtils_Assert(!arraytrie_add(ct, two));
	TestUtils_Assert(!arraytrie_add(ct, twenty));
	TestUtils_Assert(!arraytrie_add(ct, twentytwo));
	TestUtils_Assert(!arraytrie_add(ct, tomorrow));

	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_remove_one(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	const char* string = "this is a test";
	TestUtils_Assert(arraytrie_add(ct, string));
	TestUtils_Assert(ct->wc == 1);

	TestUtils_Assert(arraytrie_remove(ct, string));
	TestUtils_Assert(ct->wc == 0);

	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_remove_more(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	TestUtils_Assert(arraytrie_add(ct, one));
	TestUtils_Assert(arraytrie_add(ct, two));
	TestUtils_Assert(arraytrie_add(ct, twenty));
	TestUtils_Assert(arraytrie_add(ct, twentytwo));

	TestUtils_Assert(ct->wc == 4);
	TestUtils_Assert(arraytrie_remove(ct, one));
	TestUtils_Assert(arraytrie_remove(ct, two));
	TestUtils_Assert(arraytrie_remove(ct, twenty));
	TestUtils_Assert(arraytrie_remove(ct, twentytwo));

	TestUtils_Assert(ct->wc == 0);

	arraytrie_free(ct);
	return 0;
}

internal int32
tests_arraytrie_remove_not_present(TestUtilsState *testutilsstate)
{
	struct atrie* ct = arraytrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))arraytrie_free;

	TestUtils_Assert(arraytrie_add(ct, "this string exists"));
	TestUtils_Assert(!arraytrie_remove(ct, "this string does not exist"));

	arraytrie_free(ct);
	return 0;
}

global_variable TestUtilsTest tests_arraytrie[] = {
	TestUtils_Make_Test(tests_arraytrie_init),
	TestUtils_Make_Test(tests_arraytrie_add_one),
	TestUtils_Make_Test(tests_arraytrie_search_not_present),
	TestUtils_Make_Test(tests_arraytrie_add_more),
	TestUtils_Make_Test(tests_arraytrie_remove_one),
	TestUtils_Make_Test(tests_arraytrie_remove_more),
	TestUtils_Make_Test(tests_arraytrie_remove_not_present),
};
