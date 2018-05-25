/*
 * dijkstra.h
 *
 * Implementation of the Dijkstra's Shortest Path Algorithm.
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <limits.h>
#define INFINITE	INT_MAX

#include <stdbool.h>

// We will be using matrix implemented graph.
//#define MATRIX_IMPL
#include "graph.h"

// Returns the Shortest path tree(SPT) set using the Dijkstra's
// SPT algorithm.
void Dijkstra(Graph*, int sourceNode);

#endif
