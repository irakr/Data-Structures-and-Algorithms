##################################################
# Makefile for AVL Tree
##################################################
include Sources.mk

# Generate object file list from source file list
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
LD = ld
LDFLAGS = -lc
CFLAGS = -Wall -std=c99
CPPFLAGS = 
INCLUDES = 
GDB = -g
EXE = avl 

# For debug mode
ifeq ($(mode), debug)
  CFLAGS += $(GDB)
endif

# Build everything in the directory
.PHONY: all
all: $(EXE)

$(EXE):	$(OBJECTS)
# XXX Some issues with using ld. Instead using gcc.
# $(LD) $(LDFLAGS) $(OBJECTS) $(LIB_OBJECTS) -o $@
#
	$(CC) $(OBJECTS) -o $@

# NOTE that $< and $@ are wrapped within single quotes in the directory name contains space
%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$<' -o $@

clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~
