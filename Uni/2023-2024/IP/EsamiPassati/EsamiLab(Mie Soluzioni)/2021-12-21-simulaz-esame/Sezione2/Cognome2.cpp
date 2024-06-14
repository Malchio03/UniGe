#include <iostream>
#include <vector>
#include "AlbumLibrary.h"

using namespace std;

void sortAlbumLibrary(AlbumLibrary& AL) {
    unsigned int index;
    for (int i = 0; i < AL.size(); i++) {
        index = i;
        for (int j = i + 1; j < AL.size(); j++) {
            if (AL[j].year < AL[index].year || ((AL[j].year ==  AL[index].year) && (AL[j].title < AL[index].title))) {
                index = j;
            }
    }
    if (i != index) {
        Album temp = AL[i];
        AL[i] = AL[index];
        AL[index] = temp;
    }
}
}

void insertAlbum(const Album& A, AlbumLibrary& AL) {
    // Troviamo la posizione in cui inserire l'album A mantenendo l'ordine
    // alfabetico rispetto al titolo dell'album e l'ordine temporale rispetto all'anno
    size_t index = 0;
    while (index < AL.size() && (AL[index].title < A.title || (AL[index].title == A.title && AL[index].year <= A.year))) {
        ++index;
    }
    
    // Spostiamo gli elementi del vettore verso destra per fare spazio per l'inserimento di A
    AL.resize(AL.size() + 1);
    for (size_t i = AL.size() - 1; i > index; --i) {
        AL[i] = AL[i - 1];
    }
    
    // Inseriamo l'album A nella posizione trovata
    AL[index] = A;
}

    