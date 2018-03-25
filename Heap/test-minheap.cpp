#include <iostream>
#include "min-heap.h"

using namespace std;

typedef unsigned char byte;

int main() {
    MinHeap<byte, double> minheap;
    minheap.insertNode('a', 10.1);
    minheap.insertNode('b', 20.5);
    minheap.insertNode('c', 3.3);
    minheap.insertNode(127, 5.0);
    //minheap.insert('d', 5.3);
    minheap.printArray();
    MinHeapNode<byte, double> *min = minheap.extractMin();
    std::cout << " Min Node:\n";
    min->printContents();
    std::cout << " New heap array:\n";
    minheap.printArray();
    minheap.buildMinHeap();
    return 0;
}
