#include "Stack.h"
#include "element.h"

void Stack::push(int x) 
{
    this->linkedlist->InsertFirst(new element(x));
    this->nNum++;
}

int Stack::pop() 
{
    if (nNum == 0) 
    {
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return -1; 
    }
    int p = this->linkedlist->getHead()->Getdata();
    this->linkedlist->DeleteFirst();
    this->nNum--;
    return p;
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

int Stack::top() 
{
    if (this->nNum == 0) 
    {
        cout << "STACK RONG" << endl;
        return -1; 
    }
    return this->linkedlist->getHead()->Getdata();
}

Stack::Stack()
{
    this->nNum = 0;
    this->linkedlist = new linkedList();
}

Stack::~Stack()
{
    delete linkedlist;
}

