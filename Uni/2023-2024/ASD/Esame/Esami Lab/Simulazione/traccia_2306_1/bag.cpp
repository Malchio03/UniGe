// SOSTITUIRE CON Nome Cognome Matricola

#include <iostream>

#include "bag.h"

using namespace bag;
using namespace std;


// DEFINIZIONE DELLA STRUTTURA DATI

const Bag emptyTree = nullptr;

struct bag::Node {
    Elem value;
    Node *left;
    Node *right;
};


// crea una nuova bag vuota
Bag bag::createEmpty()
{
    return emptyTree;
}

// ci dice se una bag è vuota
bool bag::isEmpty(const Bag b)
{
    return b == emptyTree;
}

// inserisce un elemento nella bag
void bag::insert(Bag &b, Elem e)
{
    if (isEmpty(b))
        b = new Node {e, emptyTree, emptyTree};
    else if (e <= b->value)
        insert(b->left, e);
    else
        insert(b->right, e);
}


// FUNZIONI DA IMPLEMENTARE

// stampa gli elementi della bag in ordine decrescente, su un'unica linea, separati da spazi
// non è necessario andare a capo a fine linea
void bag::printInReverseOrder(const Bag b)
{
}

// restituisce vero se l'elemento v esiste in due o più copie
// NOTA: se un nodo padre ha un elemento uguale al suo nel suo sottoalbero, deve essere il suo figlio sinistro
bool bag::isDuplicate(const Bag b, Elem v)
{
    return false;
}

// restituisce la somma di tutti gli elementi che hanno valore maggiore di v
Elem bag::sumLarger(const Bag b, Elem v)
{
    return 0;
}
