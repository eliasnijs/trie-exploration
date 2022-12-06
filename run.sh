#!/bin/bash

if [ "$1" = "t" ]; then
	build/tests ${@:2}
elif [ "$1" = "b" ]; then
	build/benchmarks ${@:2}
else
	echo wrong arguments
	echo "t - run tests program "
	echo "b - run benchmarks program "
fi
