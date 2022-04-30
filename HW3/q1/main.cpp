/*
* Title : Heaps and AVL Trees
* Author : Burak Ozturk
* ID : 21901841
* Section : 1
* Assignment : 3
* Description : Driver function of heap part of Homework 3
*/

#include <iostream>
#include <random>

#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

using namespace std;

int main() {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(1.0, 100.0);

    cout << "---------- MAX HEAP ----------\n\n";
    MaxHeap maxh;

    for (int i = 0; i < 10; ++i) {
        maxh.insert((int)dist(mt));
    }

    for (int i = 0; i < 10; ++i) {
        cout << "size1:    "    << maxh.size()        << endl;
        cout << "peek1:   "     << maxh.peek()        << endl;
        cout << "extract: "     << maxh.extractMax()  << endl;
        cout << "peek2:   "     << maxh.peek()        << endl;
        cout << "size2:    "    << maxh.size()        << endl << endl;
    }

    cout << "after emptying: " << maxh.peek() << " - " << maxh.extractMax();

    cout << "\n\n---------- MIN HEAP ----------\n\n";

    MinHeap minh;

    for (int i = 0; i < 10; ++i) {
        minh.insert((int)dist(mt));
    }

    for (int i = 0; i < 10; ++i) {
        cout << "size1:    "    << minh.size()        << endl;
        cout << "peek1:   "     << minh.peek()        << endl;
        cout << "extract: "     << minh.extractMin()  << endl;
        cout << "peek2:   "     << minh.peek()        << endl;
        cout << "size2:    "    << minh.size()        << endl << endl;
    }

    cout << "after emptying: " << minh.peek() << " - " << minh.extractMin();

    cout << "\n\n---------- MEDIAN HEAP ----------\n\n";

    MedianHeap medh;

    const int SIZE = 20;

    int randInts[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        randInts[i] = (int)dist(mt);
    }

    cout << randInts[0];
    for (int i = 1; i < SIZE; ++i) {
        cout << ", " << randInts[i];
    }
    cout << "\n\n";

    for (int i = 0; i < SIZE; ++i) {
        medh.insert(randInts[i]);
        cout << "Inserted: " << randInts[i] << endl;
        cout << "Current median: " << medh.findMedian() << endl << endl;
    }

    cout << "Final median: " << medh.findMedian() << endl << endl;

    return 0;
}