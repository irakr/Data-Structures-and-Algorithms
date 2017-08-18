# Makefile for singly linked list
CC=gcc
LD=ld
CFLAGS=-Wall -std=c99
GDB=-g
EXE=sllist

$(EXE):	main.o list.o list.h
	$(CC) main.o list.o -o sllist

main.o:	main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o:	list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~

debug:
	$(CC) $(CFLAGS) $(GDB) -o $(EXE) main.c list.c
