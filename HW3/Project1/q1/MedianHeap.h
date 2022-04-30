//
// Created by boztu on 05/12/2021.
//

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
