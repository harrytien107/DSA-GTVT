// File: src/Word.h
#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

class Word {
public:
    string english;
    string vietnamese;

    Word() = default;
    Word(const string& eng, const string& vie)
        : english(eng), vietnamese(vie) {}
};

#endif // WORD_H