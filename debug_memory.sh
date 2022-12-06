#!/bin/bash

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes $1 ${*:2}
