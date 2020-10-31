##################################################
# Makefile for Binary Search Tree data structure
##################################################
include Sources.mk

# Generate object file list from source file list
OBJECTS = $(SOURCES:.cpp=.o)

CXX = g++
LD = ld
LDFLAGS = -lc
GDB = -g -O0
CXXFLAGS := -Wall -std=c99

ifeq ($(mode), debug)
  CXXFLAGS += $(GDB)
endif

CPPFLAGS = 
INCLUDES = 

EXE = rb-tree #?????????

# Build everything in the directory
.PHONY: all
all: $(EXE)

$(EXE):	$(OBJECTS) #?????????
	$(CXX) $(OBJECTS) $(LIB_OBJECTS) -o $@

# NOTE that $< and $@ are wrapped within single quotes in the directory name contains space
%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDES) -c '$<' -o $@

# For debugging output
.PHONY: debug
debug:
	CXXFLAGS += $(GDB)
	make all

clean:
	-rm -rf *.o
	-rm -rf $(EXE)
	-rm -rf *~
