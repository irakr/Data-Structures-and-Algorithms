/*
 * avl.h
 *
 * Implementation of the AVL tree.
 */

#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <inttypes.h>

typedef uint16_t key_t;

// Data type for an AVL tree node
typedef struct avl_node {
	key_t _key;
	int8_t _balance_factor;
	void *_content;
	size_t _content_size;
	struct avl_node *_left, *_right;
} AVL_Node;

/* Creates and returns a new AVL_Node node with the provided 'key' and 'data'	*/
AVL_Node *new_node(key_t key, void *data, size_t size);

/*	Insert a node by performing self-balancing mechanism	*/
AVL_Node *AVL_insert_node(AVL_Node *root, AVL_Node *node);

/* Delete a node by performing self-balancing mechanism		*/
AVL_Node *AVL_delete_node(AVL_Node *root, key_t key);

/*	Rotate left the tree	*/
AVL_Node *rotate_left(AVL_Node *root);

/*	Rotate right the tree	*/
AVL_Node *rotate_right(AVL_Node *root);

/* Returns a pointer to the lowest key'ed node, i.e., the leftmost node of the tree.	*/
AVL_Node *smallest_node(AVL_Node *root);

/* Returns a pointer to the largest key'ed node, i.e., the rightmost node of the tree.	*/
AVL_Node *largest_node(AVL_Node *root);

/*
 * Returns the no of edges from the root through the deepest level node.
 */
int height(AVL_Node *root);

/*
 * Returns the no of nodes from the root through the deepest level node.
 */
int depth(AVL_Node *root);

/* Displays the tree keys by traversing in pre-order manner 	*/
void print_preorder(AVL_Node *root);

/* Displays the tree keys by traversing in in-order manner 	*/
void print_inorder(AVL_Node *root);

/* Displays the tree keys by traversing in post-order manner 	*/
void print_postorder(AVL_Node *root);

#endif
