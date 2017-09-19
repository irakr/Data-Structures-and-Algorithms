# Source file variables

SOURCES = main.c	\
	  dijkstra.c	\

##############################################################
# Directories of required libraries.
#
# FIXME If we need graph as a library, then we will have to 
# explicitly build singly linked list too. This is because
# graph depends on list.
##############################################################
GRAPH_DIR = ../Basic\ Graph
LIST_DIR = ../Singly\ Linked\ List

# Source files of the libraries
GRAPH_SRC = $(GRAPH_DIR)/graph.c
LIST_SRC = $(LIST_DIR)/list.c

LIB_SOURCES = $(GRAPH_SRC) $(LIST_SRC)

# Object files are entered without the directory name prefixes since
# we will let gcc generate the object files in the PWD
GRAPH_OBJ = graph.o
LIST_OBJ = list.o
LIB_OBJECTS = $(GRAPH_OBJ) $(LIST_OBJ)
