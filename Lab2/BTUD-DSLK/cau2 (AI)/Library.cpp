#include "Library.h"
#include <iostream>
using namespace std;

Library::Library()
{
    head = nullptr;
}

void Library::InsertTail(Book* newBook)
{
    if (head == nullptr)
    {
        head = newBook;
    }
    else
    {
        Book* current = head;
        while (current->GetNextPointer() != nullptr)
        {
            current = current->GetNextPointer();
        }
        current->SetNextPointer(newBook);
    }
}

int Library::countBooksByAuthor(string author)
{
    int count = 0;
    Book *currBook = this->head;
    while (currBook != nullptr)
    {
        for (const auto& a : currBook->GetAuthors())
        {
            if (a == author)
            {
                count++;
                break;
            }
        }

        currBook = currBook->GetNextPointer();
    }

    return count;
}

void Library::printBooksByPublisherAndYear(string publisher, int year)
{
    Book *currBook = this->head;
    while (currBook != nullptr)
    {
        if(currBook->GetPublisher() == publisher && currBook->GetYear() == year)
        {
            cout << "Title: " << currBook->GetTitle() << endl;
            cout << "Authors: ";
            for (const auto& author : currBook->GetAuthors())
            {
                cout << author << ", ";
            }
            cout << endl;
            cout << "Publisher: " << currBook->GetPublisher() << endl;
            cout << "Year: " << currBook->GetYear() << endl;
            cout << endl;
        }

        currBook = currBook->GetNextPointer();
    }
}

