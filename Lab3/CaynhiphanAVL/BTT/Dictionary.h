// File: src/Dictionary.h
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "AVLTree.h"
#include <string>
using namespace std;
class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    void addWord(const string& english, const string& vietnamese);
    bool lookupWord(const string& english, string& vietnamese) const;
    bool modifyWord(const string& english, const string& new_vietnamese);
    void displayAll() const;

private:
    AVLTree tree;
};

#endif // DICTIONARY_H