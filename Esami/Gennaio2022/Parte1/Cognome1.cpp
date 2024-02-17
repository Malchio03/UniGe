#include <iostream>
#include "bow.h"

void add(BagOfWords & b, const std::string w)
{
    bool found = false;
    for (int i = 0; i < b.size(); i++) {
        if (b[i].word == w) {
            b[i].num++;
            found = true;
            break;
        }
    }
    if (found == false) {
        Entry newentry;
        newentry.word = w;
        newentry.num = 1;
        b.push_back(newentry);
    }
}

void del(BagOfWords & b, std::string w) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i].word == w) {
            if (b[i].num > 1) {
                b[i].num --;
                break;
            } else if (b[i].num == 1) {
                int index = i;
                for (int j = index; j < b.size() - 1; j++) {
                    b[j].word = b[j + 1].word;
                }
                b.resize(b.size() - 1);
            }
        }
    }
}

// Restituisce conteggio
int count(const BagOfWords & b, std::string w)
{
    for (int i = 0; i < b.size(); i++) {
        if (b[i].word == w) {
            return b[i].num;
        }
    }
    return 0;
}
