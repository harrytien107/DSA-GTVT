#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SinhVien
{
    string ten, lop;
    double gpa;
};

struct node
{
    // SinhVien data;
    int data;
    //2 con tro 
    node *left; //luu dia chi cua node con ben trai
    node *right; //luu dia chi cua node con ben phai
    //constructor
    // node(int x){
    //     data = x;
    //     left = right = NULL;
    // }
};
// Neu ko thích constructor
node* makeNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main()
{
    // node *root = new node(10);
    // node *root = makeNode(1);
    // node *node2 = makeNode(2);
    // node *node3 = makeNode(3);
    // root->left = node2;
    // root->right = node3;
    // cout << root << endl;
    // cout << node2 << endl;
    // cout << node3 << endl;  
    // cout << root->data << endl;
    // cout << root->left << " " << root->right << endl;

    // node *root = makeNode(1);
    // root->left = makeNode(3);
    // root->right = makeNode(2);
    // root->left->left = makeNode(5);
    // root->left->right = makeNode(4);
    // root->right->left = makeNode(7);
    // root->right->right = makeNode(6);
    // cout << root->left->right->data << endl; \
    
    node *root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    root->right->left = makeNode(6);
    root->right->right = makeNode(7);
    root->right->right->left = makeNode(8);
    while(root != NULL){
        cout << root->data << " ";
        root = root->right;
    }
    // cout << root->data << endl;
    // cout << root->right->data + root->right->left->data << endl;
    return 0;
}