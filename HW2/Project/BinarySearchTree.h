/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Header file for custom BinarySearchTree class
*/

#ifndef PROJECT_BINARYSEARCHTREE_H
#define PROJECT_BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <cstring>

#include "TreeNode.h"
#include "KeyedItem.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(BinarySearchTree * &otherBST);
    ~BinarySearchTree();

    bool isEmpty() const;

    void searchTreeInsert(KeyedItem &newItem);
    void searchTreeDelete(std::string searchKey);

    std::string inorderTraverse();

    int nodeCount();

protected:
    void insertItem(TreeNode * &treePtr, KeyedItem& item);

    void deleteItem(TreeNode * &treePtr, std::string searchKey);
    void deleteNodeItem(TreeNode * &nodePtr);
    void processLeftmost(TreeNode * &nodePtr, KeyedItem& item);

    void inorderTraverse_(TreeNode * &treePtr, std::string &str);

    std::string heightPattern_(TreeNode * &treePtr);
    std::string heightPattern();

    int nodeCount_(TreeNode * &treePtr);

private:
    TreeNode *root;

    int stringComparison(std::string s1, std::string s2);
    void upperCaser(std::string &mixedCaseString);

    friend class NgramTree;
};

#endif //PROJECT_BINARYSEARCHTREE_H
