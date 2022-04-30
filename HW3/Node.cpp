//
// Created by boztu on 05/12/2021.
//

#include "Node.h"

Node::Node(int keyValue) : key(keyValue), left(nullptr), right(nullptr), height(1) {}
Node::~Node() {
    delete left;
    delete right;
}