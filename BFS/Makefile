# Makefile for singly linked list
CC=gcc
LD=ld
CFLAGS=-Wall -std=c99
GDB=-g

EXE=bfs

DEFINES=-DMATRIX_IMPL

DIR_SLIST=../Singly\ Linked\ List/
DIR_GRAPH=../Basic\ Graph/
DIR_QUEUE=../Queue/
DIRECTORIES = -I$(DIR_SLIST) -I$(DIR_GRAPH) -I$(DIR_QUEUE)

$(EXE):	main.o queue.o graph.o list.o bfs.o $(DIR_GRAPH)graph.h bfs.h
	$(CC) main.o queue.o graph.o list.o bfs.o -o $(EXE)

main.o:	main.c $(DIR_GRAPH)graph.h bfs.h $(DIR_QUEUE)queue.h
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c main.c

bfs.o: bfs.c bfs.h
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c bfs.c

queue.o: $(DIR_QUEUE)queue.c $(DIR_QUEUE)queue.h
	$(CC) $(CFLAGS) $(DIRECTORIES) $(DEFINES) -c $(DIR_QUEUE)queue.c

graph.o:	list.o $(DIR_GRAPH)graph.c $(DIR_GRAPH)graph.h
	$(CC) $(CFLAGS) $(DEFINES) $(DIRECTORIES) -c $(DIR_GRAPH)graph.c

list.o: $(DIR_SLIST)/list.c 
	$(CC) $(CFLAGS) $(DEFINES) $(DIRECTORIES) -c $(DIR_SLIST)/list.c
    
clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~

debug:
	$(CC) $(CFLAGS) -O0 $(GDB) $(DIRECTORIES) $(DEFINES) -o $(EXE) main.c $(DIR_QUEUE)queue.c $(DIR_GRAPH)graph.c bfs.c $(DIR_SLIST)/list.c
