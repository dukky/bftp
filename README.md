bftp
====

Transpiler from brainfuck to c.

###Build
`gcc -O3 -std=c99 -o bftp bftp.c`
###Usage
`./compile.sh hellobrainfuck.bf out`

or

`./bftp hellobrainfuck.bf | gcc -O3 -o out -xc -`

`./out` : `Hello World!`
