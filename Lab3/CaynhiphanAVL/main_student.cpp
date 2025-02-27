#include <iostream>
#include <fstream>
#include "AVL_tree.h"
#include "AVL_tree.cpp"
#include "Node.h"
#include "Student.h"

using namespace std;
int main()
{
    AVL_tree tree;

    // Inserting some students
    tree.insert(Student(101, "An", "2002-05-15", 3.0));
    tree.insert(Student(102, "Bo", "2003-02-28", 3.6));
    tree.insert(Student(103, "Ca", "2004-10-10", 3.7));
    tree.insert(Student(104, "De", "2005-06-20", 2.9));

    tree.TravelLNR();
    cout << "-------------\n";
    tree.TravelNLR();

    int search_id = 102;
    bool found = tree.search(search_id);
    if (found)
    {
        cout << "Student with ID " << search_id << " found in the AVL tree." << endl;
    }
    else
    {
        cout << "Student with ID " << search_id << " not found in the AVL tree." << endl;
    }

    // Hiển thị cây dưới dạng hình ảnh
    cout << "\nCay AVL (Hien thi hinh anh):\n";
    tree.printAVLTree();
    cout << "-------------\n";

    // Xóa một sinh viên khỏi cây
    int delete_id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> delete_id;
    cout << "Xoa sinh vien co ID " << delete_id << " khoi cay AVL.\n";
    tree.deleteNode(delete_id);

    // Hiển thị lại cây sau khi xóa
    cout << "\nCay AVL sau khi xoa:\n";
    tree.TravelLNR();
    cout << "-------------\n";

    cout << "\nCay AVL (Hien thi hinh anh) sau khi xoa:\n";
    tree.printAVLTree();
    cout << "-------------\n";

    return 0;
}
