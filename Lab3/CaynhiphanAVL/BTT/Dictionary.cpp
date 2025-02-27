// File: src/Dictionary.cpp
#include "Dictionary.h"
#include <fstream>
#include <iostream>

Dictionary::Dictionary() {}

Dictionary::~Dictionary() {}

void Dictionary::addWord(const string& english, const string& vietnamese) {
    Word word(english, vietnamese);
    tree.insert(word);
}

bool Dictionary::lookupWord(const string& english, string& vietnamese) const {
    return tree.search(english, vietnamese);
}

bool Dictionary::modifyWord(const string& english, const string& new_vietnamese) {
    return tree.modify(english, new_vietnamese);
}

void Dictionary::displayAll() const {
    tree.inOrderTraversal();
}

