#include "AVL_tree.h"
#include <iostream>
#include "Node.h"
using namespace std;
AVL_tree::AVL_tree()
{
    //ctor
    this->root = nullptr;
}

AVL_tree::~AVL_tree()
{
    //dtor
}
Node* AVL_tree::deleteNode(Node* currentNode, Node* n) 
{
    if (currentNode == nullptr)
        return currentNode;
    if (n->Getkey() < currentNode->Getkey())
        currentNode->Setleft(deleteNode(currentNode->Getleft(), n));
    else if (n->Getkey() > currentNode->Getkey())
        currentNode->Setright(deleteNode(currentNode->Getright(), n));
    else 
    {
        if ((currentNode->Getleft() == nullptr) || (currentNode->Getright() == nullptr))
        {
            Node* temp = currentNode->Getleft() ? currentNode->Getleft() : currentNode->Getright();

            if (temp == nullptr) 
            {
                temp = currentNode;
                currentNode = nullptr;
            }
            else 
            {
                *currentNode = *temp;
            }

            delete temp;
        }
        else 
        {
            Node* temp = currentNode->Getright();
            while (temp->Getleft() != nullptr)
                temp = temp->Getleft();

            currentNode->Setkey(temp->Getkey());
            currentNode->Setright(deleteNode(root->Getright(), temp));
        }
    }

    if (currentNode == nullptr)
        return currentNode;

    currentNode->Setheight(1 + max(GetHeight(currentNode->Getleft()), GetHeight(currentNode->Getright())));
    int balance = CheckBal(currentNode);

    // Balance AVL tree

    // Left Left Case
    if (balance > 1 && CheckBal(currentNode->Getleft()) >= 0)
    {
        RightRotate(currentNode);
    }

    // Left Right Case
    if (balance > 1 && CheckBal(currentNode->Getleft()) < 0)
    {
        Node* nLeft = currentNode->Getleft();
        LeftRotate(nLeft);
        RightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && CheckBal(currentNode->Getright()) <= 0)
    {
        LeftRotate(currentNode);
    }

    // Right Left Case
    if (balance < -1 && CheckBal(currentNode->Getright()) > 0)
    {
        Node* nRight = currentNode->Getright();
        RightRotate(nRight);
        LeftRotate(currentNode);
    }    
    return currentNode;
}
void AVL_tree::deleteNodeRe(Node* key)
{
    this->root = deleteNode(this->root, key);
}
bool AVL_tree::InsertNode(Node* n) 
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
                    return false;
    }
    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    n->Setparent(T);
    // Rebalance the tree
    Node* x = n->Getparent();
    while (x != nullptr) 
    {
        int bal = this->CheckBal(x);
        switch (bal)
        {
            case 0:
            case 1:
            case -1:
                break;

            case 2:
                if (this->CheckBal(x->Getleft()) >= 0) 
                {
                    // Left-Left case
                    if (x == this->root) 
                    {
                        this->RightRotate(this->root);
                    } 
                    else 
                    {
                        Node* parentX = x->Getparent();
                        this->RightRotate(x);
                        if (parentX->Getleft() == x) 
                        {
                            parentX->Setleft(x);
                        } 
                        else 
                        {
                            parentX->Setright(x);
                        }
                    }
                } 
                else 
                {
                    // Left-Right case
                    Node* leftChild = x->Getleft();
                    this->LeftRotate(leftChild);
                    if (x == this->root) 
                    {
                        this->RightRotate(this->root);
                    }
                    else 
                    {
                        Node* parentX = x->Getparent();
                        this->RightRotate(x);
                        if (parentX->Getleft() == x) 
                        {
                            parentX->Setleft(x);
                        }
                        else
                        {
                            parentX->Setright(x);
                        }
                    }
                }
                break;

            case -2:
                if (this->CheckBal(x->Getright()) <= 0) 
                {
                    // Right-Right case
                    if (x == this->root)
                    {
                        this->LeftRotate(this->root);
                    }
                    else 
                    {
                        Node* parentX = x->Getparent();
                        this->LeftRotate(x);
                        if (parentX->Getright() == x)
                        {
                            parentX->Setright(x);
                        } 
                        else 
                        {
                            parentX->Setleft(x);
                        }
                    }
                } 
                else 
                {
                    // Right-Left case
                    Node* rightChild = x->Getright();
                    this->RightRotate(rightChild);
                    if (x == this->root)
                    {
                        this->LeftRotate(this->root);
                    } else
                    {
                        Node* parentX = x->Getparent();
                        this->LeftRotate(x);
                        if (parentX->Getright() == x) 
                        {
                            parentX->Setright(x);
                        } 
                        else 
                        {
                            parentX->Setleft(x);
                        }
                    }
                }
                break;
        }

        // Move up to the parent node
        x = x->Getparent();
    }

    return true;
}

void AVL_tree::RightRotate(Node*& y)
{
    Node* x = y->Getleft();
    Node* T2 = x->Getright();

    x->Setright(y);
    y->Setleft(T2);

    y->Setheight(1 + max(GetHeight(y->Getleft()), GetHeight(y->Getright())));
    x->Setheight(1 + max(GetHeight(x->Getleft()), GetHeight(x->Getright())));

    y = x;
}

// void AVL_tree::RightRotate(Node*& P) 
// {
//     Node* Q = P->Getleft();
//     Node* T = Q->Getright();

//     Q->Setright(P);
//     P->Setleft(T);

//     // Update parents
//     Q->Setparent(P->Getparent());
//     P->Setparent(Q);

//     if (T != nullptr) 
//     {
//         T->Setparent(P);
//     }

//     // Update the parent's child pointer
//     if (Q->Getparent() != nullptr)
//     {
//         if (Q->Getparent()->Getleft() == P) 
//         {
//             Q->Getparent()->Setleft(Q);
//         }
//         else
//         {
//             Q->Getparent()->Setright(Q);
//         }
//     }
//     else 
//     {
//         // if parent of Q is nullptr, Q becomes the root
//         this->root = Q;
//     }

//     P = Q;
// }

void LeftRotate(Node*& x)
{
    Node* y = x->Getright();
    Node* T2 = y->Getleft();

    y->Setleft(x);
    x->Setright(T2);

    x->Setheight(1 + max(GetHeight(x->Getleft()), GetHeight(x->Getright())));
    y->Setheight(1 + max(GetHeight(y->Getleft()), GetHeight(y->Getright())));

    x = y;
}

// void AVL_tree::LeftRotate(Node*& P) 
// {
//     Node* Q = P->Getright();
//     Node* T = Q->Getleft();

//     Q->Setleft(P);
//     P->Setright(T);

//     // Update parents
//     Q->Setparent(P->Getparent());
//     P->Setparent(Q);

//     if (T != nullptr) 
//     {
//         T->Setparent(P);
//     }

//     // Update the parent's child pointer
//     if (Q->Getparent() != nullptr) 
//     {
//         if (Q->Getparent()->Getleft() == P)
//         {
//             Q->Getparent()->Setleft(Q);
//         }
//         else 
//         {
//             Q->Getparent()->Setright(Q);
//         }
//     }
//     else 
//     {
//         // if parent of Q is nullptr, Q becomes the root
//         this->root = Q;
//     }

//     P = Q;
// }
Node* AVL_tree::InsertNode(Node* r, Node* p) 
{
    // Perform BST insertion
    if (r == nullptr) {
        r = p;
        return r;
    }

    if (p->Getkey() < r->Getkey()) 
    {
        r->Setleft(InsertNode(r->Getleft(), p));
    }
    else if (p->Getkey() > r->Getkey()) 
    {
        r->Setright(InsertNode(r->Getright(), p));
    }
    else 
    {
        // Duplicate keys are not allowed in this implementation
        return r;
    }

    // Update height of current node
    r->Setheight(1 + std::max(GetHeight(r->Getleft()), GetHeight(r->Getright())));

    // Check balance factor
    int balance = CheckBal(r);

    // Perform rotations if tree becomes unbalanced
    if (balance > 1 && p->Getkey() < r->Getleft()->Getkey()) {
        RightRotate(r);
    }
    if (balance < -1 && p->Getkey() > r->Getright()->Getkey()) {
        LeftRotate(r);
    }
    if (balance > 1 && p->Getkey() > r->Getleft()->Getkey()) {
        Node* rLeft = r->Getleft();
        LeftRotate(rLeft);
        r->Setleft(rLeft);
        RightRotate(r);
    }
    if (balance < -1 && p->Getkey() < r->Getright()->Getkey()) {
        Node* rRight = r->Getright();
        RightRotate(rRight);
        r->Setright(rRight);
        LeftRotate(r);
    }

    return r;
}

void AVL_tree::InsertNodeRe(Node* p) 
{
    this->root = InsertNode(this->root, p);
}

void AVL_tree::NLR(Node* r) {
    if (r != nullptr) 
    {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void AVL_tree::LNR(Node* r)
{
    if(r != nullptr) 
    {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}
void AVL_tree::LRN(Node* r) 
{
    if (r != nullptr)
    {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << "\n";
    }
}
void AVL_tree::TravelNLR() {
    NLR(this->root);
}
void AVL_tree::TravelLNR() {
    LNR(this->root);
}
void AVL_tree::TravelLRN() {
    LRN(this->root);
}
Node* AVL_tree::search_x(int k, int &compareCount) 
{
    Node* p = this->root;

    while (p != nullptr)
    {
        compareCount++;
        if (p->Getkey() == k)
        {
            return p;
        }
        else if (k < p->Getkey()) 
        {
            p = p->Getleft();
        }
        else
        {
            p = p->Getright();
        }
    }

    return nullptr;
}
/*
void AVL_tree::LeftRotate(Node*& P)
{
    Node* Q;
    Node* T;
    Q = P->Getright();
    T = Q->Getleft();
    P->Setright(T);
    Q->Setleft(P);
    P->Setparent(Q);
    if (T != nullptr)
        T->Setparent(P);
    P = Q;
}
void AVL_tree::RightRotate(Node*& P) 
{
    Node* Q;
    Node* T;
    Q = P->Getleft();
    T = Q->Getright();
    P->Setleft(T);
    Q->Setright(P);
    P->Setparent(Q);
    if (T != nullptr)
        T->Setparent(P);
    P = Q;
}*/
int AVL_tree::CheckBal(Node* p)
{
    int bal = this->GetHeight(p->Getleft()) - this->GetHeight(p->Getright());
    return bal;
}
int AVL_tree::GetHeight(Node* p) 
{
    if (p == nullptr) return 0;
    else
        return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}
void AVL_tree::printAVL(Node* root, int iSpace)
{
    if (root == NULL)
        return;
    iSpace += 8;

    printAVL(root->Getright(), iSpace);
    cout << endl;

    for (int i = 8; i < iSpace; i++)
        cout << " ";
    cout << root->Getkey() << "\n";

    printAVL(root->Getleft(), iSpace);
}

void AVL_tree::printAVLTree()
{
    printAVL(this->root, 0);
}
