//
// Created by boztu on 05/12/2021.
//

#ifndef PROJECT1_MINHEAP_H
#define PROJECT1_MINHEAP_H

const int MAX_MINHEAP = 1000;

class MinHeap {
public:
    MinHeap     ();
    void    insert      (int value);    // inserts integer into heap
    int     peek        ();             // returns the value of the max element
    int     extractMin  ();             // retrieves and removes the max element
    int     size        ();             // returns the number of elements in the heap

protected:
    void heapRebuild(int root);

private:
    int items[MAX_MINHEAP];
    int heapSize;
};


#endif //PROJECT1_MINHEAP_H
