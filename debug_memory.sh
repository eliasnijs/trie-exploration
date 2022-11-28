#!/bin/sh

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes build/build
