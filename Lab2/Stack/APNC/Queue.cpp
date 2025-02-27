#include "Queue.h"
#include "element.h"
using namespace std;

Queue::Queue()
{
    this->nNum = 0;
    this->linkedlist = new linkedList();
}

Queue::~Queue()
{
    delete linkedlist;
}

void Queue::enqueue(int x) 
{
    element* p = new element(x);
    this->linkedlist->InsertTail(p);
    nNum++;
}

int Queue::dequeue()
{
    if (nNum == 0) 
    {
        cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
        return -1;
    }
    int p = this->linkedlist->getHead()->Getdata();
    this->linkedlist->DeleteFirst();
    nNum--;
    return p;
}

bool Queue::isEmpty()
{
    return this->linkedlist->getHead() == nullptr;
}

void Queue::printQueue()
{
    if (nNum == 0)
    {
        cout << "QUEUE RONG" << endl;
        return;
    }
    this->linkedlist->Travel();
}

int Queue::front()
{
    if (this->nNum == 0)
    {
        cout << "QUEUE RONG";
    }
    return this->linkedlist->getHead()->Getdata();
}

int Queue::rear() 
{
    if (this->nNum == 0) {
        cout << "QUEUE RONG" << endl;
        return -1;
    }

    element* current = this->linkedlist->getHead();

    while (current->Getpointer() != nullptr)
    {
        current = current->Getpointer();
    }

    return current->Getdata();
}
