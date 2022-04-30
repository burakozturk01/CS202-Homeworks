/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Header file for custom TreeNode class
*/

#ifndef PROJECT_TREENODE_H
#define PROJECT_TREENODE_H

#include <string>
#include <iostream>

#include "KeyedItem.h"

class TreeNode {
private:
    TreeNode();

    TreeNode(KeyedItem& nodeItem, TreeNode *left  = nullptr,
                                  TreeNode *right = nullptr);
    TreeNode(TreeNode * &otherTreeNode);
    ~TreeNode();

    std::string representation();

    KeyedItem     item;
    TreeNode     *leftChildPtr;
    TreeNode     *rightChildPtr;

    friend class BinarySearchTree;

};

#endif //PROJECT_TREENODE_H
