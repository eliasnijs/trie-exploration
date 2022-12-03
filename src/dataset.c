/* depends on:
 * stdio.h, stdlib.h, base.h
 * */

/* Datasets, in the context of our program, are lists of multikey data. When
 * saved or loaded from file, these are expected to be seperated by enters.
 * */

/* macros and typedefs */

/* enumerations, structs, unions */
struct dataset {
	char *backbuffer;
	char **words;
	int32 wordcount;
};

/* function definitions */
internal int32 dataset_file_load(char *path, struct dataset *ds);
internal void dataset_die(struct dataset *ds);
internal void dataset_generate(int32 l_lb, int32 l_ub, int32 wordcount,
			       struct dataset *ds);

/* function implementations */
internal void
dataset_die(struct dataset *ds)
{
	free(ds->backbuffer);
	free(ds->words);
}

internal int32
dataset_file_load(char *path, struct dataset *ds)
{
/* TODO(Elias): At the moment, we go through the entire dataset twice.
 * The first time to get the wordcount and the second time to get the
 * pointers to the words. There has got to be a better way to do this.
 * */
	FILE *f = fopen(path, "r");
	if (!f) {
		DebugLogError("failed to read file at: %s", path);
		return 1;
	}
	int32 flen = filelen(f);
	ds->backbuffer = (char *)calloc(flen, sizeof(char));
	fread(ds->backbuffer, sizeof(char), flen, f);
	fclose(f);
	ds->wordcount = 0;
	for (int32 i = 0; i < flen; ++i) {
		if (ds->backbuffer[i] == '\n') {
			++ds->wordcount;
		}
	}
	ds->words = (char **)calloc(ds->wordcount, sizeof(char *));
	char *c = ds->backbuffer;
	for (uint32 i = 0; i < ds->wordcount; ++i) {
		ds->words[i] = c;
		while (*c != '\n') {
			++c;
		}
		*c = '\0';
		++c;
	}
	return 0;
}

internal void
dataset_generate(int32 l_lb, int32 l_ub, int32 wordcount, struct dataset *ds)
{
/* TODO(Elias): This uses rand() at the moment. Expand this function with the
 * capability to sample from given distritubtions.
 * IMPORTANT(Elias): The alphabet size is standard ASCII
 * */
	Assert(l_lb < l_ub);
	Assert(wordcount > 0);
	srand(nanos());
	ds->wordcount = wordcount;
	int32 lengths[ds->wordcount];
	int32 memsize = 0;
	for (int32 i = 0; i < ds->wordcount; ++i) {
		int32 l = l_lb + (rand() % (l_ub - l_lb));
		lengths[i] = l;
		memsize += l + 1;
	}
	ds->backbuffer = (char *)calloc(1, memsize);
	ds->words = (char **)calloc(ds->wordcount, sizeof(char *));
	int32 memindex = 0;
	for (int32 i_word = 0; i_word < ds->wordcount; ++i_word) {
		ds->words[i_word] = &ds->backbuffer[memindex];
		int32 l = lengths[i_word];
		for (int32 i_letter = 0; i_letter < l; ++i_letter) {
			ds->words[i_word][i_letter] = rand() % 0b1111111;
		}
		ds->words[i_word][l] = 0;
		memindex += l + 1;
	}
}
