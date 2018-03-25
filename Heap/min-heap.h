#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <iostream>
#include <climits>
#include <typeinfo>
#include <map>

// A Huffman tree node as a min heap node
template <typename T, typename FrequencyValType>
struct MinHeapNode {
	T data;			 // One of the input characters
	FrequencyValType freq;			 // No of occurences of the object type T
	MinHeapNode *left, *right; // Left and right child
	bool m_isInternalNode;

	MinHeapNode(T data, FrequencyValType freq, bool isInternalNode = false)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
		m_isInternalNode = isInternalNode;
	}

	// Useful by Huffman tree algorithm
	inline bool isInternalNode() {
		return m_isInternalNode;
	}

	// Utility function to check if this node is leaf
	inline bool isLeaf() {
	    return !left && !right;
	}

	// Print the data members
	// XXX... the member 'T data' must be printable by << operator
	void printContents() {
		std::cout << "-------------------------" << std::endl;
		std::cout << "(" << typeid(data).name() << ") data = " << data
			<< std::endl << "(" << typeid(freq).name() << ") freq = " << freq
			<< std::endl << "left = " << left
			<< std::endl << "right =" << right
			<< std::endl;
	}
};

// A Min Heap:  Collection of min heap (or Hufmman tree) nodes
template <typename T, typename U>
class MinHeap {
private:
    //@@@ int m_size;    // Current size of min heap
    //@@@ int m_capacity;   // capacity of min heap
    std::map<MinHeapNode<T, U>*> *m_array;  // Array/vector of minheap node pointers

	// Allocate and return a new min heap node with given data(symbol)
	// and frequency of the character
	inline MinHeapNode<T, U>* newNode(const T& data, const U& freq, bool internal = false);

	// The standard minHeapify function.
	// idx -> Index of the first node at which the minHeapify()
	// 		  algorithm will begin.
	void minHeapify(int idx);

	// A utility function to swap two min heap nodes by array index
	void swap(int index1, int index2);

public:

	MinHeap() {
		  m_array = new std::map<MinHeapNode<T, U>*>();
	}

	~MinHeap() {
		m_array->clear();
		delete m_array;
	}

	// Returns no of elements
	inline int size() {
		return m_array->size();
	}

	// Returns current capacity
	inline int capacity() {
		return m_array->capacity();
	}

	// Insert a new node to Min Heap
	void insertNode(const T& data, const U& freq);

	// Print the content of m_array[][]
	void printArray() {
		if(m_array->size() == 0)
			throw 20;
		for(MinHeapNode<T, U>* x : *m_array)
			x->printContents();
	}

	// Returns the 0th MinHeapNode pointer from *m_array[] and removes it
	// from the array. The array is then heapified again.
	MinHeapNode<T, U>* extractMin();

	// Build the min heap into m_array using bottom-up approach
	void buildMinHeap();
};


/* ============================= Definitions ================================ */

// Allocate a new min heap node with given character
// and frequency of the character
template <typename T, typename U>
inline MinHeapNode<T, U>*
	MinHeap<T, U> :: newNode(const T& data, const U& freq, bool internal)
{
    MinHeapNode<T, U>* temp = new MinHeapNode<T, U>(data, freq, internal);
    return temp;
}

// A utility function to swap two min heap nodes by array index
template <typename T, typename U>
void MinHeap<T, U> :: swap(int index1, int index2) {
	if((index1 < 0) || (index2 < 0))
		throw 20;
    MinHeapNode<T, U> *t = m_array->at(index1);
    m_array->at(index1) = m_array->at(index2);
    m_array->at(index2) = t;
}

// Insert a new node to Min Heap
template <typename T, typename U>
void MinHeap<T, U> :: insertNode(const T& data, const U& freq) {
    MinHeapNode<T, U> *n = newNode(data, freq);
    int i;

	if(m_array->size() == 0) { // XXX ... Careful with delete() implementation
		m_array->at(0) = n;
		return;
	}

	i = m_array->size();
    while ((i > 0) && (n->freq < m_array->at((i - 1)/2)->freq)) {
        m_array->at(i) = m_array->at((i - 1)/2);
        i = (i - 1) / 2;
    }
    m_array->at(i) = n;
}

// The standard minHeapify function.
// idx -> Index of the first node at which the minHeapify()
// 		  algorithm will begin.
template <typename T, typename U>
void MinHeap<T, U> :: minHeapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < m_array->size() &&
        m_array->at(left)->freq < m_array->at(smallest)->freq)
      smallest = left;

    if (right < m_array->size() &&
        m_array->at(right)->freq < m_array->at(smallest)->freq)
      smallest = right;

    if (smallest != idx) {
		swap(smallest, idx);
        minHeapify(smallest);
    }
}

// Returns the 0th MinHeapNode pointer from *m_array[] and removes it
// from the array. The array is then heapified again.
template <typename T, typename U>
MinHeapNode<T, U>* MinHeap<T, U> :: extractMin() {
    MinHeapNode<T, U>* ret = m_array->at(0);
    m_array->at(0) = m_array->at(m_array->size() - 1);
    minHeapify(0);
    return ret;
}

// Build the min heap into m_array using bottom using bottom-up approach
template <typename T, typename U>
void MinHeap<T, U> :: buildMinHeap() {
	if(m_array->size() == 0)
		throw "[Error] Heap size = 0";
    int n = m_array->size() - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(i);
}

#endif
