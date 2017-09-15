/*
 * bst.c
 */

#include "bst.h"
#include <stdlib.h>
#include <string.h>

/* Creates and returns a new BST_Node node with the provided 'key' and 'data'	*/
BST_Node *new_node(key_t key, void *data, size_t size) {
	BST_Node *ret = (BST_Node*)calloc(1, sizeof(BST_Node));
	if(!ret)
		return ret;
	
	ret->_key = key;
	ret->_content = calloc(1, size);
	if(!ret->_content) {
		free(ret);
		return NULL;
	}
	memcpy(ret->_content, data, size);
	
	return ret;
	
}

/* 
 * Inserts a new BST_Node to the tree rooted at 'root'
 */
int insert_node(BST_Node **root, BST_Node *node) {
	
	if(!node)
		return -1;
	
#ifdef RECURSIVE
	// Recursive implementation here (TODO)
#else
	
	BST_Node *ptr = *root, *parent_ptr = NULL;
	
	// For empty tree
	if(!ptr) {
		*root = node;
		return 0;
	}
	
	// For non-empty tree
	while(ptr) {
		if(node->_key < ptr->_key) {
			parent_ptr = ptr;
			ptr = ptr->_left;
		}
		else { // >=
			parent_ptr = ptr;
			ptr = ptr->_right;
		}
	}
	if(node->_key < parent_ptr->_key)
		parent_ptr->_left = node;
	else
		parent_ptr->_right = node;
	
	return 0;
	
#endif
}

/* Removes a node from the tree which has the key 'key'		*/
int delete_node_by_key(BST_Node *root, key_t key) {
}

/* Displays the tree keys by traversing in pre-order manner 	*/
void print_preorder(BST_Node *root) {
	if(root) {
		printf("%4u", root->_key);
		print_preorder(root->_left);
		print_preorder(root->_right);
	}
}

/* Displays the tree keys by traversing in in-order manner 	*/
void print_inorder(BST_Node *root) {
	if(root) {
		print_inorder(root->_left);
		printf("%4u", root->_key);
		print_inorder(root->_right);
	}
}

/* Displays the tree keys by traversing in post-order manner 	*/
void print_postorder(BST_Node *root) {
	if(root) {
		print_postorder(root->_left);
		print_postorder(root->_right);
		printf("%4u", root->_key);
	}
}
