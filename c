#!/bin/bash
# C Compiler to simplify my testing experience

clr='\033[0;31m'
NC='\033[0m'


clear;
echo -e "${clr}Compiling...${NC}"; echo

if gcc -g -std=c99 -pedantic -Wall -Wextra -lm -O1 -O0 -o $1 $1.c; then

skip=${#1}
args="$@"
cargs=${args:skip}

echo; echo -e "${clr}Running${NC} $1 ${clr}with arguments {${NC}$cargs ${clr}}:${NC}"; echo

./$args
rm $1

else

echo; echo -e "${clr}Compiler failed.${NC}"; echo

fi

echo; echo -e "${clr}Done.${NC}"
