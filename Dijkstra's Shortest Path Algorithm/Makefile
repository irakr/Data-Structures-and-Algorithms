##################################################
# Makefile for Dijkstra's Shortest path algorithm
##################################################
include Sources.mk

# Generate object file list from source file list
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
LD = ld
LDFLAGS = -lc
CFLAGS = -Wall -std=c99
CPPFLAGS = 
INCLUDES = -I$(GRAPH_DIR) -I$(LIST_DIR)
GDB = -g
EXE = dijkstra

# Build everything in the directory
.PHONY: all
all: $(EXE)

$(EXE):	build_lib $(OBJECTS)
# XXX Some issues with using ld. Instead using gcc.
# $(LD) $(LDFLAGS) $(OBJECTS) $(LIB_OBJECTS) -o $@
#
	$(CC) $(OBJECTS) $(LIB_OBJECTS) -o $@

# NOTE that $< and $@ are wrapped within single quotes in the directory name contains space
%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$<' -o $@

.PHONY: build_lib
build_lib: $(LIB_OBJECTS)

$(GRAPH_OBJ): $(GRAPH_SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$^' -o $@

$(LIST_OBJ): $(LIST_SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$^' -o $@

# For debugging output
.PHONY: debug
debug:
	CFLAGS += $(GDB)
	make all

clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~
