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
    add_edge(myGraph, 0, 1);
    add_edge(myGraph, 0, 2);
    add_edge(myGraph, 1, 0);
    add_edge(myGraph, 1, 4);
    add_edge(myGraph, 2, 3);
    add_edge(myGraph, 3, 4);
    add_edge(myGraph, 4, 0);
    
    print_graph(myGraph);
    
    return 0;
}
