#!/bin/sh

# Sources
input="src/main.c"

# Output
output="build/build"

# Flags
common_dflags="-D_POSIX_C_SOURCE=199309L"
common_wflags="-Wno-unused-variable -Wno-unused-function -Wno-write-strings"
common_flags="-std=c99 -pipe"

# -> Debug Flags
debug_dflags="$common_dflags -DENABLE_ASSERT=1 -DENABLE_DEBUGLOG=1"
debug_wflags="$common_wflags"
debug_flags="${common_flags} -Wall -g ${debug_wflags} ${debug_dflags}"
# debug_flags="$common_flags -Wall -fsanitize=address -g ${debug_wflags} ${debug_dflags}"

# -> Release Flags
release_dflags="$common_dflags"
release_wflags="$common_wflags"
# release_flags="${common_flags} -O3 -Wall  ${release_wflags} ${release_dflags}"
release_flags="${common_flags} -Ofast -march=native -Wall  ${release_wflags} ${release_dflags}"

# Linker
libs="-lncurses -lm"

# 5. Compiler
compiler="cc"

# Command
if [ "$1" = "release" ]; then
  echo compiling release build...
  ${compiler} ${release_flags} -o ${output} ${input} ${libs}
  echo finished compiling...
else
  echo compiling debug build...
  ${compiler} ${debug_flags} -o ${output} ${input} ${libs}
  echo finished compiling
fi
