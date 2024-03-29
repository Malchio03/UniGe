#include "hist.h"
#include <string>
#include <vector>


// Aggiunge
void add(Hist& h, int v) {
    // Cerca se il valore è già presente in h
    bool found = false;
    for (int i = 0; i < h.size(); ++i) {
        if (h[i].value == v) {
            h[i].num++;
            found = true;
            break;
        }
    }
    // Se il valore non è stato trovato, crea una nuova Bin e aggiungila a h
    if (!found) {
        Bin newBin;
        newBin.value = v;
        newBin.num = 1;
        h.push_back(newBin);
    }
}

// ordina
void sort(Hist & h)
{
    int index;
    for (int i = 0; i < h.size(); i++) {
        index = i;
        for (int j = i + 1; j < h.size(); j++) {
            if (h[j].value < h[index].value) {
                index = j;
            }
        }
        int temp = h[i].value;
        h[i].value = h[index].value;
        h[index].value = temp;
    }
}

// Cerca, restituisce conteggio
int count(const Hist& h, int v) {
    // Cerca il valore v e restituisce il suo conteggio
    for (int i = 0; i < h.size(); ++i) {
        if (h[i].value == v) {
            return h[i].num;
        }
    }
    // Se il valore non è presente, restituisci 0
    return 0;
}