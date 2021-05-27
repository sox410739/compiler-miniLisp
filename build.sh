#!/bin/bash

bison -d -o Final.tab.c Final.y
gcc -c -g -I.. Final.tab.c
flex -o Final.yy.c Final.l
gcc -c -g -I.. Final.yy.c
gcc -o Final Final.tab.o Final.yy.o -ll
./Final < input.txt
