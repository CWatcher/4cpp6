#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo

./convert a
./convert abc
./convert 123
./convert 123f
./convert 123.f
./convert 12.3f
./convert .123
./convert 1.23
./convert 321.
./convert -inff
./convert +inff
./convert nanf
./convert -inf
./convert +inf
./convert nan
./convert 12.3.f
./convert .1.
./convert .1.23
./convert .1.23a

# valgrind -q ./convert 0 >> convert.log
# valgrind -q ./convert nan >> convert.log
# valgrind -q ./convert 42.0f >> convert.log

# diff subject_output.txt convert.log && echo ok!
