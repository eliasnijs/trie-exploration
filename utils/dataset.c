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
	size_t len;
	char **words;
	uint32 wordcount;
};

/* function definitions */
internal int32 dataset_file_load(char *path, struct dataset *ds);
internal void dataset_die(struct dataset *ds);
internal void dataset_generate(int32 l_lb, int32 l_ub, int32 wordcount,
			       struct dataset *ds);
internal void dataset_shuffle(struct dataset *ds);

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
	uint32 flen = filelen(f);
	ds->backbuffer = (char *)calloc(flen, sizeof(char));
	fread(ds->backbuffer, sizeof(char), flen, f);
	fclose(f);
	ds->len = flen;
	ds->wordcount = 0;
	for (uint32 i = 0; i < flen; ++i) {
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
dataset_shuffle(struct dataset *ds)
{
	srand(nanos()); /* TODO(Elias): set random seed based on the current
			 * time, not sure if this is a legitimate way to
			 * randomize. */
	for (uint32 i1 = ds->wordcount - 1; i1 > 0; --i1) {
		int32 i2 = rand() % (i1 + 1);
		void *temp = ds->words[i2];
		ds->words[i2] = ds->words[i1];
		ds->words[i1] = temp;
	}
}
