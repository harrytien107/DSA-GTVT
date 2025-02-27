#include <iostream>
#include "linkedlist.h"
#include "element.h"
#include "linkedlist.cpp"
#include "element.cpp"
using namespace std;
int main()
{
    linkedlist *list_ = new linkedlist();
    element *e;
    e = new element(9);
    list_->InsertTail(e);
    e = new element(10);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTail(e);
    list_->Travel();
    list_->DeleteFirst();
    cout << "\n";
    list_->Travel();
    //cau1
    cout << "\nSum of elements: " << list_->SumList() << endl;
    //cau2
    cout << "Max of elements: " << list_->MaxList() << endl;
    //cau3
    cout << "Number of prime elements: " << list_->CountPrime() << endl;
    //cau4
    // list_->InsertTail(15);  // 15
    // list_->Travel();
    //cau5
    // cout << "\n";
    // element* secondElement = list_->Gethead()->Getpointer();
    // list_->InsertAfter(secondElement, 20);
    // list_->Travel();    
    //cau6
    // cout << "\n";
    // list_->DeleteFirst();
    //cau7
    // list_->DeleteTail();
    // list_->Travel();
    //cau8
    // cout << "\n";
    // list_->DeleteAt(secondElement);
    // list_->Travel();
    //cau9
    // int x = 20;
    // cout << "\nNumber of elements with value: " << list_->CountValue(x) << endl;
    //cau10
    linkedlist* uniqueList = new linkedlist();
    uniqueList->InsertUnique(10);
    uniqueList->InsertUnique(20);
    uniqueList->InsertUnique(10); 
    uniqueList->InsertUnique(30);
    cout << "Unique list: ";
    uniqueList->Travel();
    delete uniqueList;
    //cau11
    linkedlist* lessThanX = new linkedlist();
    linkedlist* greaterThanX = new linkedlist();
    int x = 15;

    list_->SplitList(x, lessThanX, greaterThanX);

    cout << "\nElements less than " << x << ": ";
    lessThanX->Travel();
    cout << "\nElements greater than " << x << ": ";
    greaterThanX->Travel();

    delete lessThanX;
    delete greaterThanX;
    return 0;
}