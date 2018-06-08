#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

#define QUEUE_MAXSIZE   512

/* A linked list based queue data structure.
 * See ../Singly\ Linked\ List/list.h for more info on S_Head.
 */
typedef S_Head Queue;

/*
 * Creates a new empty queue and returns a pointer to it.
 */
Queue* new_queue(void);

/*
 * Enqueue element to the queue.
 */
int enqueue(Queue*, void*, size_t);

/*
 * Dequeue element from the queue and return a pointer to that.
 */
S_Node* dequeue(Queue*);

/*
 * Prints all the elements of the queue on the screen.
 */
void print_queue(Queue *queue, CallBack_Printer);

#endif
