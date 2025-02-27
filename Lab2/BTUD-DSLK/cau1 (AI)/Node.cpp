#include "Node.h"

Node::Node() : coefficient(0), exponent(0), pointer(nullptr) {}

Node::Node(int coef, int exp) : coefficient(coef), exponent(exp), pointer(nullptr) {}

Node::~Node() {}

int Node::GetExponent() const {
    return exponent;
}

void Node::SetExponent(int val) {
    exponent = val;
}

Node* Node::GetPointer() const {
    return pointer;
}

void Node::SetPointer(Node* ptr) {
    pointer = ptr;
}