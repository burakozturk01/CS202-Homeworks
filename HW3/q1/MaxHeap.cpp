/*
* Title : Heaps and AVL Trees
* Author : Burak Ozturk
* ID : 21901841
* Section : 1
* Assignment : 3
* Description : MaxHeap implementation
*/

#include <iostream>
#include "MaxHeap.h"

MaxHeap::MaxHeap() : heapSize(0) {}

void MaxHeap::insert(int value) {
    if (heapSize >= MAX_MAXHEAP) {
        std::cout << "Heap full";
        return;
    }

    items[heapSize] = value;

    int place = heapSize;
    int parent = (place - 1) / 2;
    while ( (place > 0) && (items[place] > items[parent]) ) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    ++heapSize;
}

int MaxHeap::peek() {
    if (heapSize <= 0) {
        std::cout << "Heap empty";
        return -2147483648;  // Error code
    }
    return items[0];
}

int MaxHeap::extractMax() {
    if (heapSize <= 0) {
        std::cout << "Heap empty";
        return -2147483648;  // Error code
    }
    int root = items[0];
    items[0] = items[--heapSize];
    heapRebuild(0);
    return root;
}

int MaxHeap::size() {
    return heapSize;
}

void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < heapSize) {
        int rightChild = child + 1;

        if ((rightChild < heapSize) && (items[rightChild] > items[child]))
            child = rightChild;

        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}
