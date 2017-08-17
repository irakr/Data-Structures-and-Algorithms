/*
 * list.c
 * Definitions
 */

#include "list.h"
#include <stdlib.h>
#include <string.h>

static inline S_Node *new_node(void *content) {
    if(!content) {
        return NULL;
    }
    
    S_Node *node = malloc(sizeof(S_Node));
    node->content_ = content;
    node->next_ = NULL;
    return node;
}

/* Cleanup resources */
static inline void cleanup() {

}

void init_head(S_Head *head) {
    if(!head) {
        return;
    }
    memset(head, '\0', sizeof(*head));
    
    atexit(cleanup);    //XXX Try using on_exit() instead
}

int push(S_Head *head, void *content) {
    if(!head || !content) {
        return -1;
    }
    
    S_Node *node = new_node(content);
    if(!node) {
        return -1;
    }
    
    // Empty list condition
    if(!(head->head_))
        head->head_ = head->tail_ = node;
    else {  // Filled list condition
        head->tail_->next_ = node;
        head->tail_ = node;
    }
    
    return 0;
}

void print_list(S_Head *head, void *first_content, size_t size) {
    if(!head || !first_content || (size <= 0)) {
        return;
    }
    
}

void print_list_cb(void (*printer)(void*)) {
    if(printer == NULL)
        return;
}
