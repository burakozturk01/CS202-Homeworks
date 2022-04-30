/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Source file for custom TreeNode class
*/

#include <string>
#include <iostream>
#include <sstream>
#include "KeyedItem.h"

#include "TreeNode.h"

TreeNode::TreeNode() {
    //std::cout << "emptynodecreate\n";

}
TreeNode::TreeNode(KeyedItem& nodeItem, TreeNode *left, TreeNode *right)
                 : item(nodeItem), leftChildPtr(left), rightChildPtr(right){
}
TreeNode::TreeNode(TreeNode * &otherTreeNode) {
    if (otherTreeNode != nullptr) {
        item = KeyedItem(otherTreeNode->item);

        if (otherTreeNode->leftChildPtr != nullptr)
            leftChildPtr = new TreeNode(otherTreeNode->leftChildPtr);
        else
            leftChildPtr = nullptr;
        if (otherTreeNode->rightChildPtr != nullptr)
            rightChildPtr = new TreeNode(otherTreeNode->rightChildPtr);
        else
            rightChildPtr = nullptr;
    }
}
TreeNode::~TreeNode() {
    delete leftChildPtr;
    delete rightChildPtr;
}

std::string to_string(int n) {
	std::ostringstream stm ;
    stm << n ;
    return stm.str();
}

std::string TreeNode::representation() {
    std::string repr = "\"";
    repr += item.getKey();
    repr += "\" appears ";
    repr += std::to_string(item.getCount());
    repr += " time(s)\n";
    return repr;
}