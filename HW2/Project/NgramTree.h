/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Header file for NgramTree class
*/

#ifndef PROJECT_NGRAMTREE_H
#define PROJECT_NGRAMTREE_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "BinarySearchTree.h"

class NgramTree {
public:
    NgramTree();
    NgramTree(NgramTree &otherNGT);
    ~NgramTree();
    void addNgram( std::string ngram );
    int getTotalNgramCount();
    bool isFull();
    bool isComplete();
    void generateTree( std::string fileName, int n );

private:
    BinarySearchTree* bst;

    friend std::ostream& operator<<( std::ostream& out, NgramTree &tree );
};


#endif //PROJECT_NGRAMTREE_H
