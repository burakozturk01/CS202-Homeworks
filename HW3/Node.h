//
// Created by boztu on 05/12/2021.
//

#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H

class Node {
public:
    Node(int keyValue);
    ~Node();
    int key;
    Node* left;
    Node* right;
    int height;
};


#endif //PROJECT2_NODE_H
