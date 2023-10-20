Trie Project

- Author: 	Elias Nijs
- Startdate:	2022-11-13

Folder structure

- 'benchmarks/'		contains a benchmarking program
- 'build/'		contains the output of './build.sh'
- 'src/'		contains the trie implementations
- 'data/'		contains files produces by the programs
- 'extra/'		contains a report and performance analysis
- 'include/'		contains the headfiles of the differen tries
- 'resources/'		contains all files used by the programs
- 'tests/'		contains a testing program
- 'utils/'		contains some base files used by both the testing and
			benchmarking program

Building and Running

- Build everything with './build.sh'
- 'build.sh' will:
	1. compile all the tries and put them in a static library
	   'build/libtries.a'
	2. compile the test program
	3. compile the benchmark program
- Run the test program with:
	'build/tests <trie>'
- Run the benchmark program with:
	'build/benchmarks <trie> <filepath> <benchmarkindex>'
  To run a benchmark on multiple files, you could for example do the following:
	'wc -l resources/* | head -n -1 | sort -n | sed "s/.* //"
		| xargs -i build/benchmarks array {} 1'

Design of the program

- In every descision speed was given priority over memory usage.
- The programming style followed is largely based on the following sources:
	1. https://git.sr.ht/~sircmpwn/cstyle
	2. http://doc.cat-v.org/bell_labs/pikestyle
	3. https://suckless.org/coding_style/
- I experimented in this program with function pointers.

Other

- Both a pooling allocator and memory arena allocator were made. Unfortunately
  these couldn't by used in the final result because the the function
  definitions couldn't be changed for the assignment. In the final result these
  are removed. They will, however, still be used for benchmarking.
- A custom testing system was used. This system is still a work in progress,
  especially the terminal ui part.
