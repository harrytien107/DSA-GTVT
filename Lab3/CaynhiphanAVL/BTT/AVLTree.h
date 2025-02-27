// File: src/AVLTree.h
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "Node.h"
#include <string>

using namespace std;
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(const Word& word);
    bool search(const string& english, string& vietnamese) const;
    bool modify(const string& english, const string& new_vietnamese);
    void inOrderTraversal() const;

private:
    Node* root;

    // Helper functions
    int getHeight(Node* node) const;
    int getBalance(Node* node) const;
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* node, const Word& word);
    Node* minValueNode(Node* node);
    Node* search(Node* node, const string& english) const;
    void inOrderTraversal(Node* node) const;
    void destroy(Node* node);
};

#endif // AVL_TREE_H