/* configuration */

/* TODO(Elias): Do this in a better way. */
global_variable struct trie TestsTrieModel = {0};

/* helpers */
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

/* tests */
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
tests_trie_add_five_remove_one(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *strings[] = { "4", "1", "3", "2", "7" };
	for (int32 i = 0; i < ArrayLength(strings); ++i) {
		TestUtils_Assert(trie_add(&trie, strings[i]));
		for (int32 j = 0; j <= i; ++j) {
			TestUtils_Assert(trie_search(&trie, strings[j]));
		}
	}
	TestUtils_Assert(trie_remove(&trie, strings[0]));
	TestUtils_Assert(trie_search(&trie, strings[3]));
	TestUtils_Assert(trie_search(&trie, strings[1]));
	TestUtils_Assert(trie_search(&trie, strings[2]));

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_three_remove_one(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
	testutilsstate->cleanupargs = (void *)&trie;
	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *strings[] = { "04", "01", "07" };
	for (int32 i = 0; i < ArrayLength(strings); ++i) {
		TestUtils_Assert(trie_add(&trie, strings[i]));
		for (int32 j = 0; j <= i; ++j) {
			TestUtils_Assert(trie_search(&trie, strings[j]));
		}
	}
	TestUtils_Assert(trie_remove(&trie, strings[0]));
	for (int32 j = 1; j < ArrayLength(strings); ++j) {
		TestUtils_Assert(trie_search(&trie, strings[j]));
	}
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
	/* trie_print(&trie, stdout); */

	TestUtils_Assert(trie_search(&trie, one));
	/* trie_print(&trie, stdout); */
	TestUtils_Assert(trie_search(&trie, two));
	/* trie_print(&trie, stdout); */
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

	/* printf("\n"); */
	/* trie_print(&trie, stdout); */

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
tests_trie_add_more4(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	TestUtils_Assert(trie_add(&trie, "the"));
	TestUtils_Assert(trie_add(&trie, "how"));
	TestUtils_Assert(trie_add(&trie, "me"));
	TestUtils_Assert(trie_size(&trie) == 3);
	TestUtils_Assert(trie_search(&trie, "me"));
	TestUtils_Assert(trie_search(&trie, "the"));
	TestUtils_Assert(trie_search(&trie, "how"));
	TestUtils_Assert(trie_search(&trie, "me"));

  	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_thesame(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
	trie_init(&trie);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *s[] = {"Hello", "World", "Universe", "Heaven", "Hell"};
	for (int i = 0; i < ArrayLength(s); ++i) {
		TestUtils_Assert(trie_add(&trie, s[i]));
	}
	for (int i = 0; i < ArrayLength(s); ++i) {
		TestUtils_Assert(!trie_add(&trie, s[i]));
	}
	for (int i = 0; i < ArrayLength(s); ++i) {
		TestUtils_Assert(trie_search(&trie, s[i]));
	}

	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_splay_test(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *strings[][3] = {
		{"1", "2", "3"},
		{"1", "3", "2"},
		{"3", "1", "2"},
		{"3", "2", "1"},
	};
	for (int32 i = 0; i < 4; ++i) {
		/* DebugLogLine(); */
		trie_init(&trie);
		for (int32 j = 0; j < 3; ++j) {
			char *str = strings[i][j];
			TestUtils_Assert(trie_add(&trie, str));
		}
		/* trie_print(&trie, stdout); */
		trie_search(&trie, strings[i][2]);
		/* trie_print(&trie, stdout); */
		trie_free(&trie);
	}
	return 0;
}

internal int32
tests_trie_add_splay_test2(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *strings[] = {
		"1", "2", "3", "4", "5", "6", "9", "12",
	};
	trie_init(&trie);
	for (int32 j = 0; j < ArrayLength(strings); ++j) {
		/* DebugLogLine(); */
		char *str = strings[j];
		/* DebugLog("Adding %s", str); */
		TestUtils_Assert(trie_add(&trie, str));
		/* trie_print(&trie, stdout); */
	}
	/* DebugLogLine(); */
	/* DebugLog("Searching now"); */
	for (int32 j = 0; j < ArrayLength(strings); ++j) {
		/* DebugLogLine(); */
		TestUtils_Assert(trie_search(&trie, strings[j]));
		/* trie_print(&trie, stdout); */
	}
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_add_splay_test3(TestUtilsState *testutilsstate)
{
	struct trie trie = TestsTrieModel;
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	char *strings[] = {
		"01", "02", "03", "04", "05", "016", "017", "018", "019",
	};
	trie_init(&trie);
	for (int32 j = 0; j < ArrayLength(strings); ++j) {
		/* DebugLogLine(); */
		char *str = strings[j];
		/* DebugLog("Adding %s", str); */
		TestUtils_Assert(trie_add(&trie, str));
		/* trie_print(&trie, stdout); */
	}
	for (int32 j = 0; j < ArrayLength(strings); ++j) {
		TestUtils_Assert(trie_search(&trie, strings[j]));
	}
	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_dataset(TestUtilsState *testutilsstate, char *path)
{
	struct trie trie = TestsTrieModel;
	trie_init_wmem(&trie, Megabytes(500));
	/* trie_init(&trie); */
	TestUtils_Assert(trie.t != 0);
  	testutilsstate->cleanupargs = (void *)&trie;
  	testutilsstate->cleanup     = (void (*)(void *))trie_free;

	struct dataset ds;
	dataset_file_load(path, &ds);
	struct trie_and_dataset trie_ds = {&trie, &ds};
  	testutilsstate->cleanupargs = (void *)&trie_ds;
  	testutilsstate->cleanup     = (void (*)(void *))free_trie_and_dataset;
	shuffle_ptr((void **)ds.words, ds.wordcount);

	int32 count = ds.wordcount;
	printf("> checking add\n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(trie_add(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == i + 1);
	}
	TestUtils_Assert(trie_size(&trie) == count);
	printf("    > checking search\n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(trie_search(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == count);
	}
	printf("    > checking remove\n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(trie_remove(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == count - i - 1);
	}
	printf("    > checking search\n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(!trie_search(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == 0);
	}
	printf("    > checking double add\n");
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(trie_add(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == i + 1);
	}
	TestUtils_Assert(trie_size(&trie) == count);
	for (uint32 i = 0; i < count; ++i) {
		TestUtils_Assert(!trie_add(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == count);
	}
	TestUtils_Assert(trie_size(&trie) == count);
	printf("    > checking search  \n");
	for (uint32 i = 0; i < count; ++i) {
		struct ctrie_node *root = ((struct ctrie *)trie.t)->root;
		TestUtils_Assert(trie_search(&trie, ds.words[i]));
		TestUtils_Assert(trie_size(&trie) == count);
	}
	printf("    ");
	dataset_die(&ds);
  	trie_free(&trie);
	return 0;
}

internal int32
tests_trie_dataset_verysmall(TestUtilsState *testutilsstate)
{
	return tests_trie_dataset(testutilsstate,
				  "resources/geschud_piepklein.g6");
}
internal int32
tests_trie_dataset_small(TestUtilsState *testutilsstate)
{
	return tests_trie_dataset(testutilsstate, "resources/geschud_klein.g6");
}
internal int32
tests_trie_dataset_middle(TestUtilsState *testutilsstate)
{
	return tests_trie_dataset(testutilsstate,
				  "resources/geschud_middelmaat.g6");
}
internal int32
tests_trie_dataset_large(TestUtilsState *testutilsstate)
{
	return tests_trie_dataset(testutilsstate, "resources/geschud_groot.g6");
}

internal int32
tests_trie_dataset_words(TestUtilsState *testutilsstate)
{
	return tests_trie_dataset(testutilsstate,
				  "resources/words_shuffled.txt");
}


/* tests-batch */
global_variable TestUtilsTest tests_trie[] = {
	/* TestUtils_Make_Test(tests_trie_print), */
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
	TestUtils_Make_Test(tests_trie_add_five_remove_one),
	TestUtils_Make_Test(tests_trie_remove_more),
	TestUtils_Make_Test(tests_trie_remove_not_present),
	TestUtils_Make_Test(tests_trie_add_three_remove_one),
	TestUtils_Make_Test(tests_trie_add_more2),
	TestUtils_Make_Test(tests_trie_add_more3),
	TestUtils_Make_Test(tests_trie_add_more4),
	TestUtils_Make_Test(tests_trie_add_splay_test),
	TestUtils_Make_Test(tests_trie_add_splay_test2),
	TestUtils_Make_Test(tests_trie_add_splay_test3),
	TestUtils_Make_Test(tests_trie_add_thesame),
	TestUtils_Make_Test(tests_trie_dataset_verysmall),
	TestUtils_Make_Test(tests_trie_dataset_small),
	TestUtils_Make_Test(tests_trie_dataset_middle),
	TestUtils_Make_Test(tests_trie_dataset_large),
	TestUtils_Make_Test(tests_trie_dataset_words),
};
