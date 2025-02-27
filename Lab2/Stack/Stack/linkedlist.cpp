/// File: linkedlist.cpp

#include "linkedList.h"
#include <iostream>
#include <cmath>
using namespace std;

linkedList::linkedList()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedList::~linkedList()
{
    //dtor
}
void linkedList::InsertFirst(element* e) 
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else 
    {
        e->Setpointer(this->head); //step 1
        //e->pointer = this->head;
        this->head = e;  // step 2
    }
    this->nNum++;

}
void linkedList::InsertFirstNotDuplicate(element* e) {
    if (this->head == nullptr)
    {
        this->head = this->tail = e;
        this->nNum++;
    }
    else
    {
        if (CheckContains(e->Getdata()) == false)
        {
            e->Setpointer(this->head);
            this->head = e;
            this->nNum++;
        }
    }
}
void linkedList::InsertTail(element* e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->Setpointer(e);// step 1
        this->tail = e;    // step 2
    }
    this->nNum++;
}
bool linkedList::CheckContains(int x) 
{
    element* p = this->head;
    while (p != nullptr) 
    {
        if (p->Getdata() == x) return true;
        p = p->Getpointer();
    }
    return false;
}
void linkedList::InsertTailNotDulicate(element* e) {
    if (this->head == nullptr)
    {
        this->head = this->tail = e;
        this->nNum++;
    }
    else 
    {
        if (CheckContains(e->Getdata()) == false)
        {
            this->tail->Setpointer(e);
                this->tail = e;
            this->nNum++;
        }
    }
    
}
void linkedList::Travel() 
{
    element* p = this->head;
    while (p != nullptr) 
    {
        cout << p->Getdata() << "\t"; // p -> data
        p = p->Getpointer(); // p = p -> pointer
    }
}
int linkedList::SumList() 
{
    int sumNum = 0;
    element* p = this->head;
    while (p != nullptr) 
    {
        sumNum += p->Getdata();
        p = p->Getpointer();
    }
    return sumNum;
}
bool linkedList::DeleteFirst() 
{
    if (this->head == nullptr) 
        return false;
    else 
    {
        element* p = this->head;
        this->head = this->head->Getpointer();
        delete p;
        return true;
    }
    return true;
}
bool linkedList::DeleteTail()
{
    if (this->head == nullptr)
        return false;
    else
    {
        element* p = this->head;
        while (p->Getpointer() != this->tail)
            p = p->Getpointer();
        delete this->tail;
        this->tail = p;
        this->tail->Setpointer(nullptr);  // this->tail->pointer = nullptr;
        return true;
    }
    return true;
}

bool linkedList::DeleteP(element* p)
{
    element* q; 
    q = this->head;
    if (this->head == p) 
    {
        this->head = p->Getpointer();
        delete p;
        return true;//Xoa thanh cong
    }
    while ((q != nullptr) && (q->Getpointer() != p)) //Tim q lien truoc p
        q = q->Getpointer();
    if (q == nullptr)
        return false; //khong tim thay phan tu co khoa bang p
    else
    {
        q->Setpointer(p->Getpointer());
        //q->pointer = p->pointer;
        delete p; 
        return true; //Xoa thanh cong
    }
    return true;
}

bool linkedList::removeAll() 
{    
    while (this->head != nullptr) 
    {
        DeleteFirst();
    }
    return true;
}
int linkedList::MaxList()
{
    element* p = this->head;
    int maxNum = p->Getdata();
    while (p != nullptr) 
    {
        if (maxNum < p->Getdata())
            maxNum = p->Getdata();
        p = p->Getpointer();
    }
    return maxNum;
}
bool isPrime(int num) 
{
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) 
        {
            return false;
        }
    }
    return true;
}
int linkedList::CountPrime()
{
    int coutPrimeNum = 0;
    element* p = this->head;
    while (p != nullptr)
    {
        if (isPrime(p->Getdata()) == true)
            coutPrimeNum++;
        p = p->Getpointer();
    }
    return coutPrimeNum;
}
void linkedList::InsertAfterP(element* Data, element* p)
{
    if (p != NULL)
    {
        Data->Setpointer(p->Getpointer());//Data->pointer = p->pointer;
        p->Setpointer(Data); // p->pointer = Data;
        if (this->tail == p)
            this->tail = Data;
    }
    else
        InsertFirst(Data);
}
int linkedList::CountDuplicate(int x)
{
    int countDuplicateValue = 0;
    element* p = this->head;
    while (p != nullptr) 
    {
        if (p->Getdata() == x) countDuplicateValue++;
        p = p->Getpointer();
    }
    return countDuplicateValue;
}
void linkedList::Split2List(int x, linkedList* lessThanX, linkedList* greaterOrEqualX)
{
    element* currElement = this->head;
    while (currElement != nullptr)
    {
        element* e = new element(currElement->Getdata());
        if (currElement->Getdata() < x)
        {
            lessThanX->InsertTail(e);
        }
        else
        {
            greaterOrEqualX->InsertTail(e);
        }
        currElement = currElement->Getpointer();
    }
}
