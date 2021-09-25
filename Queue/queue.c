#include <stdlib.h>
#include "queue.h"

Queue* new_queue(void) {
    Queue *ret = calloc(1, sizeof(Queue));
    if(!ret)
        return NULL;
    
    return ret;
}

int enqueue(Queue *queue, void *data, size_t size) {
    if(!queue || (queue->nnodes_ == QUEUE_MAXSIZE))
        return -1;
    
    // Store the copy of the data in the queue.
    push((S_List*)queue, data, size);
    
    return 0;
}

// TODO....First implement node deletion in list library.
S_Node* dequeue(Queue *queue) {
    return remove_node((S_List*)queue, 0);
}

void print_queue(Queue *queue, CallBack_Printer printer) {
    print_list_cb(printer, (S_List*)queue);
}
