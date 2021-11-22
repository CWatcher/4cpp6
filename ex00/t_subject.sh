#!/bin/sh

./convert 0 > convert.log		; echo >> convert.log
./convert nan >> convert.log	; echo >> convert.log
./convert 42.0f >> convert.log

diff -w subject_output.txt convert.log > convert.diff.log \
	&& echo ok! \
	|| cat -e convert.diff.log
