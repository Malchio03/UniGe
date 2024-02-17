#include <iostream>
#include "movestack.h"

// Aggiungi in testa
void push(MoveStack & ms, char cmd)
{
    Move *aux = new Move;
    aux -> cmd = cmd;
    aux -> next = ms;
    ms = aux;
}

// Leggi e rimuovi dalla testa
char pop(MoveStack & ms)
{
    char cmd = ms -> cmd;
    Move *temp = ms;
    ms = ms -> next;
    delete temp;
    return cmd;
    
}


// Esegue mossa
void doMove(int &x, int &y, char cmd) {
    // Aggiorna le coordinate in base al comando di movimento
    switch (cmd) {
        case 'N':
            y++; // Muovi verso nord (aumenta la coordinata y)
            break;
        case 'S':
            y--; // Muovi verso sud (diminuisci la coordinata y)
            break;
        case 'E':
            x++; // Muovi verso est (aumenta la coordinata x)
            break;
        case 'W':
            x--; // Muovi verso ovest (diminuisci la coordinata x)
            break;
        default:
            // Il comando non è valido, non fare nulla
            break;
    }
}

