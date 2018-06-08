/*
 * bfs.c
 */

#include <stdlib.h>
#include "bfs.h"
#include "queue.h"

void bfs(Graph *G, uint32_t src) {
    Queue *queue = new_queue();
    uint32_t *visited = (uint32_t*)calloc(G->nnodes_, sizeof(uint32_t));
    uint32_t visits = 0;
    uint32_t i = src;
    
    visited[src] = 1;
    visits++;
    printf("%5d", src);
    
    while(visits < G->nnodes_) {
        for(uint32_t j=0; j < G->nnodes_; j++) {
            if(!visited[j] && G->edge_[i][j]) {
                visited[j] = 1;
                visits++;
                enqueue(queue, (void*)&j, sizeof(uint32_t));
            }
        }
        i = (uint32_t)(*((uint32_t*)dequeue(queue)->content_));
        printf("%5d", i);
    }
    
    // Now print the remaining elements in the queue.
    while(queue->nnodes_) {
        i = (uint32_t)(*((uint32_t*)dequeue(queue)->content_));
        printf("%5d", i);
    }
    puts("");
    
}
