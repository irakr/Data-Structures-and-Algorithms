# Makefile for singly linked list
CC=gcc
LD=ld
CFLAGS=-Wall -std=c99
GDB=-g

EXE=graph

DEFINES=

DIRECTORIES=../Singly\ Linked\ List

$(EXE):	main.o graph.o list.o graph.h
	$(CC) main.o graph.o list.o -o $(EXE)

main.o:	main.c graph.h
	$(CC) $(CFLAGS) -I$(DIRECTORIES) $(DEFINES) -c main.c

graph.o:	list.o graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c $(DEFINES) -I$(DIRECTORIES)

list.o: $(DIRECTORIES)/list.c
	$(CC) $(CFLAGS) -c $(DIRECTORIES)/list.c
    
clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~

debug:
	$(CC) $(CFLAGS) $(GDB) -I$(DIRECTORIES) $(DEFINES) -o $(EXE) main.c graph.c $(DIRECTORIES)/list.c
