#include "list.h"
#include <string> 
#include <iostream>

using namespace std;

string stampaRitorno(List list) {
    string out = "";
    if (list == nullptr) {
        return out;
    }
    Cell* cur = list;
    // Primo ciclo che mi permette di arrivare in fondo 
    while(cur -> next != nullptr) {
        cur = cur -> next;
    }

    // Ciclo per tornare indietro
    while(cur != nullptr) {
        out = out + cur -> city;
        if (cur -> prev != nullptr) {
            out = out + ",";
        }
        cur = cur -> prev;
    }
    return out;
}
