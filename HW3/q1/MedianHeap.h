/*
* Title : Heaps and AVL Trees
* Author : Burak Ozturk
* ID : 21901841
* Section : 1
* Assignment : 3
* Description : MedianHeap declaration
*/

#ifndef PROJECT1_MEDIANHEAP_H
#define PROJECT1_MEDIANHEAP_H

#include "MaxHeap.h"
#include "MinHeap.h"

const int MAX_MEDIANHEAP = 2000;

class MedianHeap {
public:
    MedianHeap     ();
    void    insert      (int value);    // inserts integer into heap
    int     findMedian  ();             // returns the value of the median

private:
    MaxHeap maxh;
    MinHeap minh;
    int heapSize;
    void balance();
};


#endif //PROJECT1_MEDIANHEAP_H
