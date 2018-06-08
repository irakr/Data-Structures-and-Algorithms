/*
 * main.c
 * Try out BFS graph algorithm.
 */

#include <stdio.h>
#include "queue.h"

void my_printer(void *arg) {
    char *data = (char*)arg;
    printf("%c", *data);
}

int main() {
    
    /* Testing queue    */
    
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
    
    //****************************************************************
    
    
    return 0;
}
