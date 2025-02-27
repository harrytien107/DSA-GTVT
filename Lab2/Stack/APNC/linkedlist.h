#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "element.h"

class linkedList {
private:
    element* head;
    element* tail;
    int nNum;

public:
    linkedList();
    virtual ~linkedList();
    element* getHead() { return head; }
    void setHead(element* val) { head = val; }
    void InsertFirst(element* e);
    void InsertFirstNotDuplicate(element* e);
    void InsertTail(element* e);
    bool CheckContains(int x);
    void InsertTailNotDulicate(element* e);
    void Travel();
    int SumList();
    bool DeleteFirst();
    bool DeleteTail();
    bool DeleteP(element* p);
    bool removeAll();
    int MaxList();
    int CountPrime();
    void InsertAfterP(element* Data, element* p);
    int CountDuplicate(int x);
    void Split2List(int x, linkedList* lessThanX, linkedList* greaterOrEqualX);
};

#endif // LINKEDLIST_H
