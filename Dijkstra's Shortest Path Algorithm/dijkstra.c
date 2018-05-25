/*
 * dijkstra.c
 */

#include "dijkstra.h"
#include <stdlib.h>
#include <string.h>

// Returns the node with minimum distance from the source and is
// not yet in the SPT set.
static int minNodeNotInSPT(Graph *G, bool *sptSet, int *distFromSource) {
	int min_dist = INFINITE, ret;
	for(int i = 0; i < G->nnodes_; ++i) {
		if(!sptSet[i] && (distFromSource[i] < min_dist)) {
			min_dist = distFromSource[i];
			ret = i;
		}
	}
	return ret;
}

static void printDijkstraInfo(Graph *G, bool *sptSet, int *dist) {
	printf("%10s          %20s\n",
			"Node", "Distance from Source");
	puts("--------------------------------------------------------------------");
	for(int i = 0; i < G->nnodes_; ++i) {
		printf("%10d %20d\n", i, dist[i]);
	}
	printf("Shortest Path Tree(SPT) Set:\n");
	for(int i = 0; i < G->nnodes_; ++i) {
		if(sptSet[i])
			printf("%5d -> ", i);
	}
	puts("X");
}

void Dijkstra(Graph *G, int sourceNode) {

//#define MATRIX_IMPL
#ifdef MATRIX_IMPL
	bool *sptSet = (bool*)calloc(G->nnodes_, sizeof(bool));
	int *distFromSource = (int*)malloc(G->nnodes_ * sizeof(int));
	
	// Assign INF distance from src to all nodes
	for(int i = 0; i < G->nnodes_; ++i)
		distFromSource[i] = INFINITE;

	// Source node distance from source itself = 0
	distFromSource[sourceNode] = 0;

	// While sptSet[] does not contain every nodes, find and put appropriate
	// nodes on the sptSet[].
	int u, v, temp_dist;
	for(int i = 0; i < G->nnodes_; ++i) {
		u = minNodeNotInSPT(G, sptSet, distFromSource);
		sptSet[u] = true;

		for(v = 0; v < G->nnodes_; v++) {
			if(G->edge_[u][v] && !sptSet[v] //&& distFromSource[u] != INFINITE
				&& (temp_dist = distFromSource[u] + G->edge_[u][v]) < distFromSource[v])
			{
				distFromSource[v] = temp_dist;
			}
		}
	}

	printDijkstraInfo(G, sptSet, distFromSource);
#else
#endif
}

