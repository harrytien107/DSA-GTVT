#include "BST.h"

BST::BST()
    : root(nullptr)
{
    // Constructor
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
        // std::cout << "Inserted root node: '" << newNode->Getkey() << "'\n";
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
            // std::cout << "Tang so lan xuat hien cua ky tu '" << current->Getkey() << "' thanh " << current->GetCount() << "\n";
            delete newNode; // Không cần nút mới
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
        // std::cout << "Inserted node '" << newNode->Getkey() << "' to the left of '" << parent->Getkey() << "'.\n";
    }
    else
    {
        parent->Setright(newNode);
        // std::cout << "Inserted node '" << newNode->Getkey() << "' to the right of '" << parent->Getkey() << "'.\n";
    }

    return true;
}

Node* BST::search_x(char key)
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
    return nullptr; // Không tìm thấy
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
        std::cout << "" << r->Getkey() << " : " << r->GetCount() << " lan.\n";
        LNR(r->Getright());
    }
}