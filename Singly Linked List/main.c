/*
 * main.c
 * Using the singly linked list implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) {
    S_Head list1;
    init_head(&list1);
    
    push(&list1, (void*)10);
    push(&list1, (void*)20);
    push(&list1, (void*)30);
    push(&list1, (void*)40);
    
	return 0;
}
