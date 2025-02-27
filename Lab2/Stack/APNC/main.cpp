#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "element.h"
#include "element.cpp"
#include "linkedList.h"
#include "linkedList.cpp"

using namespace std;

int main()
{
    // --- Thao Tác với Stack ---
    cout << "=== Stack Operations ===" << endl;
    Stack *s = new Stack();

    // Thêm các giá trị vào Stack
    s->push(7);
    s->push(10);
    s->push(18);
    s->push(20);
    
    // In nội dung hiện tại của Stack
    s->printStack();
    
    // Lấy (pop) một phần tử ra khỏi Stack
    s->pop();
    cout << "\n";
    
    // In lại nội dung của Stack sau khi pop
    s->printStack();
    
    // Giải phóng bộ nhớ cho Stack
    delete s;

    // --- Thao Tác với Queue ---
    cout << "\n=== Queue Operations ===" << endl;
    Queue *q = new Queue();

    // Thêm các giá trị vào Queue
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    
    // In nội dung hiện tại của Queue
    q->printQueue();
    
    // Lấy (dequeue) một phần tử ra khỏi Queue
    q->dequeue();
    cout << "\n";
    
    // In lại nội dung của Queue sau khi dequeue
    q->printQueue();
    
    // Giải phóng bộ nhớ cho Queue
    delete q;

    return 0;
}