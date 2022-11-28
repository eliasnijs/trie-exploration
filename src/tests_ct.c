internal int32
tests_customtrie_init(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;
	TestUtils_Assert(ct->wc == 0);
	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_add_one(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	const char* string = "this is a test";
	TestUtils_Assert(customtrie_add(ct, string));
	TestUtils_Assert(customtrie_search(ct, string));
	TestUtils_Assert(ct->wc == 1);
	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_search_not_present(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	TestUtils_Assert(customtrie_add(ct, "this string exists"));
	TestUtils_Assert(!customtrie_search(ct, "this string does not exist"));
	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_add_more(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	const char* tomorrow = "tomorow";

	TestUtils_Assert(customtrie_add(ct, one));
	TestUtils_Assert(customtrie_add(ct, two));
	TestUtils_Assert(customtrie_add(ct, twenty));
	TestUtils_Assert(customtrie_add(ct, twentytwo));
	TestUtils_Assert(customtrie_add(ct, tomorrow));

	TestUtils_Assert(ct->wc == 5);

	TestUtils_Assert(customtrie_search(ct, one));
	TestUtils_Assert(customtrie_search(ct, two));
	TestUtils_Assert(customtrie_search(ct, twenty));
	TestUtils_Assert(customtrie_search(ct, twentytwo));
	TestUtils_Assert(customtrie_search(ct, tomorrow));

	TestUtils_Assert(!customtrie_add(ct, one));
	TestUtils_Assert(!customtrie_add(ct, two));
	TestUtils_Assert(!customtrie_add(ct, twenty));
	TestUtils_Assert(!customtrie_add(ct, twentytwo));
	TestUtils_Assert(!customtrie_add(ct, tomorrow));

	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_remove_one(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	const char* string = "this is a test";
	TestUtils_Assert(customtrie_add(ct, string));
	TestUtils_Assert(ct->wc == 1);

	TestUtils_Assert(customtrie_remove(ct, string));
	TestUtils_Assert(ct->wc == 0);

	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_remove_more(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	TestUtils_Assert(customtrie_add(ct, one));
	TestUtils_Assert(customtrie_add(ct, two));
	TestUtils_Assert(customtrie_add(ct, twenty));
	TestUtils_Assert(customtrie_add(ct, twentytwo));

	TestUtils_Assert(ct->wc == 4);

	TestUtils_Assert(customtrie_remove(ct, one));
	TestUtils_Assert(customtrie_remove(ct, two));
	TestUtils_Assert(customtrie_remove(ct, twenty));
	TestUtils_Assert(customtrie_remove(ct, twentytwo));

	TestUtils_Assert(ct->wc == 0);

	customtrie_free(ct);
	return 0;
}

internal int32
tests_customtrie_remove_not_present(TestUtilsState *testutilsstate)
{
	struct ctrie* ct = customtrie_init();
	TestUtils_Assert(ct != NULL);
	testutilsstate->cleanupargs = (void *)ct;
	testutilsstate->cleanup     = (void (*)(void *))customtrie_free;

	TestUtils_Assert(customtrie_add(ct, "this string exists"));
	TestUtils_Assert(!customtrie_remove(ct, "this string does not exist"));

	customtrie_free(ct);
	return 0;
}

global_variable TestUtilsTest tests_customtrie[] = {
	TestUtils_Make_Test(tests_customtrie_init),
	TestUtils_Make_Test(tests_customtrie_add_one),
	TestUtils_Make_Test(tests_customtrie_search_not_present),
	TestUtils_Make_Test(tests_customtrie_add_more),
	TestUtils_Make_Test(tests_customtrie_remove_one),
	TestUtils_Make_Test(tests_customtrie_remove_more),
	TestUtils_Make_Test(tests_customtrie_remove_not_present),
};
