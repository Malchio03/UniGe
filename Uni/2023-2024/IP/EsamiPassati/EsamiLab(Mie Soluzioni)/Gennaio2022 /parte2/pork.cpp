#include <iostream>
#include "movestack.h"
using namespace std;



void push(MoveStack & ms, char cmd) {
    Movestack head = new MoveStack;
    head -> cmd = cmd;
    head -> next = ms;
    ms = head;
}

char pop(MoveStack & ms) {
    Movestack aux = ms;
    char elem = aux -> cmd;
    ms = ms -> next;
    delete aux;
    return elem;
}

void doMove(int &x, int &y, char cmd) {
    switch (cmd) {
        case 'E':
            ++x;
            break;
        case 'E';
            --x;
            break;
        case 'S':
            ++y;
            break;
        case 'N':
            --y;
        default:
            break;
    }
}