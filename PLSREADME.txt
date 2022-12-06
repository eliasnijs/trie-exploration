Trie Project

- Author: 	Elias Nijs
- Startdate:	2022-11-13

Compilation and Runnning

- Compile debug build with: './build.sh' from '/'
- Compile release/optimized build with: './build.sh r' from '/'
- Run with `run.sh` from '/'

Notes on the design of the program

- I experimented in this program with function pointers.
- The program is compiled as a single compilation unit.
- All dependencies are included in order in main.c (The dependencies of
  ternarytrie.c, arraytrie.c and customtrie.c are included in their file,
  otherwise I couldn't push.)
- The syntax style followed is outlined in `STYLEGUIDE.txt`. There is an
  editorconfig file present at '/.editorconfig'
- There are bunch of files included in 'src/base/', these are the files I use
  in every c project. Not all of them are necessarily used.

Notes on the folder setup

- The 'src' directory holds all source files.
- The 'build' directory holds the binaries.
- The 'resource' folders holds the files needed by the program.
- The 'data folder' holds the files output by the program.
- The 'extra' holds the report and some analysis of the program.
- The `include` folder is only present so I could push. This folder is not used.

Notes on the report

- Some performance analysis was done on these tries. The report can be found at
  '/extra/verslag.{pdf,ps,ms}'.
- There is a notebook included in which the different graphs were rendered with
   matplotlib.

License

- This project is licensed under the terms of the MIT license.
