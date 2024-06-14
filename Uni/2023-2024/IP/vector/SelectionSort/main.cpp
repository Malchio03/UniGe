#include <iostream>
#include "selectionSort_vector.h"

int main () {
    // dichiarare un vector v di interi
    vector<int> v;
    // chiamare la funzione readVector su v
    readVector(v);
    // chiamare la funzione printVector su v
    printVector(v);
    // chiamare la funzione selectionSort_vector su v e true
    selectionSort_vector(v, true);
    // chiamare la funzione printVector su v (test: deve essere stampato ordinato crescente)
    printVector(v);

}