#include "Library.h"
#include <iostream>
using namespace std;
Library::Library()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

Library::~Library()
{
}
void Library::InsertFirst(Book* e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        e->SetNextPointer(this->head);
        this->head = e;
    }
    this->nNum++;
}
void Library::InsertTail(Book* e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->SetNextPointer(e);
        this->tail = e;
    }
    this->nNum++;
}
void Library::printBooks()
{
    Book* currBook = this->head;
    while (currBook != nullptr)
    {
        cout << "Title: " << currBook->GetTitle() << endl;
        cout << "Authors: ";
        for (const auto& author : currBook->GetAuthors())
        {
            cout << author << " ";
        }
        cout << endl;
        cout << "Publisher: " << currBook->GetPublisher() << endl;
        cout << "Year: " << currBook->GetYear() << endl;
        cout << endl;
        currBook = currBook->GetNextPointer();

    }
}

int Library::countBooksByAuthor(string author) 
{
    int countBooks = 0;
    Book* currBook = this->head;
    while (currBook!=nullptr)
    {
        for (const auto& a : currBook->GetAuthors())
        {
            if (a == author) 
            {
                countBooks++;
                break;
            }
        }
        currBook = currBook->GetNextPointer();
    }
    return countBooks;
}

void Library::printBooksByPublisherAndYear(string publisher, int year)
{
    Book* currBook = this->head;
    while (currBook!=nullptr) 
    {
        if (currBook->GetPublisher() == publisher && currBook->GetYear() == year)
        {
            cout << "Title: " << currBook->GetTitle() << endl;
            cout << "Authors: ";
            for (const auto& author : currBook->GetAuthors())
            {
                cout << author << " ";
            }
            cout << endl;
            cout << "Publisher: " << currBook->GetPublisher() << endl;
            cout << "Year: " << currBook->GetYear() << endl;
            cout << endl;
        }
        currBook = currBook->GetNextPointer();
    }
}
