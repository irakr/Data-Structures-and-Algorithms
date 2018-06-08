/*
 * list.h
 * Declarations.
 */

#ifndef S_LINKED_LIST_H
#define S_LINKED_LIST_H

#include <stdio.h>
#include <stdint.h>

/* A singly linked list node data type */
typedef struct s_node {
    void *content_;
    size_t content_len_;
    struct s_node *next_;
} S_Node;

/* Data type for head pointer of a singly linked list */
typedef struct s_head {
    uint32_t nnodes_;
    S_Node *head_, *tail_;
} S_Head;


/* Initialize a list head 
 * (XXX) For safety, always do this when creating a new S_Head in your program.
 */
void init_head(S_Head *head);

/* Create a node with its content_ as the arg-2 and push it to the tail.
 * Arg-3 is the size of the void data which is required to let push() be
 * able to create a new copy of the actual content and store it in the new node.
 */
int push(S_Head*, void*, size_t);

/* 
 * Delete the node at specified location/index and also deallocate the memory occupied
 * by the node.
 * Also return the copy of the deleted node.
 */
S_Node *remove_node(S_Head*, uint32_t);

/* Traverse through the list linearly while printing the content's ID of each node */
/*
 * Arg-1 : List head pointer.
 * Arg-2 : Pointer to the content in the first node.
 * Arg-3 : sizeof(content_type)
 */
void print_list(S_Head*, void*, size_t); //TODO... This is a little tricky to implement.

typedef void (*CallBack_Printer)(void*);
/* Similar to print_list() except using a callback function which is
 * capable of printing the contents of that type.
 */
void print_list_cb(CallBack_Printer, S_Head*);

#endif
