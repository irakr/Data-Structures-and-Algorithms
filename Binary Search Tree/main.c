/*
 * main.c
 */

#include <stdio.h>
#include "bst.h"

int main() {
	BST_Node *tree = NULL;
	char data = 'a';
	insert_node(&tree, new_node(10, (void*)&data, sizeof(char)));
	insert_node(&tree, new_node(5, (void*)&data, sizeof(char)));
	insert_node(&tree, new_node(4, (void*)&data, sizeof(char)));
	insert_node(&tree, new_node(6, (void*)&data, sizeof(char)));
	insert_node(&tree, new_node(15, (void*)&data, sizeof(char)));
	insert_node(&tree, new_node(12, (void*)&data, sizeof(char)));
	
	print_inorder(tree);
	puts("");
	return 0;
}
