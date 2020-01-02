#! /bin/bash

server: server.o CreateInfra.o processRequest.o
	gcc -o server server.o CreateInfra.o processRequest.o

CreatInfra.o: CreateInfra.c ../headers.h ../shrdds.h
	gcc -c CreateInfra.c

server.o: server.c ../headers.h ../shrdds.h
	gcc -c server.c

processRequest.o : processRequest.c ../headers.h ../shrdds.h
	gcc -c processRequest.c

clean: 
	rm *.o
