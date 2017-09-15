/*
 * bst.h
 * 
 * Implementation of the Binary Search Tree data structure.
 */

#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <inttypes.h>

typedef uint16_t key_t;

/* BST node */
typedef struct bst_node {
	key_t _key;	// Unique key for each node
	void *_content;	// User defined type content
	struct bst_node *_left, *_right;
} BST_Node;

/* Creates and returns a new BST_Node node with the provided 'key' and 'data'	*/
BST_Node *new_node(key_t key, void *data, size_t size);

/* Inserts a new BST_Node to the tree rooted at 'root'	*/
int insert_node(BST_Node **root, BST_Node *node);

/* Removes a node from the tree which has the key 'key'		*/
int delete_node_by_key(BST_Node *root, key_t key);

/* Displays the tree keys by traversing in pre-order manner 	*/
void print_preorder(BST_Node *root);

/* Displays the tree keys by traversing in in-order manner 	*/
void print_inorder(BST_Node *root);

/* Displays the tree keys by traversing in post-order manner 	*/
void print_postorder(BST_Node *root);

#endif
