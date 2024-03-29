#include <iostream>
#include <string>
using namespace std;

struct cell {
    string data;
    cell* next;
};
typedef cell* list;


void insertElemInOrderedList(list &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    cell *cur = l;
    cell *prev = nullptr;

    // Caso in testa 
    if (l == nullptr || l -> data > s) {
        aux -> next = l;
        l = aux;
        return; // Esce dalla funzione dopo l'inserimento
    }

    while (cur != nullptr && cur -> data < s) {
        prev = cur;
        cur = cur -> next;
    }

    // Controllo ripetizioni
    if (cur != nullptr && cur -> data == s) {
        delete aux;
        return;
    }

    prev -> next = aux;
    aux -> next = cur;
}


void recursive_printList(const list &l) {
    if (l == nullptr) {
        return;
    }
    cout << l -> data << " ";
    recursive_printList(l -> next);
}

void recursive_reversePrintList(const list &l) {
    if (l == nullptr) {
        return;
    }

    recursive_reversePrintList(l -> next);
    cout << l -> data << " ";
}

void recursive_deleteAllElementsFromList(list &l) {
    if (l == nullptr) {
        return;
    }

    recursive_printList(l -> next);
    delete l;
    l = nullptr;
}

bool recursive_isElementInOrderedList(const list &l, string x) {
    if (l == nullptr) {
        return false;
    }

    if (l -> data == x) {
        return true;
    }

    // Se l'elemento corrente è maggiore di quello cercato, allora l'elemento non è presente
    if (l -> data > x) {
        return false;
    }
    return recursive_isElementInOrderedList(l->next, x);
}

unsigned recursive_ListLength(const list &l) {
    if (l == nullptr) {
        return 0;
    }
    return recursive_ListLength(l -> next) + 1;
}

bool recursive_insertElemInOrderedList(list &l, string x) {
    // Caso base: se la lista è vuota o se il nuovo nodo deve essere inserito in testa
    if (l == nullptr || l->data > x) {
        cell *aux = new cell;
        aux->data = x;
        aux->next = l;
        l = aux;  
        return true;  
    }

    if (l -> data == x) {
        return false;
    }

    return recursive_insertElemInOrderedList(l->next, x);
}

bool recursive_removeElemFromOrderedList(list &l, string x) {
    if (l == nullptr) {
        return false;
    }

    if (l->data == x) {
        cell *cur = l;
        l = l -> next;
        delete cur;
        return true;
    }
    return recursive_removeElemFromOrderedList(l->next, x);
}



int main() {
    list l = nullptr;

    // Popola la lista e stampala
    insertElemInOrderedList(l, "1");
    insertElemInOrderedList(l, "3");
    insertElemInOrderedList(l, "5");
    insertElemInOrderedList(l, "6");
    insertElemInOrderedList(l, "6");
    insertElemInOrderedList(l, "7");
    insertElemInOrderedList(l, "5");
   
    cout << "Lista originale: ";
    recursive_printList(l);
    cout << endl;

    cout << "Lista Reverse: ";
    recursive_reversePrintList(l);
    cout << endl;

    //recursive_deleteAllElementsFromList(l);
    //recursive_printList(l);

    cout << boolalpha;
    cout << recursive_isElementInOrderedList(l, "7");
    cout << endl;

    cout << "Size lista: " << recursive_ListLength(l);
    cout << endl;

    cout << boolalpha;
    cout << recursive_insertElemInOrderedList(l, "4");
    cout << endl;
    recursive_printList(l);

    cout << boolalpha;
    cout << endl;
    cout << recursive_removeElemFromOrderedList(l , "4");
    cout << endl;
    recursive_printList(l);
}