/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Source file for custom BinarySearchTree class
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

#include "TreeNode.h"
#include "KeyedItem.h"

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree():root(nullptr) {
}
BinarySearchTree::BinarySearchTree(BinarySearchTree * &otherBST) {
    root = new TreeNode(otherBST->root);
}
BinarySearchTree::~BinarySearchTree() {
    delete root;
}

// Converts every lowercase char to uppercase by subtracting 32 by their integer value.
void BinarySearchTree::upperCaser(std::string &mixedCaseString) {
    for (int i = 0; ((int) mixedCaseString[i] ) != 0; ++i) {
        if (((int) mixedCaseString[i] ) >= 97)
            mixedCaseString[i] -= 32;
    }
}

// Compares two strings alphabetically and ignores case-sensitivity by upperCaser method.
int BinarySearchTree::stringComparison(std::string s1, std::string s2) {
    upperCaser(s1);
    upperCaser(s2);

    // Loop stops when either of strings reaches null terminator
    for (int i = 0; (((int) s1[i]) != 0) && (((int) s2[i]) != 0); ++i) {
        if (s1[i] < s2[i])
            return 1;       // Means s1 < s2 alphabetically
        else if (s1[i] > s2[i])
            return -1;      // Means s1 > s2 alphabetically
    }
    return 0;               // Means s1 = s2 alphabetically
}

bool BinarySearchTree::isEmpty() const {
    return (root == nullptr);
}

void BinarySearchTree::searchTreeInsert(KeyedItem &newItem) {
    insertItem(root, newItem);
}

// Unused and untested
void BinarySearchTree::searchTreeDelete(std::string searchKey) {
    deleteItem(root, searchKey);
}

// In-between function to hold a string for inorderTraverse_ to change upon.
std::string BinarySearchTree::inorderTraverse() {
    std::string s;
    inorderTraverse_(root, s);
    return s;
}

//
void BinarySearchTree::inorderTraverse_(TreeNode * &treePtr, std::string &str) {
    if (treePtr != nullptr) {                               // BST is empty

        if (treePtr->leftChildPtr != nullptr)               // If left child is not null, then traverse left child first.
            inorderTraverse_(treePtr->leftChildPtr, str);

        str += treePtr->representation();                   // Add current node's representation to str

        if (treePtr->rightChildPtr != nullptr)              // If right child is not null, then lastly traverse right child
            inorderTraverse_(treePtr->rightChildPtr, str);
    }
}

void BinarySearchTree::insertItem(TreeNode * &treePtr, KeyedItem& item) {
    if (treePtr == nullptr) {
        treePtr = new TreeNode(item, nullptr, nullptr);
    }
    else if (stringComparison(item.getKey(), treePtr->item.getKey()) == 0)
        treePtr->item.changeCount(1);
    else if (stringComparison(item.getKey(), treePtr->item.getKey()) > 0)
        insertItem(treePtr->leftChildPtr, item);
    else
        insertItem(treePtr->rightChildPtr, item);
}

void BinarySearchTree::deleteItem(TreeNode * &treePtr, std::string searchKey) {
    if (treePtr == nullptr)
        std::cout << "Delete failed\n";
    else if (stringComparison(searchKey, treePtr->item.getKey()) == 0)
        deleteNodeItem(treePtr);
    else if (stringComparison(searchKey, treePtr->item.getKey()) > 0)
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}

void BinarySearchTree::deleteNodeItem(TreeNode * &nodePtr){
    TreeNode *delPtr;
    KeyedItem replacementItem("");

    if ((nodePtr->leftChildPtr == nullptr) && (nodePtr->rightChildPtr == nullptr)) {
        delete nodePtr;
        nodePtr = nullptr;
    }
    else if (nodePtr->leftChildPtr == nullptr) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    else if (nodePtr->rightChildPtr == nullptr) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = nullptr;
        delete delPtr;
    }
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void BinarySearchTree::processLeftmost(TreeNode * &nodePtr, KeyedItem& item){
    if (nodePtr->leftChildPtr == nullptr) {
        item = nodePtr->item;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, item);
}

// In-between function to supply root to heightPattern_ as an argument
std::string BinarySearchTree::heightPattern() {
    return heightPattern_(root);
}

// Returns heights of every possible path of the BST represented with a string
// Used to determine if BST is complete/full
std::string BinarySearchTree::heightPattern_(TreeNode * &treePtr) {
    // Empty BST -> Empty string
    if (treePtr == nullptr) {
        return "";
    }

    // If the node is a leaf, then returns "  " meaning "00"
    else if (treePtr->leftChildPtr == nullptr && treePtr->rightChildPtr == nullptr) {
        return "  ";
    }

        // If the node only have the left child, the returns (<left's return> + " ") all increased by one.
    else if (treePtr->rightChildPtr == nullptr) {
        std::string s = " ";
        s = heightPattern_(treePtr->leftChildPtr) + s;
        for (int i = 0; ((int)s[i]) != 0; i++)
            s[i] += 1;
        return s;
    }

        // If the node only have the right child, the returns (" " + <right's return>) all increased by one.
    else if (treePtr->leftChildPtr == nullptr) {
        std::string s = " ";
        s = s + heightPattern_(treePtr->rightChildPtr);
        for (int i = 0; ((int)s[i]) != 0; i++)
            s[i] += 1;
        return s;
    }

        // If the node have both children, the returns (<left's return> + <right's return>) all increased by one.
    else {
        std::string s;
        s += heightPattern_(treePtr->leftChildPtr);
        s += heightPattern_(treePtr->rightChildPtr);
        for (int i = 0; ((int)s[i]) != 0; i++)
            s[i] += 1;
        return s;
    }
}

// In-between function to supply root to nodeCount_ as an argument
int BinarySearchTree::nodeCount() {
    return nodeCount_(root);
}

// Returns current node's count + left child's count + right child's count
int BinarySearchTree::nodeCount_(TreeNode * &treePtr) {
    if (treePtr == nullptr)
        return 0;
    else
        return treePtr->item.getCount() + nodeCount_(treePtr->leftChildPtr) + nodeCount_(treePtr->rightChildPtr);
}