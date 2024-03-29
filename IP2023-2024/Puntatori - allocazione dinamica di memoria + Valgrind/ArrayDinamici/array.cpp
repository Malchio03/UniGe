#include "array.h"
#include <iostream>

using namespace std;

void read_d_array(dynamic_array &d) {
    int s = -1;
    do {
        cout << "Inserisci la dimensione dell'Array: ";
        cin >> s;
    } while (s <=0);

    d.size = s;
    d.store = new double[s];
    for (int i = 0; i < s; ++i) {
        cout << "Inserisci valore: ";
        cin >> d.store[i];
    }
}

void print_d_array(const dynamic_array &d) {
    double *p = d.store;
    cout << "{ ";
    for (int i = 0; i < d.size; ++i) {
        cout << *p;
        if (i < d.size - 1) {
            cout << ", ";
        }
        ++p;
    }
    cout << " }" << endl;
}

void delete_d_array(dynamic_array &d) {
    if (d.size > 0) {
        delete[] d.store;
        d.size = 0;
    } else {
        string err = "Array gia vuoto";
        throw err;
    }
}

void create_d_array(dynamic_array &d, int size, double value) {
    // Caso di size negativa
    if (size < 0) {
        string err = "create_d_array: size negativa";
        throw err;
    }

    // Caso in cui l'array non sia vuoto
    if (d.size > 0) {
        delete_d_array(d);
    }

    d.size = size;
    d.store = new double[size];

    // Inizializzo tutti i valori a value
    for (int i = 0; i < d.size; ++i) {
        d.store[i] = value;
    }
}

void set_d_array_element(dynamic_array &d, unsigned int index, double value) {
    if (index < 0 || index > d.size) {
        string err = "set_array_element: out-of-range";
        throw err;
    }
    d.store[index] = value;
}

double get_d_array_element(const dynamic_array &d, unsigned int index) {
    if (index < 0 || index > d.size) {
        string err = "get_d_array_element: out-of-range";
        throw err;
    }
    return d.store[index];
}

void concat_d_arrays(const dynamic_array &t1, const dynamic_array &t2, dynamic_array &t3) {
    int newSize = t1.size + t2.size;
    t3.size = newSize;
    t3.store = new double[newSize];

    // Riempio la prima parte
    for (int i = 0; i < t1.size; ++i) {
        t3.store[i] = t1.store[i];
    }

    // Riempio la seconda parte
    for (int i = 0; i < t2.size; ++i) {
        t3.store[t1.size + i] = t2.store[i];
    }
}

void sort_d_array(dynamic_array &d) {
    int index;
    for (int i = 0; i < d.size - 1; ++i) {
        index = i;
        for (int j = i + 1; j < d.size; ++j) {
            if (d.store[j] < d.store[index]) {
                index = j;
            }
        }
        double temp = d.store[i];
        d.store[i] = d.store[index];
        d.store[index] = temp;
    }
}

int main() {
    try {
        dynamic_array arr1, arr2, result;
        
        // Lettura dei due array
        cout << "Primo array:" << endl;
        read_d_array(arr1);

        cout << "Secondo array:" << endl;
        read_d_array(arr2);

        // Concatenazione degli array
        concat_d_arrays(arr1, arr2, result);

        // Stampa del risultato della concatenazione
        cout << "Risultato della concatenazione:" << endl;
        print_d_array(result);

        // Ordinamento dell'array concatenato
        sort_d_array(result);
        cout << "Risultato dopo l'ordinamento:" << endl;
        print_d_array(result);

        // Deallocazione della memoria
        delete[] arr1.store;
        delete[] arr2.store;
        delete[] result.store;
    } catch (string &err) {
        cout << err << endl;
    }
}
