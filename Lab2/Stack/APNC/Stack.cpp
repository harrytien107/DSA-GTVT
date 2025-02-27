#include "Stack.h"
#include "element.h"
using namespace std;

Stack::Stack()
{
    this->nNum = 0;
    this->linkedlist = new linkedList();
}

Stack::~Stack()
{
    delete linkedlist;
}

void Stack::push(int x) 
{
    // Thay đổi từ InsertFirst sang InsertTail
    this->linkedlist->InsertTail(new element(x));
    this->nNum++;
}

int Stack::pop() 
{
    if (nNum == 0) 
    {
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return -1;
    }
    // Lấy giá trị của phần tử cuối
    element* current = this->linkedlist->getHead();
    while (current->Getpointer() != nullptr) {
        current = current->Getpointer();
    }
    int value = current->Getdata();
    
    // Xóa phần tử cuối
    this->linkedlist->DeleteTail();
    this->nNum--;
    return value;
}

int Stack::top() 
{
    if (this->nNum == 0) 
    {
        cout << "Stack empty" << endl;
        return -1;
    }
    // Lấy giá trị của phần tử cuối
    element* current = this->linkedlist->getHead();
    while (current->Getpointer() != nullptr) {
        current = current->Getpointer();
    }
    return current->Getdata();
}

void Stack::printStack()
{
    if (nNum == 0)
    {
        cout << "STACK RONG" << endl;
        return;
    }
    this->linkedlist->Travel();
}

bool Stack::isEmpty()
{
    return this->linkedlist->getHead() == nullptr;
}