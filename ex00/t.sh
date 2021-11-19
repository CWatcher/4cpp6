#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo

valgrind -q ./convert 0 >> convert.log
valgrind -q ./convert nan >> convert.log
valgrind -q ./convert 42.0f >> convert.log

diff subject_output.txt convert.log && echo ok!
