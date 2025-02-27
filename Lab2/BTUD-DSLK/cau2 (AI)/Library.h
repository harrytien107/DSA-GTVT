#pragma once
#include "Book.h"

class Library
{
private:
    Book* head;
public:
    Library();
    void InsertTail(Book* newBook);
    int countBooksByAuthor(string author);
    void printBooksByPublisherAndYear(string publisher, int year);
};