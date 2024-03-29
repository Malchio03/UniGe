#include <iostream>
#include "vector.h"
using namespace std;

my_vector create_my_vector(unsigned int capacity) {
    if (capacity < 0) {
        string err = "create_my_vector: capacity negativa";
        throw err;
    }

    my_vector v;
    v.capacity = capacity;
    v.size = 0;
    v.store = new double[capacity];
    return v;
}

void print_my_vector_status(const my_vector &v) {
    cout << "**********************" << endl;
    cout << "my_vector size = " << v.size << endl;
    cout << "my_vector capacity = " << v.capacity << endl;

    cout << "my_vector store = { ";
    for (int i = 0; i < v.size; ++i) {
        cout << v.store[i] << " ";
        if (i < v.size - 1) {
            cout << ",";
        }
    }
    cout << "}" << endl;
    cout << "**********************" << endl;
}

void push_back_my_vector_element(my_vector &v, double x) {
    if (v.size == v.capacity) {
        string err = "push_back_my_vector_element: Impossibile inserire elemento in Array pieno";
        throw err;
    }

    if (v.size < v.capacity) {
        v.store[v.size] = x;
        v.size++;
    }    
}

double pop_back_my_vector_element(my_vector &v) {
    if (v.size == 0) {
        string err = "pop_back_my_vector_element: Impossibile estrarre elemento da Array vuoto";
        throw err;
    }
    if (v.size < 0) {
        string err = "pop_back_my_vector_element: size negativa";
        throw err;
    }
    double valore = v.store[v.size - 1];
    v.size--;
    return valore;
}

void set_my_vector_element(my_vector &v, double value, unsigned int index) {
    if (v.size == 0) {
        string err = "set_my_vector_element: Impossibile impostare un elemento di un My_Vector vuoto";
        throw err;
    }
    if (index < 0 || index > v.size - 1 ) {
        string err = "set_my_vector_element: Indice invalido";
        throw err;
    }
    v.store[index] = value;
}

double get_my_vector_element(const my_vector &v, unsigned int index) {
    if (v.size == 0) {
        string err = "get_my_vector_element: Impossibile leggere un elemento da un My_Vector vuoto";
        throw err;
    }
    if (index < 0 || index > v.size - 1 ) {
        string err = "get_my_vector_element: Indice fornito non ammissibile";
        throw err;
    }
    return v.store[index];
}

void resize_my_vector(my_vector &v, unsigned int new_capacity) {
    if (new_capacity <= 0) {
        string err = "resize_my_vector: new_capacity fornita non positiva";
        throw err;
    }    

    // Allocare un blocco lungo new_capacity
    double *new_store = new double[new_capacity];

    unsigned int num_elements_to_copy;
    if (v.size < new_capacity) {
        num_elements_to_copy = v.size;
    } else {
        num_elements_to_copy = new_capacity;
    }

    for (unsigned int i = 0; i < num_elements_to_copy; ++i) {
        new_store[i] = v.store[i];
    }

    delete[] v.store;

    v.store = new_store;
    v.capacity = new_capacity;
    v.size = num_elements_to_copy; 
}

void safe_push_back_my_vector_element(my_vector &v, double x) {

    if (v.capacity == 0) {
       resize_my_vector(v, 1);
    }
    if (v.size == v.capacity) {
        resize_my_vector(v, 2 * v.capacity);
    }

    if (v.size < v.capacity) {
        v.store[v.size] = x;
        v.size++;
    } 
}

void destroy_my_vector(my_vector &v) {
    if (v.capacity > 0) {
        delete[] v.store;
        v.size = 0;
        v.capacity = 0;
    }
}

bool looks_consistent_my_vector(const my_vector &v) {
    if (v.store != 0 && v.size > 0 && v.size < v.capacity && v.capacity > 0) {
        return true;
    }
    return false;
}

void sort_my_vector(my_vector &v) {
    unsigned int index;
    for (unsigned int i = 0; i < v.size; ++i) {
        index = i;
        for (unsigned int j = 0; j < v.size; ++j) {
            if (v.store[j] < v.store[index]) {
                index = j;
            } 
        }
        unsigned int temp = v.store[i];
        v.store[i] = v.store[index];
        v.store[index] = temp;
    }
}