________________________________________________________________________________
Trie Project

- Author: 	Elias Nijs
- Startdate:	2022-11-13

Compilation and Runnning

- Compile debug   build with: `./build.sh`
- Compile release build with: `./build.sh release`
- Run with `./run.sh`

Notes on the design of the program

- I experimented in this program with function pointers.
- The program is compiled as a single compilation unit.
- All dependencies are located in order in main.c
  (The dependencies of ternarytrie.c, arraytrie.c and customtrie.c are
   included in their file. Otherwise I couldn't push.)
- The syntax style followed is outlined in `STYLEGUIDE.txt`.

Other Notes

- The `include` folder is only present so I could push. This folder is not
  used.
