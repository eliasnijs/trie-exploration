/* Configuration */
global_variable struct trie TestsTrieModel = {0};

/* Helpers */
struct trie_and_dataset {
	struct trie *at;
	struct dataset *ds;
};

internal void
free_trie_and_dataset(struct trie_and_dataset *args)
{
	trie_free(args->at);
	dataset_die(args->ds);
}

/* Tests */
internal int32
tests_trie_init(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;
	TestUtils_Assert(trie_size(&trie) == 0);
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_one(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* string = "this is a test";
	TestUtils_Assert(trie_add(&trie, string));
	TestUtils_Assert(trie_search(&trie, string));
	TestUtils_Assert(trie_size(&trie) == 1);
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_two(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* string = "Town";
	const char* string2 = "Tomorrow";
	TestUtils_Assert(trie_add(&trie, string));
	TestUtils_Assert(trie_add(&trie, string2));
	TestUtils_Assert(trie_search(&trie, string));
	TestUtils_Assert(trie_search(&trie, string2));
	TestUtils_Assert(trie_size(&trie) == 2);
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_three(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* s1 = "Twenty";
	const char* s2 = "Twentytwo";
	const char* s3 = "Twenly";
	TestUtils_Assert(trie_add(&trie, s1));
	TestUtils_Assert(trie_add(&trie, s2));
	TestUtils_Assert(trie_add(&trie, s3));
	TestUtils_Assert(trie_size(&trie) == 3);
	TestUtils_Assert(trie_search(&trie, s1));
	TestUtils_Assert(trie_search(&trie, s2));
	TestUtils_Assert(trie_search(&trie, s3));
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_three_2(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* s1 = "Twenty";
	const char* s2 = "Twentytwo";
	const char* s3 = "Two";
	TestUtils_Assert(trie_add(&trie, s1));
	TestUtils_Assert(trie_add(&trie, s2));
	TestUtils_Assert(trie_add(&trie, s3));
	TestUtils_Assert(trie_size(&trie) == 3);
	TestUtils_Assert(trie_search(&trie, s1));
	TestUtils_Assert(trie_search(&trie, s2));
	TestUtils_Assert(trie_search(&trie, s3));
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_two_2(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* string = "this is a test";
	const char* string2 = "Hello World!";
	TestUtils_Assert(trie_add(&trie, string));
	TestUtils_Assert(trie_add(&trie, string2));
	TestUtils_Assert(trie_search(&trie, string));
	TestUtils_Assert(trie_search(&trie, string2));
	TestUtils_Assert(trie_size(&trie) == 2);
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_already_present(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* string = "this is a test";
	const char* string2 = "this is a test";
	TestUtils_Assert(trie_add(&trie, string));
	TestUtils_Assert(trie_search(&trie, string));
	TestUtils_Assert(trie_size(&trie) == 1);
	TestUtils_Assert(!trie_add(&trie, string));
	TestUtils_Assert(trie_search(&trie, string2));
	TestUtils_Assert(trie_size(&trie) == 1);
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_search_not_present(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	TestUtils_Assert(trie_add(&trie, "this string exists"));
	TestUtils_Assert(!trie_search(&trie, "this string does not exist"));
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_more(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	const char* tomorrow = "tomorow";

	TestUtils_Assert(trie_add(&trie, one));
	TestUtils_Assert(trie_add(&trie, two));
	TestUtils_Assert(trie_add(&trie, twenty));
	TestUtils_Assert(trie_add(&trie, twentytwo));
	TestUtils_Assert(trie_add(&trie, tomorrow));

	TestUtils_Assert(trie_size(&trie) == 5);

	TestUtils_Assert(trie_search(&trie, one));
	TestUtils_Assert(trie_search(&trie, two));
	TestUtils_Assert(trie_search(&trie, twenty));
	TestUtils_Assert(trie_search(&trie, twentytwo));
	TestUtils_Assert(trie_search(&trie, tomorrow));

	TestUtils_Assert(!trie_add(&trie, one));
	TestUtils_Assert(!trie_add(&trie, two));
	TestUtils_Assert(!trie_add(&trie, twenty));
	TestUtils_Assert(!trie_add(&trie, twentytwo));
	TestUtils_Assert(!trie_add(&trie, tomorrow));

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_remove_one(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* string = "this is a test";
	TestUtils_Assert(trie_add(&trie, string));
	TestUtils_Assert(trie_size(&trie) == 1);

	TestUtils_Assert(trie_remove(&trie, string));
	TestUtils_Assert(trie_size(&trie) == 0);

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_remove_more(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	const char* one = "one";
	const char* two = "two";
	const char* twenty = "twenty";
	const char* twentytwo = "twentytwo";
	TestUtils_Assert(trie_add(&trie, one));
	TestUtils_Assert(trie_add(&trie, two));
	TestUtils_Assert(trie_add(&trie, twenty));
	TestUtils_Assert(trie_add(&trie, twentytwo));

	TestUtils_Assert(trie_size(&trie) == 4);
	TestUtils_Assert(trie_remove(&trie, one));
	TestUtils_Assert(trie_remove(&trie, two));
	TestUtils_Assert(trie_remove(&trie, twenty));
	TestUtils_Assert(trie_remove(&trie, twentytwo));

	TestUtils_Assert(trie_size(&trie) == 0);

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_remove_not_present(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	TestUtils_Assert(trie_add(&trie, "this string exists"));
	TestUtils_Assert(!trie_remove(&trie, "this string does not exist"));

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_print(TestUtilsState *testutilsstate) {
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

    	const char* one = "one";
    	const char* two = "two";
    	const char* twenty = "twenty";
    	const char* twentytwo = "twentytwo";

    	TestUtils_Assert(trie_add(&trie, one));
    	TestUtils_Assert(trie_add(&trie, two));
    	TestUtils_Assert(trie_add(&trie, twenty));
    	TestUtils_Assert(trie_add(&trie, twentytwo));

    	TestUtils_Assert(trie_size(&trie) == 4);

	printf("\n");
	trie_print(&trie, stdout);

  	trie_free(&trie);
  	return 0;
}

internal int32
tests_trie_add_more2(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	TestUtils_Assert(trie_add(&trie, "one"));
	TestUtils_Assert(trie_add(&trie, "two"));
	TestUtils_Assert(trie_add(&trie, "twenty"));
	TestUtils_Assert(trie_add(&trie, "twentytwo"));
	TestUtils_Assert(trie_add(&trie, "throne"));
	TestUtils_Assert(trie_add(&trie, "twenly"));
	TestUtils_Assert(trie_size(&trie) == 6);
	TestUtils_Assert(trie_search(&trie, "twenly"));

  	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_more3(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	TestUtils_Assert(trie_add(&trie, "one"));
	TestUtils_Assert(trie_add(&trie, "two"));
	TestUtils_Assert(trie_add(&trie, "twenty"));
	TestUtils_Assert(trie_add(&trie, "twenly"));
	TestUtils_Assert(trie_add(&trie, "twentytwo"));
	TestUtils_Assert(trie_add(&trie, "throne"));
	TestUtils_Assert(trie_size(&trie) == 6);
	TestUtils_Assert(trie_search(&trie, "twenly"));

  	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_afbyrm(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	struct dataset ds;
	dataset_file_load("resources/words.txt", &ds);
	struct trie_and_dataset trie_ds = {&trie, &ds};
  	testutilsstate->cleanupargs = (void *)&trie_ds;
  	testutilsstate->cleanup     = (void (*)(void *))free_trie_and_dataset;

	shuffle_ptr((void **)ds.words, ds.wordcount);
	int32 count = ds.wordcount;
	count = 10;
	printf("checking add: \n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(trie_add(&trie, ds.words[i]));
		if (trie_size(&trie) != i + 1) {
			DebugLogError("%20s %10d", ds.words[i], i);
		}
	}
	trie_print(&trie,stdout);
	DebugLogInt(trie_size(&trie));
	DebugLogInt(ds.wordcount);
	printf("checking search: \n");
	for (uint32 i = 0; i < count; ++i) {
		if (!trie_search(&trie, ds.words[i])) {
			DebugLogError("%20s %10d", ds.words[i], i);
		}
	}
	printf("checking second add: \n");
	for (uint32 i = 0; i < count; ++i) {
		if (trie_add(&trie, ds.words[i])) {
			DebugLogError("%20s %10d", ds.words[i], i);
		}
	}
	/* printf("checking remove: \n"); */
	/* for (uint32 i = 0; i < count; ++i) { */
	/* 	if (!trie_remove(&trie, ds.words[i])) { */
	/* 		DebugLogError("remove: %s", ds.words[i]); */
	/* 	} */
	/* } */
	/* printf("checking search after remove: \n"); */
	/* for (uint32 i = 0; i < count; ++i) { */
	/* 	if (trie_search(&trie, ds.words[i])) { */
	/* 		DebugLogError("second search: %s", ds.words[i]); */
	/* 	} */
	/* } */
	dataset_die(&ds);
  	trie_free(&trie);
	return 0;
}

global_variable TestUtilsTest tests_trie[] = {
	TestUtils_Make_Test(tests_trie_print),
	TestUtils_Make_Test(tests_trie_init),
	TestUtils_Make_Test(tests_trie_add_one),
	TestUtils_Make_Test(tests_trie_add_two),
	TestUtils_Make_Test(tests_trie_add_two_2),
	TestUtils_Make_Test(tests_trie_add_three),
	TestUtils_Make_Test(tests_trie_add_three_2),
	TestUtils_Make_Test(tests_trie_search_not_present),
	TestUtils_Make_Test(tests_trie_add_already_present),
	TestUtils_Make_Test(tests_trie_add_more),
	TestUtils_Make_Test(tests_trie_remove_one),
	TestUtils_Make_Test(tests_trie_remove_more),
	TestUtils_Make_Test(tests_trie_remove_not_present),
	TestUtils_Make_Test(tests_trie_add_more2),
	TestUtils_Make_Test(tests_trie_add_more3),
	TestUtils_Make_Test(tests_trie_afbyrm),
};
