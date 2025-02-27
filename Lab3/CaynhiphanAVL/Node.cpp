#include "Node.h"
#include "Student.h"
Node::Node()
{
    // ctor
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::Node(int k, Student s)
{
    // ctor
    this->key = k;
    this->student = s;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::~Node()
{
    // dtor
}