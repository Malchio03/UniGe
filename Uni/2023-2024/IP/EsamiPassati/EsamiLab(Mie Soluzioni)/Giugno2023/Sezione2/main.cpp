#include <iostream>
#include "list.h"

// Funzione per stampare la lista
void stampaLista(const List& list) {
    Cell* current = list;
    while (current != nullptr) {
        std::cout << current->city << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void eliminaLista(List& list) {
    if (list == nullptr) {
        return; // Se la lista è già nulla, non c'è nulla da fare
    }

    Cell* current = list;
    while (current != nullptr) {
        Cell* temp = current;
        current = current->next;
        delete temp;
    }
    list = nullptr; // Imposta il puntatore della lista a nullptr
}


int main() {
    // Creazione di alcune città
    City pisa("Pisa");
    City genova("Genova");
    City milano("Milano");
    City venezia("Venezia");
    City napoli("Napoli");
    City firenze("Firenze");

    // Creazione di una lista vuota
    List lista = nullptr;

    // Inserimento delle città nella lista
    inserimentoInTesta(lista, firenze);
    inserimentoInTesta(lista, napoli);
    inserimentoInTesta(lista, venezia);
    inserimentoInTesta(lista, milano);
    inserimentoInTesta(lista, genova);
    inserimentoInTesta(lista, pisa);

    // Stampare la lista per verificare l'inserimento
    std::cout << "Inserimento in testa lista con elementi:";
    stampaLista(lista);

    // Test stampaAdiacenti
    std::cout << "Adiacenti a Milano: " << stampaAdiacenti(lista, "Milano") << std::endl; // Output: Genova,Milano,Venezia
    std::cout << "Adiacenti a Genova: " << stampaAdiacenti(lista, "Genova") << std::endl; // Output: Pisa,Genova,Milano
    std::cout << "Adiacenti a Pisa: " << stampaAdiacenti(lista, "Pisa") << std::endl; // Output: -,Pisa,Genova
    std::cout << "Adiacenti a Napoli: " << stampaAdiacenti(lista, "Napoli") << std::endl; // Output: Venezia,Napoli,Firenze
    std::cout << "Adiacenti a Firenze: " << stampaAdiacenti(lista, "Firenze") << std::endl; // Output: Napoli,Firenze,-

    // Test per una città non trovata
    std::cout << "Adiacenti a Roma: " << stampaAdiacenti(lista, "Roma") << std::endl; // Output: -,-,- 
}



