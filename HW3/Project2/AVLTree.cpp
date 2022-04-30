//
// Created by boztu on 05/12/2021.
//

#include "AVLTree.h"
#include <iostream>

Node::Node(int keyValue) : key(keyValue), left(nullptr), right(nullptr), height(1) {}
Node::~Node() {
    delete left;
    delete right;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

AVLTree::AVLTree() : rotations(0), root(nullptr) {}
AVLTree::~AVLTree() {
    delete root;
}

Node* AVLTree::rightRotation(Node* node) { // node: k2 in the slides
    Node* k1 = node->left;
    Node* B = k1->right;

    k1->right = node;
    node->left = B;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;

    rotations++;

    return k1;
}

Node* AVLTree::leftRotation(Node* node) { // node: k1 in the slides
    Node* k2 = node->right;
    Node* B = k2->left;

    k2->left = node;
    node->right = B;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;

    rotations++;

    return k2;
}

int AVLTree::heightDifference(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::insert(int value) {
    root = insert(value, root);
}

Node* AVLTree::insert(int value, Node* node) {
    if (node == nullptr)
        return( new Node(value) );

    if (value < node->key)
        node->left = insert(value, node->left);
    else if (value > node->key)
        node->right = insert(value, node->right);
    else
        return node; // No duplicate items allowed

    int diff = heightDifference(node);

    if (diff > 1 && value < node->left->key)
        return rightRotation(node);

    else if (diff < -1 && value > node->right->key)
        return leftRotation(node);

    else if (diff > 1 && value > node->left->key)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    else if (diff < -1 && value < node->right->key)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return node;
}

int AVLTree::getNumberOfRotations() {
    return rotations;
}