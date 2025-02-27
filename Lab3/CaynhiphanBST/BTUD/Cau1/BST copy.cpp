#include "BST.h"
#include <iostream>

using namespace std;
BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
    DeleteAllNodes(this->root);
}
void BST::DeleteAllNodes(Node* r)
{
    if (r != nullptr)
    {
        DeleteAllNodes(r->Getleft());
        DeleteAllNodes(r->Getright());
        delete r;
    }
}
bool BST::InsertNode(Node* n)
{
    Node* p = this->root;
    Node* T = new Node();
    if (root == nullptr)
    {
        this->root = n;
        return true;
    }
    while (p != nullptr) 
    {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                {
                    p->IncrementCount();
                    delete n;
                    return false;
                }
    }
    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    return true;
}
bool BST::InsertNodeRe(Node* root, Node* p) 
{
    if (root == nullptr)
    {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey())
        return false;
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}
void BST::NLR(Node* r) 
{
    if (r != nullptr) 
    {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

void BST::LNR(Node* r) 
{
    if (r != nullptr) 
    {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}
void BST::LRN(Node* r) 
{
    if (r != nullptr)
    {
        LRN(r->Getleft());
        cout << r->Getkey() << "\n";
        LRN(r->Getright());
    }
}
void BST::TravelNLR()
{
    NLR(this->root);
}
void BST::TravelLNR() 
{
    LNR(this->root);
}
void BST::TravelLRN()
{
    LRN(this->root);
}
Node* BST::search_x(char k) 
{
    Node* p = this->root;
    if (p != NULL)
    {
        if (k == p->Getkey()) return p;
        if (k < p->Getkey())
        {
            p = p->Getleft();
            return search_x(k);
        }
        if (k > p->Getkey())
        {
            p = p->Getright();
            return search_x(k);
        }
    }
    return NULL; //Khong tim dc nut nao co khoa x
}
void BST::deleteNode(Node* n) 
{
    if (n == nullptr) return;

    Node* p = n;
    if (p->Getleft() == nullptr && n->Getright() == nullptr) 
    {
        // Case 1: Node is a leaf
        // Find the parent
        Node* parent = nullptr;
        Node* current = this->root;
        while (current != nullptr && current != n) 
        {
            parent = current;
            if (n->Getkey() < current->Getkey()) 
            {
                current = current->Getleft();
            }
            else 
            {
                current = current->Getright();
            }
        }

        // Update the parent pointer
        if (parent != nullptr) 
        {
            if (parent->Getleft() == n) 
                parent->Setleft(nullptr);
            else parent->Setright(nullptr);
        }
        else 
        {
            root = nullptr;
        }

        delete n;
    }
    else 
    {
        if (p->Getright() != nullptr) 
        {
            // Case 3: Node has right child (there is a left child or not)
            // Find the smallest node in the right subtree
            Node* parentRightSubtree = p;
            p = p->Getright();
            while (p->Getleft() != nullptr)
            {
                parentRightSubtree = p;
                p = p->Getleft();
            }
            n->Setkey(p->Getkey()); // set value of p to n
            if (parentRightSubtree->Getleft() == p) // set pointer of p parents to child of p
            {
                parentRightSubtree->Setleft(p->Getright());
            }
            else 
            {
                parentRightSubtree->Setright(p->Getright());
            }
            delete p;
        }
        else 
        {
            // Case 2: Node has left child only
            // Find largest node in the left subtree
            Node* parentLeftSubtree = p;
            p = p->Getleft();
            while (p->Getright() != nullptr) 
            {
                parentLeftSubtree = p;
                p = p->Getright();
            }
            n->Setkey(p->Getkey());
            if (parentLeftSubtree->Getright() == p)
            {
                parentLeftSubtree->Setright(p->Getleft());
            }
            else 
            {
                parentLeftSubtree->Setleft(p->Getleft());
            }
            delete p;
        }
    }
}


// Node* BST::findNode(int key) 
// {
//     Node* current = this->root; // Assuming root is the root of your BST
//     while (current != nullptr)
//     {
//         if (key == current->Getkey()) 
//         {
//             return current;
//         }
//         else if (key < current->Getkey())
//         {
//             current = current->Getleft();
//         }
//         else 
//         {
//             current = current->Getright();
//         }
//     }
//     return nullptr; // If the node with the key is not found
// }
