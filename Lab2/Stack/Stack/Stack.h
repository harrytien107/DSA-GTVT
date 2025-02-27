#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"
#include <iostream>
using namespace std;

class Stack {
private: 
    int nNum;
    linkedList* linkedlist;
public:
    Stack();
    virtual ~Stack();
    void push(int);
    int pop();
    void printStack();
    bool isEmpty();
    int top();
};
#endif // STACK_H
