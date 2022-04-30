/*
* Title : Heaps and AVL Trees
* Author : Burak Ozturk
* ID : 21901841
* Section : 1
* Assignment : 3
* Description : MedianHeap implementation
*/

#include <iostream>
#include "MedianHeap.h"
#include "MaxHeap.h"
#include "MinHeap.h"

MedianHeap::MedianHeap() : heapSize(0) {}

void MedianHeap::insert(int value) {
    if (heapSize >= MAX_MEDIANHEAP) {
        std::cout << "Heap full";
        return;
    }

    if (value > findMedian())
        minh.insert(value);
    else
        maxh.insert(value);
    ++heapSize;

    balance();
}

int MedianHeap::findMedian() {
    if (heapSize < 0) {
        std::cout << "Heap empty";
        return -2147483648;  // Error code
    }

    if (heapSize == 0)
        return 0;

    if (maxh.size() > minh.size())
        return maxh.peek();
    else
        return minh.peek();
}

void MedianHeap::balance() {
    if (maxh.size() - minh.size() > 1) {
        minh.insert(maxh.extractMax());
        balance(); // Recursion is actually not needed
    }
    else if (minh.size() - maxh.size() > 1) {
        maxh.insert(minh.extractMin());
        balance(); // Recursion is actually not needed
    }
}