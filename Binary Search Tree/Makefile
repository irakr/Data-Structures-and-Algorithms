##################################################
# Makefile for Binary Search Tree data structure
##################################################
include Sources.mk

# Generate object file list from source file list
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
LD = ld
LDFLAGS = -lc
GDB = -g
CFLAGS := -Wall -std=c99

ifeq ($(mode), debug)
  CFLAGS += $(GDB)
endif

CPPFLAGS = 
INCLUDES = 

EXE = bst #?????????

# Build everything in the directory
.PHONY: all
all: $(EXE)

$(EXE):	$(OBJECTS) #?????????
	$(CC) $(OBJECTS) $(LIB_OBJECTS) -o $@

# NOTE that $< and $@ are wrapped within single quotes in the directory name contains space
%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$<' -o $@

# For debugging output
.PHONY: debug
debug:
	CFLAGS += $(GDB)
	make all

clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~
