/*
 * Graph.h
 * Basic Graph implementation of an Undirected Graph.
 */

#ifndef GRAPH_H_
#define GRAPH_H_

// For S_Head data type
#include "list.h"
#include <stdio.h>
#include <stdint.h>

typedef int32_t** EdgeWeight;

typedef struct graph {
    int nnodes_; // Total no. of nodes

// Adjacency Matrix implementation
#ifdef MATRIX_IMPL
    int **edge_;
#else
// Default is adjacency list implementation
	// Dynamically allocated 1-d array.
    S_Head *adj_list_;
	EdgeWeight weight_;
#endif

} Graph;

//----------------------------------------------------------------------------

// Create a new 'Graph' on the heap and return a pointer to it
Graph *create_graph(int V);

// Add an edge between source and destination
int add_edge(Graph *g, int src, int dest, int weight);

// Print graph contents according to implementation without using any graph algorithms like BFS, DFS, etc.
void print_graph(Graph *g);

#endif
