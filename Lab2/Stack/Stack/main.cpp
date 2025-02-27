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

string ConvertDecimalToBinary(Stack* binaryNo, int decimalNo)
{
    string strBinNo = "";
    if(decimalNo == 0)
    {
        return "0";
    }
    while(decimalNo > 0)
    {
        int remainder = decimalNo % 2;
        binaryNo->push(remainder);
        decimalNo /= 2;
    }
    while(!binaryNo->isEmpty())
    {
        strBinNo += to_string(binaryNo->pop());
    }
    return strBinNo;
}

// bool sortTrainCarsStack(vector<int> inputTrainCarr, int outputTrainCarr[], int sizeTrainCarr) 
// {
//     Stack* stack = new Stack();
//     int outputIndex = 0;
//     for(int i = 0; i < sizeTrainCarr; i++)
//     {
//         stack->push(inputtrainCarr[i]);
//     }
// }

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
    cout << "\n=== Chuyen Doi Cac So Nhi Phan ===" << endl;
    int decimalNumber;
    cout << "Nhap mot so nguyen duong (co so 10): ";
    cin >> decimalNumber;

    Stack *binaryStack = new Stack();
    string binaryResult = ConvertDecimalToBinary(binaryStack, decimalNumber);
    cout << "Gia tri nhi phan: " << binaryResult << endl;

    // Giải phóng bộ nhớ cho Stack chuyển đổi
    delete binaryStack;
    return 0;
}




// int main()
// {
//     // Stack Operations
//     cout << "=== Stack  ===" << endl;
//     Stack* s = new Stack();

//     // Push 3 user-input values into the stack
//     int stackInput;
//     for(int i = 0; i < 3; ++i) {
//         cout << "Nhap gia tri vao stack(nhap 1 gia tri trong 1 cau lenh): ";
//         cin >> stackInput;
//         s->push(stackInput);
//     }

//     // Push an additional value to demonstrate popping beyond current size
//     s->push(20);

//     // Print Stack
//     cout << "Stack hien tai: ";
//     s->printStack();
//     cout << "\n";
//     // Pop 4 times
//     for(int i = 0; i < 4; ++i) {
//         int poppedValue = s->pop();
//         if(poppedValue != -1) {
//             cout << "Lay ra tu stack: " << poppedValue << endl;
//         }
//     }

//     // Attempt to pop once more to show empty stack message
//     int extraPop = s->pop();
//     if(extraPop != -1) {
//         cout << "Lay ra tu stack: " << extraPop << endl;
//     }

//     delete s;

//     // Queue Operations
//     cout << "\n=== Queue ===" << endl;
//     Queue* q = new Queue();

//     // Enqueue 3 user-input values into the queue
//     int queueInput;
//     for(int i = 0; i < 3; ++i) {
//         cout << "Nhap gia tri vao queue(nhap 1 gia tri trong 1 cau lenh): ";
//         cin >> queueInput;
//         q->enqueue(queueInput);
//     }

//     // Enqueue an additional value to demonstrate dequeuing beyond current size
//     q->enqueue(25);

//     // Print Queue
//     cout << "Queue hien tai: ";
//     q->printQueue();
//     cout << "\n";
//     // Dequeue 4 times
//     for(int i = 0; i < 4; ++i) {
//         int dequeuedValue = q->dequeue();
//         if(dequeuedValue != -1) {
//             cout << "Lay ra tu queue: " << dequeuedValue << endl;
//         }
//     }

//     // Attempt to dequeue once more to show empty queue message
//     int extraDequeue = q->dequeue();
//     if(extraDequeue != -1) {
//         cout << "Lay ra tu queue: " << extraDequeue << endl;
//     }

//     delete q;

//     return 0;
// }