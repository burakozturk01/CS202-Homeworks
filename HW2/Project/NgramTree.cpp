/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Source file for NgramTree class
*              Uses a custom BST class to hold Ngrams
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "KeyedItem.h"
#include "NgramTree.h"

NgramTree::NgramTree() {
    bst = new BinarySearchTree();
}

NgramTree::NgramTree(NgramTree &otherNGT) {
    bst = otherNGT.bst;
}

NgramTree::~NgramTree() {
    delete bst;
}

// Pre-requisites:  All strings added with addNgram function directly must consist of only letters, not spaces
//                  and must have the same length with the ones BST currently holding.
void NgramTree::addNgram( std::string ngram ) {
    KeyedItem ki(ngram);
    bst->searchTreeInsert(ki);
}

int NgramTree::getTotalNgramCount() {
    return bst->nodeCount();
}

bool NgramTree::isComplete() {
    // Gets BST's height pattern to determine if it's complete.
    std::string pattern = bst->heightPattern();

    // Binary trees with 1 node and empty binary trees are full by definition, therefore complete.
    if (pattern == "" || pattern == " ")
        return true;

    // Assumes height sequence is monotone initially.
    bool monotone = true;

    for (int i = 1; pattern[i] != (char) 0; i++) {

        // If previous path's height < next path's height, then BST is not complete
        if (pattern[i-1] < pattern[i])
            return false;

        // From left to right height can decrease by one for only one time for tree to be complete.
        // First time makes monotone = false
        else if (pattern[i-1] == (pattern[i] + 1) && monotone)
            monotone = false;

        // Second decrease in height sequence means BST is not complete
        else if (pattern[i-1] == (pattern[i] + 1))
            return false;
    }
    return true;
}

bool NgramTree::isFull() {
    // Gets BST's height pattern to determine if it's complete.
    std::string pattern = bst->heightPattern();

    // Binary trees with 1 node and empty binary trees are full by definition.
    if (pattern.empty() || pattern == " ")
        return true;

    // If height sequence is monotone all the way from left to right, then BST is full.
    for (int i = 1; pattern[i] != (char) 0; i++) {
        if (pattern[i - 1] != pattern[i])
            return false;
    }
    return true;
}

// Prerequisites: Input file must start and end with a-z or A-Z, not space characters.
//                There can't be more than one space between two continuous sequence of characters.
void NgramTree::generateTree( std::string fileName, int n ) {
    if (n < 1) {
        std::cout << "Ngrams can't be shorter than 1\n";
        return;
    }

    if (!(bst->isEmpty())) {
        delete bst;
        bst = new BinarySearchTree();
    }

    std::string input;  // input will hold <fileName>'s contents.

    // Reads file into input : std::string
    std::ifstream f(fileName);
    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf();
        input = ss.str();
    }

    input += " ";

    // -- Slice input from strings and put to array --

    // Count space characters in inputs and add 1 to find word count
    int wordCount = 0;
    for (int i = 0; input[i] != (char) 0; ++i) {
        if (input[i] == ' ')
            wordCount++;
    }

    // String array
    std::string array[wordCount];

    // Put substrings to array
    for (int pos = 0, i = 0, len = 0; input[pos] != (char) 0; ++pos) {
        if (input[pos] == ' ') {
            array[i] = input.substr(pos-len, len);
            i++;
            len = 0;
        }
        else
            len++;
    }

    // Find Ngrams and add to the BST
    for (int i = 0; i < wordCount; ++i) {
        for (int j = 0; j < (array[i])[j+n-1] != (char) 0; ++j) {
            if ((array[i]).length() < n)
                continue;
            addNgram((array[i]).substr(j, n));
        }
    }


}

std::ostream& operator<<( std::ostream& out, NgramTree &tree ) {
    out << tree.bst->inorderTraverse();
    return out;
}