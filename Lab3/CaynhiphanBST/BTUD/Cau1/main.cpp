#include <iostream>
#include <string>
#include "BST.h"
#include "BST.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;

int main()
{
    BST* tree = new BST();
    string text;

    cout << "Nhap van ban(khong dau): ";
    getline(cin, text);

    // Xay dung cay BST
    for(char ch : text)
    {
        if(ch == ' ') continue; // Bỏ qua dấu cách nếu không muốn đếm
        Node* n = new Node(ch);
        tree->InsertNode(n);
    }

    // a. Hien thi so lan xuat hien cua moi ky tu
    cout << "\nThong ke so luong ky tu trong van ban:\n";
    tree->TravelLNR(); // Duyet cay theo thu tu LNR (In-order traversal)

    // b. Nhập vào một ký tự và kiểm tra số lần xuất hiện
    char searchChar;
    cout << "\nNhap vao mot ky tu de kiem tra so lan xuat hien: ";
    cin >> searchChar;

    Node* foundNode = tree->search_x(searchChar);
    if(foundNode != nullptr)
    {
        cout << "Ky tu '" << foundNode->Getkey() << "' xuat hien " << foundNode->GetCount() << " lan.\n";
    }
    else
    {
        cout << "Ky tu '" << searchChar << "' khong co trong van ban.\n";
    }

    // Clean up
    delete tree;
    return 0;
}