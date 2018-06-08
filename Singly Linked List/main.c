/*
 * main.c
 * Using the singly linked list implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void printer(void* arg) {
    int *val = (int*)arg;
    printf("%5d", *val);
}

#define PRINT_LIST(list) printf("\nThe list is ==>\n");     \
                         print_list_cb(printer, &list);

/*  main program    */
int main(int argc, char *argv[]) {
    S_Head list;
    init_head(&list);
    int val;
    
    while(1) {
        printf("Enter a value to be inserted(-1 to end): ");
        scanf("%d", &val);
        if(val == -1)
            break;
        push(&list, (void*)&val, sizeof(int));
    }

    PRINT_LIST(list);
    
    while(1) { 
        printf("Enter node index to be deleted(-1 to end): ");
        scanf("%d", &val);
        if(val == -1)
            break;
        S_Node *del_node = remove_node(&list, val);
        if(!del_node) {
            fprintf(stderr, "Error in remove_node(): Probably you have provided an invalid index.\n");
            return 0;
        }
        PRINT_LIST(list);
    }
    PRINT_LIST(list);
    return 0;
}
