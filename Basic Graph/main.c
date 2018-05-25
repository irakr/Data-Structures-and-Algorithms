/*
 * main.c
 * Try out Graph implementation.
 */

#include <stdio.h>
#include "graph.h"

int main() {
    Graph *myGraph = create_graph(5);
    if(!myGraph)
        fprintf(stderr, "[ERROR] Could not create graph\n");
    
    // TODO...Try the implementation
    add_edge(myGraph, 0, 1, 4);
    add_edge(myGraph, 0, 2, 5);
    add_edge(myGraph, 1, 0, 1);
    add_edge(myGraph, 1, 4, 2);
    add_edge(myGraph, 2, 3, 3);
    add_edge(myGraph, 3, 4, 6);
    add_edge(myGraph, 4, 0, 7);
    
    print_graph(myGraph);
	
	while(1);
	
    return 0;
}
