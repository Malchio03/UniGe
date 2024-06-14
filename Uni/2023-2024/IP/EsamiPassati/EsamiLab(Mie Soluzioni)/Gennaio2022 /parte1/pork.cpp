#include <iostream>
#include "bow.h"
#include <vector>

void add(BagOfWords & b, const std::string w)
{
    bool found = false;
    for(unsigned int i = 0; i < b.size(); ++i) {
        // Se trovo l'elemento incremento il suo conteggio
        if (b[i].word == w) {
           ++b[i].num;
           found = true;
        }
    }
    if (!found) {
        // se W non è presente
        Entry newEntry;
        newEntry.num = 1;
        newEntry.word = w;
        b.push_back(newEntry);
    }
}

void del(BagOfWords & b, std::string w) {
    for(unsigned int i = 0; i < b.size(); ++i) {
        if (b[i].word == w && b[i].num > 1) {
            --b[i].num;
        } else if (b[i].word == w && b[i].num == 1) {
            for (int j = i; j < b.size(); ++j) {
                b[j] = b[j + 1];
            }
            b.pop_back();
        }
    }
}

// Restituisce conteggio
int count(const BagOfWords & b, std::string w)
{
    for (int i = 0; i < b.size(); ++i) {
        if (b[i].word == w) {
            return b[i].num;
        }
    } 
    return 0;
}
