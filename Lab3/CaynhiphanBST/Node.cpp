#include "Node.h"
Node::Node()
{
    // ctor
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
Node::Node(int k)
{
    // ctor
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->count = 1;
}
Node::~Node()
{
    // dtor
}