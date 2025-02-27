#include "Node.h"

Node::Node()
{
    // ctor
    this->key = '\0'; // Khởi tạo ký tự rỗng
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->count = 0;
}

Node::Node(char k)
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