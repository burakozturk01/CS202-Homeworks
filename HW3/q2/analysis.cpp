/*
* Title : Heaps and AVL Trees
* Author : Burak Ozturk
* ID : 21901841
* Section : 1
* Assignment : 3
* Description : Implementation of AVLTree rotation analysis function
*/

#include "analysis.h"
#include <iostream>
#include <random>

void rotationAnalysis() {
    // AVLTrees
    AVLTree *a[10], *b[10], *c[10];

    // Rotation count arrays
    int ra[10], rb[10], rc[10];

    // Initialize all AVLTrees
    for (int i = 0; i < 10; ++i) {
        a[i] = new AVLTree();
        b[i] = new AVLTree();
        c[i] = new AVLTree();
    }

    // Part a
    int *randomNumbers = new int[10000];

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(1, 100000);

    for (int i = 0; i < 10000; ++i)
        randomNumbers[i] = distr(generator);

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= i * 1000; ++j)
            a[i - 1]->insert(randomNumbers[j-1]);
        ra[i - 1] = a[i - 1]->getNumberOfRotations();
        delete a[i - 1];
    }

    delete[] randomNumbers;

    // Part b
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= i * 1000; ++j)
            b[i - 1]->insert(j-1);
        rb[i - 1] = b[i - 1]->getNumberOfRotations();
        delete b[i - 1];
    }

    // Part c
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < i * 1000; ++j)
            c[i - 1]->insert(100000 - j);
        rc[i - 1] = c[i - 1]->getNumberOfRotations();
        delete c[i - 1];
    }

    // Table printing

    std::cout << "| Array Size | Random | Ascending | Descending|\n";
    std::cout << "|------------|--------|-----------|-----------|\n";

    for (int i = 0; i < 10; ++i) {
        if (!i)
            std::cout << "|       " << (i+1)*1000 << " |    " << ra[i] << " |       " << rb[i] << " |        " << rc[i] << "|" << std::endl;
        else if (i == 9)
            std::cout << "|      " << (i+1)*1000 << " |   " << ra[i] << " |      " << rb[i] << " |       " << rc[i] << "|" << std::endl;
        else
            std::cout << "|       " << (i+1)*1000 << " |   " << ra[i] << " |      " << rb[i] << " |       " << rc[i] << "|" << std::endl;
    }
}