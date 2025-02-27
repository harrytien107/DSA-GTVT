#include <bits/stdc++.h>
#include "BST.h"
#include "BST.cpp"
#include "Node.h"
#include "Node.cpp"
using namespace std;

int main()
{
    BST* tree = new BST();
    string text;

    cout << "Nhap van ban (Khong dau): ";
    getline(cin, text);
    
    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        Node* n = new Node(word);
        tree->InsertNode(n);
    }

    cout << "\nThong ke so luong tu trong van ban:\n";
    tree->TravelLNR();

    string searchWord;
    cout << "\nNhap vao mot tu de kiem tra so lan xuat hien: ";
    cin >> searchWord;

    Node* foundNode = tree->search_x(searchWord);
    if(foundNode != nullptr)
    {
        cout << "\"" << foundNode->Getkey() << "\" xuat hien " << foundNode->GetCount() << " lan.\n";
    }
    else
    {
        cout << "\"" << searchWord << "\" khong co trong van ban.\n";
    }

    delete tree;
    return 0;
}