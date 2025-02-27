#include "linkedlist.h"
#include <iostream>
using namespace std;
linkedlist::linkedlist()
{
    // ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}
linkedlist::~linkedlist()
{
    // dtor
}
void linkedlist::InsertFirst(element *e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        e->Setpointer(this->head); // step 1  //dung Setpointer vì cái j bị private r
        this->head = e;            // step 2
    }
    this->nNum++;
}
void linkedlist::InsertTail(element *e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->Setpointer(e); // step 1
        this->tail = e;            // step 2
    }
    this->nNum++; // đếm số lượng phần tử (ko QT lắm)
}
void linkedlist::Travel()
{
    element *p = this->head;
    while (p != nullptr)
    {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
}
//cau6
bool linkedlist::DeleteFirst()
{
    if (this->head == nullptr) return false;
    else
    {
        element *p = this->head;
        this->head = this->head->Getpointer();
        delete p;
        return true;
    }
}
// bool linkedlist::check
void linkedlist::RemoveAll()
{
    while (this->head != nullptr)
    {
        element* temp = this->head;
        this->head = this->head->Getpointer();
        delete temp;
    }
    this->tail = nullptr;
    this->nNum = 0;
}
//cau1
int linkedlist::SumList()
{
    int sum = 0;
    element *p = this->head;
    while (p != nullptr)
    {
        sum += p->Getdata();
        p = p->Getpointer();
    }
    return sum;
}
//cau2
int linkedlist::MaxList()
{
    if (this->head == nullptr)
        return 0; //nếu danh sách rỗng thì trả về 0
    int a = this->head->Getdata();
    element* p = this->head->Getpointer();
    while (p != nullptr)
    {
        if (p->Getdata() > a)
            a = p->Getdata();
        p = p->Getpointer();
    }
    return a;
}
//cau3
bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int linkedlist::CountPrime()
{
    int count = 0;
    element* p = this->head;
    while (p != nullptr)
    {
        if (isPrime(p->Getdata()))
            count++;
        p = p->Getpointer();
    }
    return count;
}
//cau4
void linkedlist::InsertTail(int val)
{
    element* e = new element(val);
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->Setpointer(e);
        this->tail = e;
    }
    this->nNum++;
}
//cau5
void linkedlist::InsertAfter(element* p, int val)
{
    if (p == nullptr) return;
    element* e = new element(val);
    e->Setpointer(p->Getpointer());
    p->Setpointer(e);
    if (p == this->tail)
        this->tail = e;
    this->nNum++;
}
//cau7
bool linkedlist::DeleteTail()
{
    if (this->head == nullptr) return false;
    if (this->head == this->tail)
    {
        delete this->head;
        this->head = this->tail = nullptr;
        return true;
    }
    element* p = this->head;
    while (p->Getpointer() != this->tail)
        p = p->Getpointer();
    delete this->tail;
    this->tail = p;
    this->tail->Setpointer(nullptr);
    return true;
}
//cau8
bool linkedlist::DeleteAt(element* p)
{
    if (p == nullptr) return false;
    if (p == this->head) return DeleteFirst();
    if (p == this->tail) return DeleteTail();
    element* q = this->head;
    while (q->Getpointer() != p)
        q = q->Getpointer();
    q->Setpointer(p->Getpointer());
    delete p;
    return true;
}
// bool linkedlist::DeleteAt(element* p)
// {
//     if (this->head == nullptr || p == nullptr)
//         return false;

//     if (p == this->head)
//         return DeleteFirst();

//     element* current = this->head;
//     while (current->Getpointer() != p && current != nullptr)
//         current = current->Getpointer();

//     if (current == nullptr)
//         return false;

//     if (p == this->tail)
//     {
//         this->tail = current;
//         this->tail->Setpointer(nullptr);
//     }
//     else
//     {
//         current->Setpointer(p->Getpointer());
//     }

//     delete p;
//     this->nNum--;
//     return true;
// }

//cau9
int linkedlist::CountValue(int x)
{
    int count = 0;
    element* p = this->head;
    while (p != nullptr)
    {
        if (p->Getdata() == x)
            count++;
        p = p->Getpointer();
    }
    return count;
}
//cau10
// bool linkedlist::InsertUnique(int val)
// {
//     element* p = this->head;
//     while (p != nullptr)
//     {
//         if (p->Getdata() == val)
//             return false;
//         p = p->Getpointer();
//     }
//     InsertTail(val);
//     return true;
// }
bool linkedlist::InsertUnique(int val)
{
    if (CountValue(val) > 0)
        return false;
        
    InsertTail(val);
    return true;
}
//cau11
void linkedlist::SplitList(int x, linkedlist* lessThanX, linkedlist* greaterThanX)
{
    element* p = this->head;
    while (p != nullptr)
    {
        if (p->Getdata() < x)
            lessThanX->InsertTail(p->Getdata());
        else
            greaterThanX->InsertTail(p->Getdata());
        p = p->Getpointer();
    }
}