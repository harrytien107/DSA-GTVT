#ifndef BST_H
#define BST_H
#include "Node.h"
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
    Node* search_x(Node*, int);
    Node* search_x(int);
    int SumTree();
    void SumNodeTree(Node*, int&);
    Node* FindMin();
    Node* FindMax();
    Node* FindMinNode(Node*);
    Node* FindMaxNode(Node*);
    int CountAllNode();
    void CountAllNode(Node*, int&);
    int CountNode();
    void CountNode(Node*, int&);
    int CountLeafNodes(); // Public method
    void CountLeafNodesHelper(Node*, int&); // Helper method

    void PrintFrequencies();
    void PrintFrequencies(Node*);
    int CountDistinctValues();  // New method for counting distinct values
    void CountDistinctValues(Node* r, int& count);

protected:
private:
    Node* root;
    void DeleteAllNodes(Node*);
};
#endif // BST_H