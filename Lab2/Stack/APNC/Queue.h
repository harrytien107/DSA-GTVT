#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <iostream>
using namespace std;

class Queue {
private:
    int nNum;
    linkedList* linkedlist;

public:
    Queue();
    virtual ~Queue();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void printQueue();
    int front();
    int rear();
};

#endif // QUEUE_H
