/*
 * main.c
 */
#include <stdio.h>
#include "dijkstra.h"

int main() {
	Graph *G = create_graph(9);
	add_edge(G, 0, 1, 4);
	add_edge(G, 0, 7, 8);
	add_edge(G, 1, 2, 8);
	add_edge(G, 1, 7, 11);
	add_edge(G, 2, 3, 7);
	add_edge(G, 2, 5, 4);
	add_edge(G, 2, 8, 2);
	add_edge(G, 3, 4, 9);
	add_edge(G, 3, 5, 14);
	add_edge(G, 4, 5, 10);
	add_edge(G, 5, 6, 2);
	add_edge(G, 6, 7, 1);
	add_edge(G, 6, 8, 6);
	add_edge(G, 7, 8, 7);

	//print_graph(G);

	Dijkstra(G, 0);

	return 0;
}

