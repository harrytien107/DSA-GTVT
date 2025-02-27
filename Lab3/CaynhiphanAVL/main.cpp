#include <iostream>
#include <fstream>
#include "AVL_tree.h"
#include "AVL_tree.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;
int main()
{
    AVL_tree tree;
    ifstream infile("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab3\\CaynhiphanAVL\\input.txt"); // Mở tập tin input.txt để đọc

    if (!infile.is_open()) // Kiểm tra xem tập tin có mở thành công không
    {
        cerr << "Khong the mo tap tin input.txt\n";
        return 1;
    }

    int val;
    while (infile >> val) // Đọc từng số nguyên từ tập tin đến khi hết tập tin
    {
        Node* n = new Node(val);
        tree.InsertNodeRe(n);
    }

    infile.close(); // Đóng tập tin

    // Hiển thị cây AVL theo thứ tự in NLR
    cout << "Cay AVL sau khi chen cac gia tri:\n";
    tree.TravelNLR();

    // Hiển thị cây AVL dạng hình ảnh
    cout << "\nCay AVL (hien thi hinh anh):\n";
    tree.printAVLTree();

    // Thêm chức năng tìm kiếm khóa x
    int x;
    cout << "\nNhap vao khoa x de tim kiem: ";
    cin >> x;

    int compareCount = 0;
    Node* result = tree.search_x(x, compareCount);
    if(result != nullptr)
    {
        cout << "Tim thay khoa " << x << " trong cay AVL.\n";
    }
    else
    {
        cout << "Khong tim thay khoa " << x << " trong cay AVL.\n";
    }
    cout << "So phep so sanh thuc hien: " << compareCount << "\n";

    return 0;
}