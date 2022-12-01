internal int32
tests_ternarytrie_basic(TestUtilsState *testutilsstate)
{
	struct ttrie *tst = ternarytrie_init();
  	testutilsstate->cleanupargs = (void *)tst;
  	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

  	TestUtils_Assert(ternarytrie_add(tst, "IS"));
  	TestUtils_Assert(ternarytrie_add(tst, "AL"));
  	TestUtils_Assert(ternarytrie_add(tst, "ZO"));
  	TestUtils_Assert(ternarytrie_size(tst) == 3 );


  	TestUtils_Assert(ternarytrie_search(tst, "IS"));
  	TestUtils_Assert(ternarytrie_search(tst, "AL"));
  	TestUtils_Assert(ternarytrie_search(tst, "ZO"));

  	TestUtils_Assert(ternarytrie_remove(tst, "ZO"));
  	TestUtils_Assert(ternarytrie_search(tst, "IS"));
  	TestUtils_Assert(ternarytrie_search(tst, "AL"));
  	TestUtils_Assert(!ternarytrie_search(tst, "ZO"));
  	TestUtils_Assert(ternarytrie_size(tst) == 2);

  	TestUtils_Assert(ternarytrie_add(tst, "ZO"));
  	TestUtils_Assert(ternarytrie_search(tst, "ZO"));
  	TestUtils_Assert(ternarytrie_size(tst) == 3);

  	ternarytrie_free(tst);
  	return 0;
}

internal int32
tests_ternarytrie_init(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	TestUtils_Assert(tst != 0x0);
    	TestUtils_Assert(tst->wc == 0);

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_add_one(TestUtilsState *testutilsstate) {
	struct ttrie * tst = ternarytrie_init();
    	TestUtils_Assert(tst != 0x0);
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	const char* string = "this is a test";
    	TestUtils_Assert(ternarytrie_add(tst, string));
    	TestUtils_Assert(ternarytrie_search(tst, string));
    	TestUtils_Assert(tst->wc == 1);

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_search_not_present(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
    	TestUtils_Assert(tst);
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	TestUtils_Assert(ternarytrie_add(tst, "this string exists"));
    	TestUtils_Assert(!ternarytrie_search(tst, "this string does not exist"));

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_add_more(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
    	TestUtils_Assert(tst != NULL);
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	const char* one = "one";
    	const char* two = "two";
    	const char* twenty = "twenty";
    	const char* twentytwo = "twentytwo";

    	TestUtils_Assert(ternarytrie_add(tst, one));
    	TestUtils_Assert(ternarytrie_add(tst, two));
    	TestUtils_Assert(ternarytrie_add(tst, twenty));
    	TestUtils_Assert(ternarytrie_add(tst, twentytwo));

    	TestUtils_Assert(tst->wc == 4);

    	TestUtils_Assert(ternarytrie_search(tst, one));
    	TestUtils_Assert(ternarytrie_search(tst, two));
    	TestUtils_Assert(ternarytrie_search(tst, twenty));
    	TestUtils_Assert(ternarytrie_search(tst, twentytwo));

    	TestUtils_Assert(!ternarytrie_add(tst, one));
    	TestUtils_Assert(!ternarytrie_add(tst, two));
    	TestUtils_Assert(!ternarytrie_add(tst, twenty));
    	TestUtils_Assert(!ternarytrie_add(tst, twentytwo));

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_remove_one(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
    	TestUtils_Assert(tst != NULL);
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	const char* string = "this is a test";
    	TestUtils_Assert(ternarytrie_add(tst, string));
    	TestUtils_Assert(tst->wc == 1);

    	TestUtils_Assert(ternarytrie_remove(tst, string));
    	TestUtils_Assert(tst->wc == 0);

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_remove_more(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
    	TestUtils_Assert(tst != NULL);
    	testutilsstate->cleanupargs = (void *)tst;
    	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	const char* one = "one";
    	const char* two = "two";
    	const char* twenty = "twenty";
    	const char* twentytwo = "twentytwo";

    	TestUtils_Assert(ternarytrie_add(tst, one));
    	TestUtils_Assert(ternarytrie_add(tst, two));
    	TestUtils_Assert(ternarytrie_add(tst, twenty));
    	TestUtils_Assert(ternarytrie_add(tst, twentytwo));

    	TestUtils_Assert(tst->wc == 4);

    	TestUtils_Assert(ternarytrie_remove(tst, one));
    	TestUtils_Assert(ternarytrie_remove(tst, two));
    	TestUtils_Assert(ternarytrie_search(tst, two) == false);
    	TestUtils_Assert(ternarytrie_remove(tst, twenty));
    	TestUtils_Assert(ternarytrie_search(tst, twenty) == false);
    	TestUtils_Assert(ternarytrie_remove(tst, twentytwo));

    	TestUtils_Assert(tst->wc == 0);

    	ternarytrie_free(tst);
    	return 0;
}

internal int32
tests_ternarytrie_remove_not_present(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
  	TestUtils_Assert(tst);
  	testutilsstate->cleanupargs = (void *)tst;
  	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

  	TestUtils_Assert(ternarytrie_add(tst, "this string exists"));
  	TestUtils_Assert(!ternarytrie_remove(tst, "this string does not exist"));

  	ternarytrie_free(tst);
  	return 0;
}

internal int32
tests_ternarytrie_print(TestUtilsState *testutilsstate) {
	struct ttrie *tst = ternarytrie_init();
  	TestUtils_Assert(tst);
  	testutilsstate->cleanupargs = (void *)tst;
  	testutilsstate->cleanup     = (void (*)(void *))ternarytrie_free;

    	const char* one = "one";
    	const char* two = "two";
    	const char* twenty = "twenty";
    	const char* twentytwo = "twentytwo";

    	TestUtils_Assert(ternarytrie_add(tst, one));
    	TestUtils_Assert(ternarytrie_add(tst, two));
    	TestUtils_Assert(ternarytrie_add(tst, twenty));
    	TestUtils_Assert(ternarytrie_add(tst, twentytwo));

    	TestUtils_Assert(tst->wc == 4);

	printf("\n");
	ternarytrie_print(stdout, tst);

  	ternarytrie_free(tst);
  	return 0;
}


global_variable TestUtilsTest tests_ternarytrie[] = {
	/* TestUtils_Make_Test(tests_ternarytrie_print), */
	TestUtils_Make_Test(tests_ternarytrie_basic),
  	TestUtils_Make_Test(tests_ternarytrie_init),
  	TestUtils_Make_Test(tests_ternarytrie_add_one),
  	TestUtils_Make_Test(tests_ternarytrie_search_not_present),
	TestUtils_Make_Test(tests_ternarytrie_add_more),
	TestUtils_Make_Test(tests_ternarytrie_remove_one),
	TestUtils_Make_Test(tests_ternarytrie_remove_more),
	TestUtils_Make_Test(tests_ternarytrie_remove_not_present),
};
