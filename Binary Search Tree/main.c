/*
 * main.c
 */

#include <stdio.h>
#include "bst.h"

/*	Just wrapper macros to make things easier */

#define insert_and_display(tree, key, data)										\
	do {																		\
		insert_node(&tree, new_node(key, (void*)&data, sizeof(char)));			\
		printf("[INSERTED %2d]: ", key);										\
		print_preorder(tree);													\
		puts("");																\
	} while(0);

#define delete_and_display(tree, key)										\
	do {																		\
		delete_node_by_key(&tree, key);											\
		printf("[DELETED %2d]: ", key);											\
		print_preorder(tree);													\
		puts("");																\
	} while(0);
	
int main() {
	BST_Node *tree = NULL;
	char data = 'a';
	printf("Height = %d\n", height(tree));

	insert_and_display(tree, 10, data);
	insert_and_display(tree, 5, data);
	insert_and_display(tree, 4, data);
	insert_and_display(tree, 6, data);
	insert_and_display(tree, 15, data);
	insert_and_display(tree, 12, data);
	
	printf("Current Root = %d\n", tree->_key);
	printf("Height = %d\n", height(tree));

	//print_inorder(tree);
	puts("");
	
	delete_and_display(tree, 10);
	delete_and_display(tree, 5);
	delete_and_display(tree, 6);
	
	printf("Current Root = %d\n", tree->_key);
	//print_inorder(tree);
	
	puts("");
	
	return 0;
}
