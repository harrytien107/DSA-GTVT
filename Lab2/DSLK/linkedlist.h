#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"
class linkedlist
{
private:
    element* head;
    element* tail;
    int nNum;

public:
    linkedlist();
    virtual ~linkedlist();
    element* Gethead() { return head; }
    void Sethead(element* val) { head = val; }
    element* Gettail() { return tail; }
    void Settail(element* val) { tail = val; }
    void InsertFirst(element* );
    void InsertTail(element* );
    bool DeleteFirst();
    void Travel();
    void RemoveAll();
    int SumList();
    int MaxList();
    int CountPrime();
    void InsertTail(int val);
    void InsertAfter(element* p, int val);
    bool DeleteTail();
    bool DeleteAt(element* p); //cau8
    int CountValue(int x);
    bool InsertUnique(int val);
    void SplitList(int x, linkedlist* lessThanX, linkedlist* greaterThanX);
protected:
};
#endif // LINKEDLIST_H