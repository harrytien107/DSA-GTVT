#include "BST.h"

BST::BST()
    : root(nullptr)
{

}

BST::~BST()
{
    DeleteAllNodes(root);
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

bool BST::InsertNode(Node* newNode)
{
    if (root == nullptr)
    {
        root = newNode;
        return true;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;
        if (newNode->Getkey() == current->Getkey())
        {
            current->IncrementCount();
            delete newNode; 
            return true;
        }
        else if (newNode->Getkey() < current->Getkey())
        {
            current = current->Getleft();
        }
        else
        {
            current = current->Getright();
        }
    }

    // Chèn nút mới vào vị trí phù hợp
    if (newNode->Getkey() < parent->Getkey())
    {
        parent->Setleft(newNode);
    }
    else
    {
        parent->Setright(newNode);
    }

    return true;
}

Node* BST::search_x(const std::string& key)
{
    Node* current = root;
    while (current != nullptr)
    {
        if (key == current->Getkey())
        {
            return current;
        }
        else if (key < current->Getkey())
        {
            current = current->Getleft();
        }
        else
        {
            current = current->Getright();
        }
    }
    return nullptr; 
}

void BST::TravelLNR()
{
    LNR(root);
}

void BST::LNR(Node* r)
{
    if (r != nullptr)
    {
        LNR(r->Getleft());
        cout << "\"" << r->Getkey() << "\" : " << r->GetCount() << " lan.\n";
        LNR(r->Getright());
    }
}