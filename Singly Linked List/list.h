/*
 * list.h
 * Declarations.
 */

#ifndef S_LINKED_LIST_H
#define S_LINKED_LIST_H

#include <stdio.h>

/* A singly linked list node data type */
typedef struct s_node {
    void *content_;
    struct s_node *next_;
} S_Node;

/* Data type for head pointer of a singly linked list */
typedef struct s_head {
    S_Node *head_, *tail_; // Optional 'tail' pointer for quick reference to the tail node.
} S_Head;


/* Initialize a list head 
 * (XXX) For safety, always do this when creating a new S_Head in your program.
 */
void init_head(S_Head *head);

/* Create a node with its content_ as the arg-2 and push it to the tail  */
int push(S_Head*, void*);

/* Traverse through the list linearly while printing the content's ID of each node */
/*
 * Arg-1 : List head pointer.
 * Arg-2 : Pointer to the content in the first node.
 * Arg-3 : sizeof(content_type)
 */
void print_list(S_Head*, void*, size_t); //TODO... This is a little tricky to implement.

/* Similar to print_list() except using a callback function which is capable of printing the contents of that type. */
void print_list_cb(void (*printer)(void*));

#endif
