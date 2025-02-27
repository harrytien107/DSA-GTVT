// File: src/Node.h
#ifndef NODE_H
#define NODE_H

#include "Word.h"

class Node {
public:
    Word data;
    Node* left;
    Node* right;
    int height;

    Node(const Word& w)
        : data(w), left(nullptr), right(nullptr), height(1) {}
};

#endif // NODE_H