#include "AVL_tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

AVL_tree::~AVL_tree()
{
    //dtor
}
// Node* AVL_tree::deleteNode(Node* root, int key)
// {
//         if (root == nullptr)
//             return root;

//         if (key < root->getStudent().getStudentID())
//             root->Setleft(deleteNode(root->Getleft(), key));
//         else if (key > root->getStudent().getStudentID())
//             root->Setright(deleteNode(root->Getright(), key));
//         else 
// 		{
//             if ((root->Getleft() == nullptr) || (root->Getright() == nullptr)) 
// 			{
//                 Node* temp = root->Getleft() ? root->Getleft() : root->Getright();

//                 if (temp == nullptr) 
//                 {
//                     temp = root;
//                     root = nullptr;
//                 }
//                 else 
//                 {
//                     *root = *temp;
//                 }

//                 delete temp;
//             }
//             else 
//             {
//                 Node* temp = root->Getright();
//                 while (temp->Getleft() != nullptr)
//                     temp = temp->Getleft();

//                 root->Setstudent(temp->Getstudent());
//                 root->Setright(deleteNode(root->Getright(), temp->Getstudent().GetStudentID()));
//             }
//         }

//         if (root == nullptr)
//             return root;

//         root->Setheight(1 + max(getHeight(root->Getleft()), getHeight(root->Getright())));
//         int balance = checkBalance(root);

//         if (balance > 1 && checkBalance(root->Getleft()) >= 0)
//             rotateRight(root);

//         if (balance > 1 && checkBalance(root->Getleft()) < 0) 
//         {
//             Node* nLeft = root->Getleft();
//             rotateLeft(nLeft);
//             rotateRight(root);
//         }

//         if (balance < -1 && checkBalance(root->Getright()) <= 0)
//             rotateLeft(root);

//         if (balance < -1 && checkBalance(root->Getright()) > 0) 
//         {
//             Node* nRight = root->Getright();
//             rotateRight(nRight);
//             rotateLeft(root);
//         }

//         return root;
//     }
// void AVL_tree::deleteNodeRe(int key)
// {
//     this->root = deleteNode(this->root, key);
// }
// bool AVL_tree::InsertNode(Node* n) 
// {
//     Node* p = this->root;
//     Node* T = new Node();
//     if (root == nullptr)
//     {
//         this->root = n;
//         return true;
//     }
//     while (p != nullptr)
//     {
//         T = p;

//         if (p->Getkey() > n->Getkey())
//             p = p->Getleft();
//         else
//             if (p->Getkey() < n->Getkey())
//                 p = p->Getright();
//             else
//                 if (p->Getkey() == n->Getkey())
//                     return false;
//     }
//     if (T->Getkey() > n->Getkey())
//         T->Setleft(n);
//     else T->Setright(n);
//     n->Setparent(T);
//     // Rebalance the tree
//     Node* x = n->Getparent();
//     while (x != nullptr) 
//     {
//         int bal = this->CheckBal(x);
//         switch (bal)
//         {
//             case 0:
//             case 1:
//             case -1:
//                 break;

//             case 2:
//                 if (this->CheckBal(x->Getleft()) >= 0) 
//                 {
//                     // Left-Left case
//                     if (x == this->root) 
//                     {
//                         this->RightRotate(this->root);
//                     } 
//                     else 
//                     {
//                         Node* parentX = x->Getparent();
//                         this->RightRotate(x);
//                         if (parentX->Getleft() == x) 
//                         {
//                             parentX->Setleft(x);
//                         } 
//                         else 
//                         {
//                             parentX->Setright(x);
//                         }
//                     }
//                 } 
//                 else 
//                 {
//                     // Left-Right case
//                     Node* leftChild = x->Getleft();
//                     this->LeftRotate(leftChild);
//                     if (x == this->root) 
//                     {
//                         this->RightRotate(this->root);
//                     }
//                     else 
//                     {
//                         Node* parentX = x->Getparent();
//                         this->RightRotate(x);
//                         if (parentX->Getleft() == x) 
//                         {
//                             parentX->Setleft(x);
//                         }
//                         else
//                         {
//                             parentX->Setright(x);
//                         }
//                     }
//                 }
//                 break;

//             case -2:
//                 if (this->CheckBal(x->Getright()) <= 0) 
//                 {
//                     // Right-Right case
//                     if (x == this->root)
//                     {
//                         this->LeftRotate(this->root);
//                     }
//                     else 
//                     {
//                         Node* parentX = x->Getparent();
//                         this->LeftRotate(x);
//                         if (parentX->Getright() == x)
//                         {
//                             parentX->Setright(x);
//                         } 
//                         else 
//                         {
//                             parentX->Setleft(x);
//                         }
//                     }
//                 } 
//                 else 
//                 {
//                     // Right-Left case
//                     Node* rightChild = x->Getright();
//                     this->RightRotate(rightChild);
//                     if (x == this->root)
//                     {
//                         this->LeftRotate(this->root);
//                     } else
//                     {
//                         Node* parentX = x->Getparent();
//                         this->LeftRotate(x);
//                         if (parentX->Getright() == x) 
//                         {
//                             parentX->Setright(x);
//                         } 
//                         else 
//                         {
//                             parentX->Setleft(x);
//                         }
//                     }
//                 }
//                 break;
//         }

//         // Move up to the parent node
//         x = x->Getparent();
//     }

//     return true;
// }


// Node* AVL_tree::InsertNode(Node* r, Node* p) 
// {
//     // Perform BST insertion
//     if (r == nullptr) {
//         r = p;
//         return r;
//     }

//     if (p->Getkey() < r->Getkey()) 
//     {
//         r->Setleft(InsertNode(r->Getleft(), p));
//         r->Getleft()->Setparent(r);
//     }
//     else if (p->Getkey() > r->Getkey()) 
//     {
//         r->Setright(InsertNode(r->Getright(), p));
//         r->Getright()->Setparent(r);
//     }
//     else 
//     {
//         // Duplicate keys are not allowed in this implementation
//         return r;
//     }

//     // Update height of current node
//     r->Setheight(1 + std::max(GetHeight(r->Getleft()), GetHeight(r->Getright())));

//     // Check balance factor
//     int balance = CheckBal(r);

//     // Perform rotations if tree becomes unbalanced
//     if (balance > 1 && p->Getkey() < r->Getleft()->Getkey()) {
//         RightRotate(r);
//     }
//     if (balance < -1 && p->Getkey() > r->Getright()->Getkey()) {
//         LeftRotate(r);
//     }
//     if (balance > 1 && p->Getkey() > r->Getleft()->Getkey()) {
//         Node* rLeft = r->Getleft();
//         LeftRotate(rLeft);
//         r->Setleft(rLeft);
//         RightRotate(r);
//     }
//     if (balance < -1 && p->Getkey() < r->Getright()->Getkey()) {
//         Node* rRight = r->Getright();
//         RightRotate(rRight);
//         r->Setright(rRight);
//         LeftRotate(r);
//     }

//     return r;
// }

// void AVL_tree::InsertNodeRe(Node* p) 
// {
//     this->root = InsertNode(this->root, p);
// }

// void AVL_tree::NLR(Node* r) {
//     if (r != nullptr) 
//     {
//         cout << r->Getkey() << "\n";
//         NLR(r->Getleft());
//         NLR(r->Getright());
//     }
// }
// void AVL_tree::LNR(Node* r)
// {
//     if(r != nullptr) 
//     {
//         LNR(r->Getleft());
//         cout << r->Getkey() << "\n";
//         LNR(r->Getright());
//     }
// }
// void AVL_tree::LRN(Node* r) 
// {
//     if (r != nullptr)
//     {
//         LRN(r->Getleft());
//         LRN(r->Getright());
//         cout << r->Getkey() << "\n";
//     }
// }
// void AVL_tree::TravelNLR() {
//     NLR(this->root);
// }
// void AVL_tree::TravelLNR() {
//     LNR(this->root);
// }
// void AVL_tree::TravelLRN() {
//     LRN(this->root);
// }
// void AVL_tree::deleteNode(Node *n)
// {
//     Node *p = n;
//     if (n->Getleft() == nullptr && n->Getright() == nullptr)
//         delete n;
//     else
//     {
//         if (p->Getright() != nullptr)
//         {
//             while (p->Getleft() != nullptr) //
//                 p = p->Getleft();
//             n->Setkey(p->Getkey());
//             // Code
//             delete p;
//         }
//         else
//         {
//             while (p->Getright() != nullptr) //
//                 p = p->Getright();
//             n->Setkey(p->Getkey());
//             // Code
//             delete p;
//         }
//     }
// }
// Node* AVL_tree::search_x(int k, int &compareCount) 
// {
//     Node* p = this->root;
//     compareCount = 0;
//     while (p != nullptr)
//     {
//         compareCount++;
//         if (p->Getkey() == k)
//         {
//             return p;
//         }
//         else if (k < p->Getkey()) 
//         {
//             p = p->Getleft();
//         }
//         else
//         {
//             p = p->Getright();
//         }
//     }

//     return nullptr;
// }

// void AVL_tree::LeftRotate(Node*& P)
// {
//     Node* Q;
//     Node* T;
//     Q = P->Getright();
//     T = Q->Getleft();
//     P->Setright(T);
//     Q->Setleft(P);
//     P->Setparent(Q);
//     if (T != nullptr)
//         T->Setparent(P);
//     P = Q;
// }
// void AVL_tree::RightRotate(Node*& P) 
// {
//     Node* Q;
//     Node* T;
//     Q = P->Getleft();
//     T = Q->Getright();
//     P->Setleft(T);
//     Q->Setright(P);
//     P->Setparent(Q);
//     if (T != nullptr)
//         T->Setparent(P);
//     P = Q;
// }
//

int AVL_tree::getHeight(Node *p)
{
    if (p == nullptr)
        return 0;
    return p->getHeight();
}
int AVL_tree::checkBalance(Node *p)
{
    if (p == nullptr)
        return 0;
    return getHeight(p->Getleft()) - getHeight(p->Getright());
}

void AVL_tree::rotateLeft(Node*& x)
{
    Node* y = x->Getright();
    Node* T2 = y->Getleft();
    y->Setleft(x);
    x->Setright(T2);

    x->Setheight(1 + max(getHeight(x->Getleft()), getHeight(x->Getright())));
    y->Setheight(1 + max(getHeight(y->Getleft()), getHeight(y->Getright())));
    x = y;
}
void AVL_tree::rotateRight(Node*& y)
{
    Node* x = y->Getleft();
    Node* T2 = x->Getright();

    x->Setright(y);
    y->Setleft(T2);

    y->Setheight(1 + max(getHeight(y->Getleft()), getHeight(y->Getright())));
    x->Setheight(1 + max(getHeight(x->Getleft()), getHeight(x->Getright())));

        y = x;
}
    Node* AVL_tree::deleteNode(Node* root, int key)
{
    if (root == nullptr) return root;

    if (key < root->GetStudent().GetStudentID())
        root->Setleft(deleteNode(root->Getleft(), key));
    else if (key > root->GetStudent().GetStudentID())
        root->Setright(deleteNode(root->Getright(), key));
    else 
    {
        if (root->Getleft() == nullptr && root->Getright() == nullptr)
        {
                Node* temp = root->Getleft() ? root->Getleft() : root->Getright();

                if (temp == nullptr) 
                {
                    temp = root;
                    root = nullptr;
                }
                else 
                {
                    *root = *temp;
                }

                delete temp;
            }
            else 
            {
                Node* temp = root->Getright();
                while (temp->Getleft() != nullptr)
                    temp = temp->Getleft();

                root->SetStudent(temp->GetStudent());
                root->Setright(deleteNode(root->Getright(), temp->GetStudent().GetStudentID()));
            }
        }

        if (root == nullptr)
            return root;

        root->Setheight(1 + max(getHeight(root->Getleft()), getHeight(root->Getright())));
        int balance = checkBalance(root);

        if (balance > 1 && checkBalance(root->Getleft()) >= 0)
            rotateRight(root);

        if (balance > 1 && checkBalance(root->Getleft()) < 0) 
        {
            Node* nLeft = root->Getleft();
            rotateLeft(nLeft);
            rotateRight(root);
        }

        if (balance < -1 && checkBalance(root->Getright()) <= 0)
            rotateLeft(root);

        if (balance < -1 && checkBalance(root->Getright()) > 0) 
        {
            Node* nRight = root->Getright();
            rotateRight(nRight);
            rotateLeft(root);
        }

        return root;
    }

    Node* AVL_tree::insert(Node* node, const Student& student)
    {
        if (node == nullptr)
            return new Node(student);

        if (student.GetStudentID() < node->GetStudent().GetStudentID())
            node->Setleft(insert(node->Getleft(), student));
        else if (student.GetStudentID() > node->GetStudent().GetStudentID())
            node->Setright(insert(node->Getright(), student));
        else
            return node;

        node->Setheight(1 + max(getHeight(node->Getleft()), getHeight(node->Getright())));

        int balance = checkBalance(node);

        if (balance > 1 && student.GetStudentID() < node->Getleft()->GetStudent().GetStudentID())
            rotateRight(node);

        if (balance < -1 && student.GetStudentID() > node->Getright()->GetStudent().GetStudentID())
            rotateLeft(node);

        if (balance > 1 && student.GetStudentID() > node->Getleft()->GetStudent().GetStudentID()) 
        {
            Node* nLeft = node->Getleft();
            rotateLeft(nLeft);
            rotateRight(node);
        }

        if (balance < -1 && student.GetStudentID() < node->Getright()->GetStudent().GetStudentID()) 
        {
            Node* nRight = node->Getright();
            rotateRight(nRight);
            rotateLeft(node);
        }

        return node;
    }

bool AVL_tree::search(Node* root, int key) {
        if (root == nullptr)
            return false;

        if (key == root->GetStudent().GetStudentID())
            return true;
        else if (key < root->GetStudent().GetStudentID())
            return search(root->Getleft(), key);
        else
            return search(root->Getright(), key);
    }

void AVL_tree::insert(const Student& student)
{
    root = insert(root, student);
}
void AVL_tree::deleteNode(int key) 
    {
        root = deleteNode(root, key);
    }

    bool AVL_tree::search(int key) 
{
    return search(root, key);
}

void AVL_tree::LNR(Node* root) 
    {
        if (root != nullptr) 
        {
            LNR(root->Getleft());
            cout << "Student ID: " << root->GetStudent().GetStudentID() << ", Name: " << root->GetStudent().GetName()
                << ", dateOfBirth: " << root->GetStudent().GetDateOfBirth() << ", GPA: " << root->GetStudent().GetGPA() << endl;
            LNR(root->Getright());
        }
    }

    void AVL_tree::TravelLNR() 
    {
        LNR(root);
    }

    void AVL_tree::NLR(Node* root)
    {
        if (root != nullptr)
        {
            cout << "Student ID: " << root->GetStudent().GetStudentID() << ", Name: " << root->GetStudent().GetName()
                << ", dateOfBirth: " << root->GetStudent().GetDateOfBirth() << ", GPA: " << root->GetStudent().GetGPA() << endl;
            LNR(root->Getleft());
            LNR(root->Getright());
        }
    }

    void AVL_tree::TravelNLR()
    {
        NLR(root);
    }

void AVL_tree::printAVL(Node* node, int indent) 
{
    if (node == nullptr)
        return;

    indent += 8;

    printAVL(node->Getright(), indent);
    cout << endl;

    for (int i = 8; i < indent; i++)
        cout << " ";
    cout << node->GetStudent().GetStudentID() << "\n";

    printAVL(node->Getleft(), indent);
}

void AVL_tree::printAVLTree() 
{
    printAVL(root, 0);
}