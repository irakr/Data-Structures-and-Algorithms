/*
 * list.c
 * Definitions
 */

#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef enum{COPY, ORIGINAL} create_mode_t;

/* Create a S_Node object on the heap, initialize it with the proper content_ and return it.
 * 'mode' specifies whether just to copy the address of the original content to the content_ field of S_Node or
 * to make a new copy of the original content on the heap and assign its address to the content_ field of S_Node.
 * 'size' is relevant only if 'mode'==COPY
 */
static inline S_Node *new_node(void *content, size_t size, create_mode_t mode) {
    if(!content)
        return NULL;
    
    S_Node *node = malloc(sizeof(S_Node));
    if(!node)
        return NULL;
    
    void *copy = NULL;
    
    if(mode == COPY) {
    // Make a new copy of the content on the heap
        copy = calloc(1, size);
        if(!copy)
            return NULL;
    }
    else if(mode == ORIGINAL)
    // Copy the original content
        copy = content;
    
    node->content_ = copy;
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

int push(S_Head *head, void *content, size_t size) {
    if(!head || !content || (size <= 0)) {
        return -1;
    }
    
    S_Node *node = new_node(content, size, COPY);
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

void print_list_cb(void (*printer)(void*), S_Head *list) {
    if(!printer || !list)
        return;
    
    S_Node *walker = list->head_;
    for(; walker != NULL; walker = walker->next_) {
        printer(walker->content_);  // XXX... Trouble with interpreting back to 'Guitar' type.
    }
    
}
