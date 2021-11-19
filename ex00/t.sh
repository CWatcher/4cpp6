#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo

valgrind -q ./convert .123
valgrind -q ./convert 321.
valgrind -q ./convert +inf
valgrind -q ./convert nan

# valgrind -q ./convert 0 >> convert.log
# valgrind -q ./convert nan >> convert.log
# valgrind -q ./convert 42.0f >> convert.log

# diff subject_output.txt convert.log && echo ok!
