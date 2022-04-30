//
// Created by boztu on 05/12/2021.
//

#ifndef PROJECT1_MAXHEAP_H
#define PROJECT1_MAXHEAP_H

const int MAX_MAXHEAP = 1000;

class MaxHeap {
public:
            MaxHeap     ();
    void    insert      (int value);    // inserts integer into heap
    int     peek        ();             // returns the value of the max element
    int     extractMax  ();             // retrieves and removes the max element
    int     size        ();             // returns the number of elements in the heap

protected:
    void heapRebuild(int root);

private:
    int items[MAX_MAXHEAP];
    int heapSize;
};


#endif //PROJECT1_MAXHEAP_H
