/*
 * main.c
 * Try out BFS graph algorithm.
 */

#include <stdio.h>
#include "graph.h"
#include "bfs.h"
#include "queue.h"

void my_printer(void *arg) {
    char *data = (char*)arg;
    printf("%c", *data);
}

int main() {
    
    /* Testing queue 
    
    Queue * queue = new_queue();
    size_t size = sizeof(char);
    char m[] = "IRAK";
    enqueue(queue, (void*)m, size);
    enqueue(queue, (void*)(m+1), size);
    enqueue(queue, (void*)(m+2), size);
    enqueue(queue, (void*)(m+3), size);
    print_queue(queue, my_printer);
    S_Node *node = dequeue(queue);
    printf("Dequeued element = ");
    my_printer(node->content_);
    puts("");
    print_queue(queue, my_printer);
    
    ****************************************************************
    */
    
    /* Testing BFS algorithm */
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
    
    puts("Input graph G = \n");
    print_graph(G);
    
    puts("Displaying BFS traversal node trace:");
    bfs(G, 0);

    //**************************************************************

    return 0;
}
