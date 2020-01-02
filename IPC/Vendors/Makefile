#! /bin/bash

adder: adder.o
	gcc -o adder adder.o

adder.o: adder.c headers.h  ../shrdds.h
	gcc -c adder.c

clean: 
	rm *.o
