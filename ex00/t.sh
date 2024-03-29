#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

set -v

./convert a			; echo
./convert -0.0		; echo
./convert 123		; echo
./convert 123f		; echo
./convert 123.f		; echo
./convert 12.3f		; echo
./convert .123		; echo
./convert 1.23		; echo
./convert -4.56		; echo
./convert 321.		; echo

./convert nan		; echo
./convert nanf		; echo
./convert -inff		; echo
./convert +inff		; echo
./convert -inf		; echo
./convert +inf		; echo

./convert abc
./convert 1a
./convert 12.3.f
./convert .1.
./convert .1.23
./convert .1.23a

./t_subject.sh
