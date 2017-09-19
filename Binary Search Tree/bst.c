/*
 * bst.c
 */

#include "bst.h"
#include <stdlib.h>
#include <string.h>

/* (MACRO): Yield the max value of; a or b	*/
#define max(a, b)	(((a) > (b)) ? (a) : (b))

/*
 * (WRAPPER): To free() a BST_Node* including its _content.
 *
 * XXX Use this function only when you want to delete the node
 * perfectly, which includes the content too.
 * Otherwise, just use free();
 *
 */
static void release_node(BST_Node *node) {
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
	ret->_content_size = size;
	
	return ret;
	
}

/* 
 * Inserts a new BST_Node to the tree rooted at 'root'
 */
int insert_node(BST_Node **root, BST_Node *node) {
	
	if(!node)
		return -1;
	
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
}


/* Removes a node from the tree which has the key 'key'		*/
int delete_node_by_key(BST_Node **root, key_t key) {
	BST_Node *ptr = *root, *parent_ptr=NULL, *pred = NULL;
	if(ptr == NULL)
		return -1;
	
	/// Using iterative method
	
repeat:
	// Search for node and with the target key including its parent
	while(ptr) {
		if(key < ptr->_key) {
			parent_ptr = ptr;
			ptr = ptr->_left;
		}
		else if(key > ptr->_key) {
			parent_ptr = ptr;
			ptr = ptr->_right;
		}
		else break;
	}
	if(!ptr) { // Not found
		return -1;
	}
	
	// Apply the 3 cases of deletion.
	if(!ptr->_left && !ptr->_right) {		// CASE-1: No child nodes
		if(ptr == parent_ptr->_left)
			parent_ptr->_left = NULL;
		else
			parent_ptr->_right = NULL;
		release_node(ptr);
	}
	else if(ptr->_left && ptr->_right) {	// CASE-2: Two child nodes
		
		pred = largest_node(ptr->_left); // In-order predecessor
		
		// Copy the key and content of pred node to ptr node
		ptr->_key = pred->_key;
		ptr->_content = dup_content(pred->_content, pred->_content_size);
		
		// Modifying ptr, parent_ptr and key to be able to delete pred by repeating
		// the whole step again (Similar to recursion)
		parent_ptr = ptr;
		ptr = ptr->_left;
		key = pred->_key;
		goto repeat;
	}
	else {									// CASE-3: Any one child
	
		// If this node if the left child of its parent
		if(ptr == parent_ptr->_left) {
			// If this node has a left child only
			if(ptr->_left)
				parent_ptr->_left = ptr->_left;
			else
				parent_ptr->_left = ptr->_right;
		}
		else {
			if(ptr->_left)
				parent_ptr->_right = ptr->_left;
			else
				parent_ptr->_right = ptr->_right;
		}
	}
	
	return 0;
}

/* Returns a pointer to the lowest key'ed node, i.e., the leftmost node of the tree.	*/
BST_Node *smallest_node(BST_Node *root) {
	BST_Node *ptr = root;
	
	// If root is not empty
	if(ptr)
		while(ptr->_left)
			ptr = ptr->_left;
	
	return ptr;
}

/* Returns a pointer to the largest key'ed node, i.e., the rightmost node of the tree.	*/
BST_Node *largest_node(BST_Node *root) {
	BST_Node *ptr = root;
	
	// If root is not empty
	if(ptr)
		while(ptr->_right)
			ptr = ptr->_right;
	
	return ptr;
}

/*
 * Returns the no of edges from the root through the deepest level node.
 */
int height(BST_Node *root) {
	// Cancel out the +1 for the root node since it does not have any incoming edge
	int h = depth(root) - 1;
	if(h < 0) // In case of empty tree
		h = 0;
	return h;
}

/*
 * Returns the no of nodes from the root through the deepest level node.
 */
int depth(BST_Node *root) {
	if(!root)
		return 0;
	return max(depth(root->_left), depth(root->_right)) + 1;
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
