/*
 * avl.c
 */

#include "avl.h"
#include <stdlib.h>
#include <string.h>

/* (MACRO): Yield the max value of; a or b	*/
#define max(a, b)	(((a) > (b)) ? (a) : (b))

/*
 * (WRAPPER): To free() a AVL_Node* including its _content.
 *
 * XXX Use this function only when you want to delete the node
 * perfectly, which includes the content too.
 * Otherwise, just use free();
 *
 */
static void release_node(AVL_Node *node) {
	if(node->_content)
		free(node->_content);
	free(node);
}

/*
 * Returns a new content by allocating in the heap with the contents copied
 * from 'content'.
 */
static void* dup_content(void *content, size_t size) {
	void *ret = calloc(1, size);
	if(!ret)
		return ret;
	memcpy(ret, content, size);
	return ret;
}

/* Creates and returns a new AVL_Node node with the provided 'key' and 'data'	*/
AVL_Node *new_node(key_t key, void *data, size_t size) {
	AVL_Node *ret = (AVL_Node*)calloc(1, sizeof(AVL_Node));
	if(!ret)
		return ret;
	
	ret->_key = key;
	ret->_content = calloc(1, size);
	if(!ret->_content) {
		free(ret);
		return NULL;
	}
	memcpy(ret->_content, data, size);
	ret->_content_size = size;
	
	return ret;
}

/*	Insert a node by performing self-balancing mechanism	*/
AVL_Node *AVL_insert_node(AVL_Node *root, AVL_Node *node) {

	// Node insertion
	if(!root) {
		//root = node;
		return node;
	}
	if(node->_key < root->_key)
		root->_left = AVL_insert_node(root->_left, node);
	else
		root->_right = AVL_insert_node(root->_right, node);
	
	/// Balancing mechanism
	
	// Getting balance factor
	root->_balance_factor = depth(root->_left) - depth(root->_right);
	
	// (TODO) Perform appropriate rotations
	// CASE-1: Left heavy
	if(root->_balance_factor > 1) {
		
		// Since for left-heavy it is definitive that the child of the consequence node is its left child.
		// Although grandchild may be left or right and we have two sub-cases for them below.
		AVL_Node *child = root->_left; 
		
		// CASE-1.1: Left-Left
		if(node->_key < child->_key)
			root = rotate_right(root);
		
		// CASE-1.2: Left-Right
		else if(node->_key > child->_key) {
			root->_left = rotate_left(child);
			root = rotate_right(root);
		}
		
	}
	// CASE-2: Right heavy
	else if(root->_balance_factor < -1) {
		AVL_Node *child = root->_right;
		
		// CASE-2.1: Right-Right
		if(node->_key > child->_key)
			root = rotate_left(root);
		
		// CASE-2.2: Right-Left
		if(node->_key < child->_key) {
			root->_right = rotate_right(root->_right);
			root = rotate_left(root);
		}
		
	}
	// Otherwise, the tree is balanced
	
	// Update the balance factor
	root->_balance_factor = depth(root->_left) - depth(root->_right);
	
	return root;
}

/* (TODO) Delete a node by performing self-balancing mechanism		*/
AVL_Node *AVL_delete_node(AVL_Node *root, key_t key) {

}

/*	Rotate left the tree	*/
AVL_Node *rotate_left(AVL_Node *root) {
	if(!root)
		return root;
	
	AVL_Node *temp = root->_right->_left;
	root->_right->_left = root;
	root = root->_right;
	root->_left->_right = temp;
	
	return root;
}

/*	Rotate right the tree	*/
AVL_Node *rotate_right(AVL_Node *root) {
	if(!root)
		return root;
	
	AVL_Node *temp = root->_left->_right;
	root->_left->_right = root;
	root = root->_left;
	root->_right->_left = temp;
	
	return root;
}

/* Returns a pointer to the lowest key'ed node, i.e., the leftmost node of the tree.	*/
AVL_Node *smallest_node(AVL_Node *root) {
	AVL_Node *ptr = root;
	
	// If root is not empty
	if(ptr)
		while(ptr->_left)
			ptr = ptr->_left;
	
	return ptr;
}

/* Returns a pointer to the largest key'ed node, i.e., the rightmost node of the tree.	*/
AVL_Node *largest_node(AVL_Node *root) {
	AVL_Node *ptr = root;
	
	// If root is not empty
	if(ptr)
		while(ptr->_right)
			ptr = ptr->_right;
	
	return ptr;
}

/*
 * Returns the no of edges from the root through the deepest level node.
 */
int height(AVL_Node *root) {
	// Cancel out the +1 for the root node since it does not have any incoming edge
	int h = depth(root) - 1;
	if(h < 0) // In case of empty tree
		h = 0;
	return h;
}

/*
 * Returns the no of nodes from the root through the deepest level node.
 */
int depth(AVL_Node *root) {
	if(!root)
		return 0;
	return max(depth(root->_left), depth(root->_right)) + 1;
}

/* Displays the tree keys by traversing in pre-order manner 	*/
void print_preorder(AVL_Node *root) {
	if(root) {
		printf("%4u", root->_key);
		print_preorder(root->_left);
		print_preorder(root->_right);
	}
}

/* Displays the tree keys by traversing in in-order manner 	*/
void print_inorder(AVL_Node *root) {
	if(root) {
		print_inorder(root->_left);
		printf("%4u", root->_key);
		print_inorder(root->_right);
	}
}

/* Displays the tree keys by traversing in post-order manner 	*/
void print_postorder(AVL_Node *root) {
	if(root) {
		print_postorder(root->_left);
		print_postorder(root->_right);
		printf("%4u", root->_key);
	}
}
