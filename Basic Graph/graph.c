/*
 * Graph.c
 * Basic graph operations
 */

#include "graph.h"
#include <stdlib.h>
#include <assert.h>

Graph *create_graph(int V) {
    
    Graph *g = (Graph*)calloc(1, sizeof(Graph));
    assert(g != NULL);
    g->nnodes_ = V;
    
#ifdef MATRIX_IMPL
    g->edge_ = (int**)malloc(sizeof(int*) * V);
    if(!g->edge_) {
        free(g);    // Release memories backwards
        return NULL;
    }
    for(int i = 0; i < V; i++) {
        g->edge_[i] = (int*)calloc(V, sizeof(int));
        if(!g->edge_[i]) {
            free(g->edge_);
            free(g);
            return NULL;
        }
    }
#else // Adjacency list implementation
    g->adj_list_ = (S_Head*)calloc(V, sizeof(S_Head));
    if(!g->adj_list_) {
        free(g);
        return NULL;
    }
	
	g->weight_ = (int32_t**)calloc(V, sizeof(int32_t));
	if(!g->weight_) {
		free(g);
		return NULL;
	}
	for(int i = 0; i < V; i++) {
		g->weight_[i] = (int32_t*)calloc(V, sizeof(int32_t));
		if(!g->weight_[i]) {
			free(g->weight_);
			free(g);
			return NULL;
		}
	}
#endif
    
    return g;
}

int add_edge(Graph *g, int src, int dest, int weight) {
    if(!g)
        return -1;
    if(src < 0 || dest < 0 || src >= g->nnodes_ || dest >= g->nnodes_)
        return -1;
    
    // Note that this is an undirected graph. Therefore, edge will be linked from src to dest and vice-versa.
#ifdef MATRIX_IMPL
    g->edge_[src][dest] = weight;
    g->edge_[dest][src] = weight;
#else
    push(g->adj_list_+src, (void*)&dest, sizeof(dest));
	g->weight_[src][dest] = weight;
    //push(g->adj_list_+dest, (void*)&src, sizeof(src));
#endif
    
    return 0;
}

void print_graph(Graph *g) {

    int i, j;
    if(!g) {
        fprintf(stderr, "In print_graph(Graph*): Graph is empty !\n");
        return;
    }
    
#ifdef MATRIX_IMPL
    
    //puts("Printing adjacency matrix implemented graph");
    
    // Print column wise indexes first. Then print each row-wise
    // indexes along with the edges.
    printf("%5s", "+");
    for(i = 0; i < g->nnodes_; ++i)
        printf("%5d", i);
    puts("");
    for(i = 0; i < g->nnodes_; i++) {
        printf("%5d", i);
        for(j = 0; j < g->nnodes_; j++) {
            printf("%5d", g->edge_[i][j]);
        }
        puts("");
    }
    
#else
    
    //puts("Printing adjacency list implemented graph");
    for(i = 0; i < g->nnodes_; i++) {
        S_Node *walker = g->adj_list_[i].head_;
        printf("%-5d", i);
        for(; walker != NULL; walker = walker->next_) {
			int dest = (int)(*((int*)walker->content_));
            printf("%5d(%d)", dest, g->weight_[i][dest]);
		}
        puts("");
    }
    
#endif
}
