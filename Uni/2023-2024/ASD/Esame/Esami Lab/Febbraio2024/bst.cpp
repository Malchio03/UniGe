#include "bst.h"
#include <iostream>

bool insertElem(Dictionary& d, const Key k, const Value v) {
    if (d == nullptr) {
        d = new bstNode;
        d->elem.key = k;
        d->elem.value = v;
        d->leftChild = nullptr;
        d->rightChild = nullptr;
        return true;
    }
    if (d->elem.key == k) {
        d->elem.value = v;
        return false;
    }
    if (k < d->elem.key) {
        return insertElem(d->leftChild, k, v);
    } else {
        return insertElem(d->rightChild, k, v);
    }
}

Value search(const Dictionary& d, const Key k) {
    if (d == nullptr) {
        return "";
    }
    if (d->elem.key == k) {
        return d->elem.value;
    }
    if (k < d->elem.key) {
        return search(d->leftChild, k);
    } else {
        return search(d->rightChild, k);
    }
}

Dictionary copy(const Dictionary& d) {
    if (d == nullptr) {
        return nullptr;
    }
    Dictionary newTree = new bstNode;
    newTree->elem.key = d->elem.key;
    newTree->elem.value = d->elem.value;
    newTree->leftChild = copy(d->leftChild);
    newTree->rightChild = copy(d->rightChild);
    return newTree;
}

// funzione ausiliare per delete elem, viene usata solo per il caso in cui il nodo ha due figli, mi sposto nel sottoalbero destro
Elem deleteMin(Dictionary& d) {
    if (d->leftChild == nullptr) {
        Elem tmpElem = d->elem;
        Dictionary tmpNode = d->rightChild;
        delete d;
        d = tmpNode;
        return tmpElem;
    } else {
        return deleteMin(d->leftChild);
    }
}

void deleteElem(Dictionary& d, const Key k) {
    if (d == nullptr) {
        return;
    }
    // se la chiave è minore del nodo corrente mi sposto a sinistra
    if (k < d->elem.key) {
        deleteElem(d->leftChild, k);
    } else if (k > d->elem.key) {   //se la chiave è maggioew del nodo corrente mi sposto a destra
        deleteElem(d->rightChild, k);
    } else {
        // caso 1: il nodo non ha figli
        if (d->leftChild == nullptr && d->rightChild == nullptr) {
            delete d;
            d = nullptr;
        } 
        // caso 2: il nodo ha solo il figlio sinistros
        else if (d->leftChild != nullptr && d->rightChild == nullptr) {
            Dictionary tmpNode = d->leftChild;
            delete d;
            d = tmpNode;
        }
        // caso 3: il nodo ha solo figlio destro
        else if (d->leftChild == nullptr && d->rightChild != nullptr) {
            Dictionary tmpNode = d->rightChild;
            delete d;
            d = tmpNode;
        } 
        // caso 4: il nodo ha 2 filgi
        else {
            d->elem = deleteMin(d->rightChild);
        }
    }
}
