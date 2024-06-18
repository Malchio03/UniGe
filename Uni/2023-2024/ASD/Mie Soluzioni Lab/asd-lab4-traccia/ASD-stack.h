#ifndef ASD_STACK_H
#define ASD_STACK_H

#include "ASD-token.h" // Assicurati che ASD-token.h sia incluso per definire il tipo token

namespace stack {
    // Definizione della struttura Stack per rappresentare una pila
    struct Stack {
        token* data; // Array dinamico per contenere gli elementi
        int capacity; // Capacità massima dello stack
        int size; // Numero attuale di elementi nello stack
    };

    // Prototipi delle funzioni da implementare
    Stack createEmpty();
    bool isEmpty(const Stack&);
    void push(const token&, Stack&);
    token pop(Stack&);
}

#endif
