#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "Node.h"
class AVL_tree
{
public:
    AVL_tree() : root(nullptr) {}
    virtual ~AVL_tree();
    Node *Getroot() { return root; }
    void Setroot(Node *val) { root = val; }
    bool InsertNode(Node *);
    Node *InsertNode(Node *, Node *);
    void InsertNodeRe(Node *);
    void deleteNode(Node *);
    // void TravelNLR();
    // void TravelLNR();
    // void TravelLRN();
    // void NLR(Node *);
    // void LNR(Node *);
    // void LRN(Node *);
    // void LeftRotate(Node *&);
    // void RightRotate(Node *&);
    int CheckBal(Node *);
    int GetHeight(Node *);

    void deleteNodeRe(Node*);
    Node* deleteNode(Node* root, int key);
    Node* search_x(int, int&);
    void printAVL(Node* node, int indent) ;
    void printAVLTree() ;

    void insert(const Student& student);
    void deleteNode(int key);
    bool search(int key);
    void LNR(Node* root);
    void TravelLNR();
    void NLR(Node* root);
    void TravelNLR();

protected:
private:
    Node *root;
    int getHeight(Node* p);
    int checkBalance(Node* p);
    void rotateLeft(Node*& x);
    void rotateRight(Node*& y);
    Node* insert(Node* node, const Student& student);
    bool search(Node* root, int key);

};
#endif // AVL_TREE_H