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
static inline S_Node *create_new_node(void *content, size_t size, create_mode_t mode) {
    if(!content)
        return NULL;
    
    S_Node *new_node = malloc(sizeof(S_Node));
    if(!new_node)
        return NULL;
    
    void *copy = NULL;
    
    if(mode == COPY) {
    // Make a new copy of the content on the heap
        copy = calloc(1, size);
        if(!copy)
            return NULL;
        memcpy(copy, content, size);
    }
    else if(mode == ORIGINAL)
    // Copy the original content
        copy = content;
    
    new_node->content_ = copy;
    new_node->content_len_ = size;
    new_node->next_ = NULL;
    return new_node;
}

/* Cleanup resources */
static inline void cleanup() {

}

void init_head(S_List *head) {
    if(!head) {
        return;
    }
    memset(head, '\0', sizeof(*head));
    
    atexit(cleanup);    //XXX Try using on_exit() instead
}

int push(S_List *head, void *content, size_t size) {
    if(!head || !content || (size <= 0)) {
        return -1;
    }
    
    S_Node *new_node = create_new_node(content, size, COPY);
    if(!new_node) {
        return -1;
    }
    
    
    // Empty list condition
    if(!(head->head_))
        head->head_ = head->tail_ = new_node;
    else {  // Filled list condition
        head->tail_->next_ = new_node;
        head->tail_ = new_node;
    }
    head->nnodes_++;
    
    return 0;
}

S_Node *remove_node(S_List *head, uint32_t index) {
    S_Node *ret = NULL;
    S_Node *current_node, *next_node = NULL;
    uint32_t temp_index = index;
    
    if(!head || index < 0 || index >= head->nnodes_)
        return NULL;
    
    // If there are no nodes in the list.    
    if(head->nnodes_ == 0)
        return ret;

    // If only 1 node in the list.
    if(head->nnodes_ == 1) {
        ret = head->head_;
        head->head_ = head->tail_ = NULL;
        head->nnodes_--;
        return ret;
    }
    
    // For all other case.
    for(current_node = head->head_; current_node && (temp_index > 0); current_node = current_node->next_,--temp_index) {
        next_node = current_node;
    }
    
    ret = current_node; // Node to be removed from the list.
    
    // If index was 0.
    if(!next_node)
        head->head_ = head->head_->next_;
    else { //else if index > 0.
        next_node->next_ = current_node->next_;
        // If index was for last node,i.e., head->nnodes-1.
        if(current_node == head->tail_)
            head->tail_ = next_node;
    }
    current_node->next_ = NULL;
    
    head->nnodes_--;
    return ret;
}

int reverse_list(S_List *head) {
    S_Node *prev_node = NULL, *current_node = NULL, *next_node = NULL,
        *first_node = NULL, *last_node = NULL;
    
    if(!head)
        return -1;

    // If empty list.
    if(!head->head_)
        return 0;

    // If everything goes well then we will set head->head_ and head->tail_
    // to the these values.
    first_node = head->tail_;
    last_node = head->head_;

    current_node = head->head_;
    next_node = current_node->next_;
    while(current_node) {
        current_node->next_ = prev_node; // Flip the next pointer.
        
        // Move forward all 3 pointers.
        prev_node = current_node;
        current_node = next_node;
        next_node = (next_node) ? next_node->next_ : NULL;
    }
    head->head_ = first_node;
    head->tail_ = last_node;

    return 0;
}

void print_list(S_List *head, void *first_content, size_t size) {
    if(!head || !first_content || (size <= 0)) {
        return;
    }
    
}

void print_list_cb(CallBack_Printer printer, S_List *list) {
    if(!printer || !list)
        return;
    
    S_Node *current_node = list->head_;
    for(; current_node != NULL; current_node = current_node->next_) {
        printer(current_node->content_);  // XXX... Trouble with interpreting back to 'Guitar' type.
    }
    puts("");
    
}

void destroy_list(S_List* list) {
    if(!list)
        return;
    printf("Destroying the list.\n");
    for(S_Node* ptr = list->head_; ptr != NULL; ptr = ptr->next_) {
        if(ptr)
            free(ptr);
    }
}

