#include "Book.h"
#include <string> // Ensure to include string for std::to_string
#include <bits/stdc++.h>

// Constructor
Book::Book(string t, vector<string> a, string p, int y)
{
    title = t;
    author = a;
    publisher = p;
    year = y;
    next = nullptr;
}

// GetAuthors method
vector<string> Book::GetAuthors()
{
    return author;
}

// GetPublisher method
string Book::GetPublisher()
{
    return publisher;
}

// GetYear method
int Book::GetYear()
{
    return year;
}

// GetNextPointer method
Book* Book::GetNextPointer()
{
    return next;
}

// SetNextPointer method
void Book::SetNextPointer(Book* ptr)
{
    next = ptr;
}


