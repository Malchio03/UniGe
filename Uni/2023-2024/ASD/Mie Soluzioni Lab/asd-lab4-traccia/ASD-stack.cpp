#include "ASD-stack.h"
#include <iostream>
#include <string>

using namespace stack;
using namespace std; // Aggiungi questa linea per utilizzare correttamente il tipo string

// Restituisce uno stack vuoto
Stack stack::createEmpty() {
    Stack s;
    s.data = nullptr;
    s.capacity = 0;
    s.size = 0;
    return s;
}

// Restituisce true se lo stack è vuoto
bool stack::isEmpty(const Stack& st) {
    return st.size == 0;
}

// Aggiunge elem in cima allo stack
void stack::push(const token& elem, Stack& st) {
    if (st.size == st.capacity) {
        // Se lo stack è pieno, rialloca la memoria per aumentare la capacità
        int newCapacity = (st.capacity == 0) ? 1 : 2 * st.capacity;
        token* newData = new token[newCapacity];
        for (int i = 0; i < st.size; ++i) {
            newData[i] = st.data[i];
        }
        delete[] st.data;
        st.data = newData;
        st.capacity = newCapacity;
    }
    st.data[st.size++] = elem;
}

// Toglie dall'ultimo elemento dello stack e lo restituisce
// Solleva un'eccezione di tipo string se lo stack è vuoto
token stack::pop(Stack& st) {
    if (isEmpty(st)) {
        string err = "Errore: stack vuoto"; // Creazione dell'oggetto string
        throw err; // Lancio dell'oggetto string come eccezione
    }
    return st.data[--st.size];
}
