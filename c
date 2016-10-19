#!/bin/bash
# C Compiler to simplify my testing experience

echo "Compiling..."; echo

gcc -g -std=c99 -pedantic -Wall -Wextra -O1 -O0 -o $1 $1.c
skip=${#1}
args="$@"
cargs=${args:skip}

echo; echo "Running $1 with arguments {$cargs }:"; echo

./$args
rm $1

echo; echo "Done."
