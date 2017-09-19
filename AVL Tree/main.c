/*
 * main.c
 */

#include <stdio.h>
#include "avl.h"

/*	Just wrapper macros to make things easier */

#define insert_and_display(tree, key, data)										\
	do {																		\
		tree = AVL_insert_node(tree, new_node(key, (void*)&data, sizeof(char)));			\
		printf("[INSERTED %2d]: ", key);										\
		print_preorder(tree);													\
		puts("");																\
	} while(0);

#define delete_and_display(tree, key)										\
	do {																		\
		tree = AVL_delete_node_by_key(tree, key);											\
		printf("[DELETED %2d]: ", key);											\
		print_preorder(tree);													\
		puts("");																\
	} while(0);

int main() {
	int data = 55;
	AVL_Node *tree = NULL;
	
	insert_and_display(tree, 30, data);
	insert_and_display(tree, 5, data);
	insert_and_display(tree, 35, data);
	insert_and_display(tree, 32, data);
	insert_and_display(tree, 40, data);
	//insert_and_display(tree, 16, data);
	//insert_and_display(tree, 4, data);
	//insert_and_display(tree, 6, data);
	
	if(tree)
		printf("Root = %d\n", tree->_key);
	else
		printf("Tree is empty\n");
	
	printf("[Preorder]: ");
	print_preorder(tree);
	puts("");
	
	insert_and_display(tree, 45, data);
	
	return 0;
}
