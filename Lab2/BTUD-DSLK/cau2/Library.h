#pragma once
#include "Book.h"
#include <string>
using namespace std;

class Library
{
private:
    Book* head;
    Book* tail;
    int nNum;
public:
    Library();
    ~Library();

    void InsertFirst(Book* e);
    void InsertTail(Book* e);
    void printBooks();
    int countBooksByAuthor(string author);
    void printBooksByPublisherAndYear(string publisher, int year);
};