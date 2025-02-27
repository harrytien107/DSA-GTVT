#include <iostream>
#include "Library.h"
#include "Library.cpp"
#include "Book.h"
#include "Book.cpp"
using namespace std;

// int main()
// {
//     Library lib;
//     Book* book1;
//     Book* book2;
//     Book* book3;
//     Book* book4;
//     book1 = new Book("Book1", {"Author1", "Author2"}, "Publisher1", 2020);
//     book2 = new Book("Book2", {"Author3", "Author4"}, "Publisher2", 2021);
//     book3 = new Book("Book3", {"Author5", "Author6"}, "Publisher3", 2022);
//     book4 = new Book("Book4", {"Author7", "Author8"}, "Publisher1", 2020);
//     lib.InsertTail(book1);
//     lib.InsertTail(book2);
//     lib.InsertTail(book3);
//     lib.InsertTail(book4);

//     cout << lib.countBooksByAuthor("Author1");
//     cout << "\n";
//     lib.printBooksByPublisherAndYear("Publisher1", 2020);
//     return 0;
// } 
int main()
{
    // Library lib;
    // int n;
    // cout << "Enter number of books: ";
    // cin >> n;
    // cin.ignore(); // To ignore the newline after the number

    // for(int i = 0; i < n; ++i){
    //     string title, publisher;
    //     int year, numAuthors;
    //     vector<string> authors;

    //     cout << "Enter title of book " << i+1 << ": ";
    //     getline(cin, title);

    //     cout << "Enter number of authors for book " << i+1 << ": ";
    //     cin >> numAuthors;
    //     cin.ignore();

    //     for(int j = 0; j < numAuthors; ++j){
    //         string author;
    //         cout << "Enter author " << j+1 << ": ";
    //         getline(cin, author);
    //         authors.push_back(author);
    //     }

    //     cout << "Enter publisher of book " << i+1 << ": ";
    //     getline(cin, publisher);

    //     cout << "Enter year of publication for book " << i+1 << ": ";
    //     cin >> year;
    //     cin.ignore();

    //     Book* book = new Book(title, authors, publisher, year);
    //     lib.InsertTail(book);
    // }
    Library lib;
    Book* book1;
    Book* book2;
    Book* book3;
    Book* book4;
    book1 = new Book("Book1", {"Author1", "Author2"}, "Publisher1", 2020);
    book2 = new Book("Book2", {"Author3", "Author4"}, "Publisher2", 2021);
    book3 = new Book("Book3", {"Author5", "Author6"}, "Publisher2", 2022);
    book4 = new Book("Book4", {"Author7", "Author8"}, "Publisher1", 2020);
    lib.InsertTail(book1);
    lib.InsertTail(book2);
    lib.InsertTail(book3);
    lib.InsertTail(book4);

    // Part b: Count books by a specific author
    string searchAuthor;
    cout << "Enter author name to count their books: ";
    getline(cin, searchAuthor);
    cout << "Number of books by " << searchAuthor << ": " << lib.countBooksByAuthor(searchAuthor) << "\n";

    // Part c: List books by publisher and year
    string searchPublisher;
    int searchYear;
    cout << "Enter publisher name: ";
    getline(cin, searchPublisher);
    cout << "Enter year: ";
    cin >> searchYear;
    cin.ignore();

    lib.printBooksByPublisherAndYear(searchPublisher, searchYear);

    return 0;
}