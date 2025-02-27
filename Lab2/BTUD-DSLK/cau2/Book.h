#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Book
{
private:
    string title;
    vector<string> author;
    string publisher;
    int year;
    Book *next;
public:
    Book(string, vector<string>, string, int);
    string GetTitle()
    {
        return title;
    }
    void SetTitle(int value)
    {
        title = value;
    }
    vector<string> GetAuthors();
    string GetPublisher();
    int GetYear();
    Book* GetNextPointer();
    void SetNextPointer(Book* nextBook);
};