//
// Created by boztu on 05/12/2021.
//

#ifndef PROJECT2_AVLTREE_H
#define PROJECT2_AVLTREE_H

class Node {
public:
    Node(int keyValue);
    ~Node();
    int key;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b);

int getHeight(Node* node);

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int value); //inserts an element into the tree
    int getNumberOfRotations(); //returns the number of rotations performed so far while constructing the tree

private:
    Node* rightRotation(Node* node);
    Node* leftRotation(Node* node);

    int heightDifference(Node* node);

    Node* insert(int value, Node* node);

    Node* root;
    int rotations;
};


#endif //PROJECT2_AVLTREE_H
