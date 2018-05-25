##################################################
# Makefile for Dijkstra's Shortest path algorithm
##################################################
include Sources.mk

# Generate object file list from source file list
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
LD = ld
LDFLAGS = -lc
DEBUG = 
CFLAGS = -Wall -std=c99 $(DEBUG)
CPPFLAGS = 
DEFINES = -DMATRIX_IMPL
INCLUDES = -I$(GRAPH_DIR) -I$(LIST_DIR)

ifeq ($(OS), Windows_NT)
	EXE = dijkstra.exe
else
	EXE = dijkstra
endif

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
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -c '$<' -o $@

.PHONY: build_lib
build_lib: $(LIB_OBJECTS)

$(GRAPH_OBJ): $(GRAPH_SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -c '$^' -o $@

$(LIST_OBJ): $(LIST_SRC)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -c '$^' -o $@


clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~
