#!/bin/sh

# _________________________________________________________________________________________
# Configuration

# Flags
common_dflags="-D_POSIX_C_SOURCE=199309L"
common_wflags="-Wno-unused-variable -Wno-unused-function -Wno-write-strings"
common_flags="-std=c99 -pipe"

# -> Debugg Flags
debug_dflags="$common_dflags -DENABLE_ASSERT=1 -DENABLE_DEBUGLOG=1"
debug_wflags="$common_wflags"
debug_flags="${common_flags} -Wall -g ${debug_wflags} ${debug_dflags}"
debug_flags="$common_flags -Wall -Wextra -fsanitize=address -g ${debug_wflags} ${debug_dflags}"

# -> Release Flags
release_dflags="$common_dflags"
release_wflags="$common_wflags"
# release_flags="${common_flags} -O3 -Wall  ${release_wflags} ${release_dflags}"
release_flags="${common_flags} -Ofast -march=native -Wall  ${release_wflags} ${release_dflags}"

# Compiler
compiler="cc"

# _________________________________________________________________________________________
# Compiling
#

flags=""
if [ "$1" = "r" ]; then
  echo "[build.sh]: set release flags"
  flags=$release_flags
else
  echo "[build.sh]: set debug flags"
  flags=$debug_flags
fi

echo "[build.sh]: building static trie library..."

echo "[build.sh]: compiling ternarytrie..."
${compiler} -c ${flags} -o build/libternarytrie.o src/ternarytrie.c
echo "[build.sh]: compiling arraytrie..."
${compiler} -c ${flags} -o build/libarraytrie.o src/arraytrie.c
echo "[build.sh]: compiling customtrie..."
${compiler} -c ${flags} -o build/libcustomtrie.o src/customtrie.c
echo "[build.sh]: finished compiling tries"

echo "[build.sh]: creating library..."
ar rcs build/libtries.a build/libternarytrie.o build/libcustomtrie.o build/libarraytrie.o
ar rcs build/libarraytrie.a build/libarraytrie.o
rm build/libternarytrie.o build/libcustomtrie.o build/libarraytrie.o
echo "[build.sh]: finished creating library"

echo "[build.sh]: trie library complete"

echo "[build.sh]: building test program..."
${compiler} ${flags} -o "build/tests" "tests/tests.c" -lncurses -L build/ -ltries
echo "[build.sh]: finished building test program"


echo "[build.sh]: building benchmark program..."
${compiler} ${flags} -o "build/benchmarks" "benchmarks/benchmarks.c" -L build/ -ltries
echo "[build.sh]: finished building benchmark program"
