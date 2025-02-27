#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int AVLTree::getHeight(Node* node) const {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(Node* node) const {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, const Word& word) {
    if (node == nullptr)
        return new Node(word);

    if (word.english < node->data.english)
        node->left = insert(node->left, word);
    else if (word.english > node->data.english)
        node->right = insert(node->right, word);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && word.english < node->left->data.english)
        return rightRotate(node);

    if (balance < -1 && word.english > node->right->data.english)
        return leftRotate(node);

    if (balance > 1 && word.english > node->left->data.english) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && word.english < node->right->data.english) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(const Word& word) {
    root = insert(root, word);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

bool AVLTree::search(const string& english, string& vietnamese) const {
    Node* result = search(root, english);
    if (result != nullptr) {
        vietnamese = result->data.vietnamese;
        return true;
    }
    return false;
}

Node* AVLTree::search(Node* node, const string& english) const {
    if (node == nullptr || node->data.english == english)
        return node;

    if (english < node->data.english)
        return search(node->left, english);
    else
        return search(node->right, english);
}

bool AVLTree::modify(const string& english, const string& new_vietnamese) {
    Node* node = search(root, english);
    if (node != nullptr) {
        node->data.vietnamese = new_vietnamese;
        return true;
    }
    return false;
}

void AVLTree::inOrderTraversal() const {
    inOrderTraversal(root);
}

void AVLTree::inOrderTraversal(Node* node) const {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << "Tieng Anh: " << node->data.english
            << " | Tieng Viet: " << node->data.vietnamese << endl;
        inOrderTraversal(node->right);
    }
}