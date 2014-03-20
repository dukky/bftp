bftp
====

Transpiler from brainfuck to c.

##Build
`gcc -O3 -std=c99 -o bftp bftp.c`

##Usage
`./compile.sh source.bf out`

Or
`./bftp source.bf | gcc -O3 -o out -xc -`
