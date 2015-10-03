#!/bin/bash
if [ -z "$2" ]; then
	./bftp $1 | gcc -Wall -Werror -O3 -o a.out -xc -
else
	./bftp $1 | gcc -Wall -Werror -O3 -o $2 -xc -
fi
