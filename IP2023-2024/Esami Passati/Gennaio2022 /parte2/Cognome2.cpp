#include <iostream>
#include "movestack.h"

// Aggiungi in testa
void push(MoveStack & ms, char cmd)
{
    Move *aux = new Move;
    aux -> cmd =  cmd;
    aux -> next = ms;
    ms = aux;
}

// Leggi e rimuovi dalla testa
char pop(MoveStack & ms)
{
    Move *aux = ms;
    // Memorizzo il valore
    char element = aux -> cmd;
    ms = ms -> next;
    delete aux;
    return element;
}


// Esegue mossa
void doMove(int &x, int &y, char cmd) {
    // Aggiorna le coordinate in base al comando di movimento
    switch (cmd) {
        case 'N':
            --y;
            break;
        case 'S':
            ++y;
            break;
        case 'E':
            ++x;
            break;
        case 'W':
            --x;
            break;
        default:
            // Il comando non è valido, non fare nulla
            break;
    }
}

