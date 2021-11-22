#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo

./convert a			; echo
./convert 123		; echo
./convert 123f		; echo
./convert 123.f		; echo
./convert 12.3f		; echo
./convert .123		; echo
./convert 1.23		; echo
./convert 321.		; echo
./convert -inff		; echo
./convert +inff		; echo
./convert nanf		; echo
./convert -inf		; echo
./convert +inf		; echo
./convert nan		; echo

./convert abc
./convert 1a
./convert 12.3.f
./convert .1.
./convert .1.23
./convert .1.23a

# valgrind -q ./convert 0 >> convert.log
# valgrind -q ./convert nan >> convert.log
# valgrind -q ./convert 42.0f >> convert.log

# diff subject_output.txt convert.log && echo ok!
