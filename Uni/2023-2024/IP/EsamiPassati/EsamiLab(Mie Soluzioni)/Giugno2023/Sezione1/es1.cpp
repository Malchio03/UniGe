#include "array.h"
#include <string> 
#include <iostream>

using namespace std;

string stampa(int arrayInteri[], int dimensione) {
    // Dichiaro una string out, mi servirà per dopo
    string out = "";
    // Scorro l'array
    for (int i = 0; i < dimensione; ++i) {   // Uso int perche come paramentri nelle funzioni ho int, senno avrei usato unsigned int
        // "Stampo" 
        out = out + std::to_string(arrayInteri[i]);
        // "Stampo" la virgola
        if (i < dimensione - 1) {
            out = out + ",";
        }
    }
    // ritorno la stringa
    return out;
}
