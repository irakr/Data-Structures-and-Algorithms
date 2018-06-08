# Makefile for singly linked list
CC=gcc
LD=ld
CFLAGS=-Wall -std=c99
GDB=-g

EXE=queue-test

DEFINES=-DMATRIX_IMPL

DIR_SLIST=../Singly\ Linked\ List/
DIRECTORIES = -I$(DIR_SLIST) -I$(DIR_GRAPH)

$(EXE):	main.o queue.o list.o
	$(CC) main.o queue.o list.o -o $(EXE)

main.o:	main.c
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c queue.c

list.o: $(DIR_SLIST)/list.c $(DIR_SLIST)/list.h
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c $(DIR_SLIST)/list.c
    
clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~

debug:
	$(CC) $(CFLAGS) -O0 $(GDB) $(DIRECTORIES) $(DEFINES) -o $(EXE) main.c queue.c $(DIR_SLIST)/list.c
