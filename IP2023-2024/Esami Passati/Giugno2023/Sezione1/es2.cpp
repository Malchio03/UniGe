#include "array.h"
#include <string> 
#include <iostream>

using namespace std;

//                                                       index/pos
//                                                          ||
string stampaKelementi(int arrayInteri[], int dimensione, int k) {
    string out = "";

    if (dimensione == 0) {
        return out;
    }
    // Se la dimensione è uguale a k stampo l'intero array
    if (k >= dimensione) {
        // Scorro l'array
        for (int i = 0; i < dimensione; ++i) {
            out = out + to_string(arrayInteri[i]);
            if (i < dimensione - 1) {
            out = out + ",";
        }
        }
    } else {
        // Scorro fino a pos(k)
        for (int i = 0; i < k; ++i) {
            out = out + to_string(arrayInteri[i]);
            if (i < k - 1) {
            out = out + ",";
        }
    }
}
return out;
}
