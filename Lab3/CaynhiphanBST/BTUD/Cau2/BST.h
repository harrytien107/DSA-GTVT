#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>
using namespace std;
class BST
{
public:
    BST();
    virtual ~BST();
    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    bool InsertNodeRe(Node* , Node* );
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node *);
    void LNR(Node *);
    void LRN(Node *);
    Node* search_x(const string&);

protected:
private:
    Node* root;
    void DeleteAllNodes(Node*);
};
#endif // BST_H