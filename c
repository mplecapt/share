#!/bin/bash
# C Compiler to simplify my testing experience

clear;
echo "Compiling..."; echo

if gcc -g -std=c99 -pedantic -Wall -Wextra -lm -O1 -O0 -o $1 $1.c; then

skip=${#1}
args="$@"
cargs=${args:skip}

echo; echo "Running $1 with arguments {$cargs }:"; echo

./$args
rm $1

else

echo; echo "Compiler failed."; echo

fi

echo; echo "Done."
