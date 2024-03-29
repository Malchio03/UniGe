#include <iostream>
using namespace std;

const int N = 5;

struct array_str {
    int size = N;
    int array[N];
};

void reverseArray(const array_str& source, array_str& dest) {
    if (&source == &dest) {
        string err = "Indirizzo di source uguale a quello di dest";
        throw err;
    }

    if (source.size != dest.size) {
        string err = "Size diverse";
        throw err;
    }
    
    for (int i = 0; i < source.size; ++i) {
        dest.array[source.size - 1 - i] = source.array[i];
    }
}

void printArray(const array_str& source) {
    for (int i = 0; i < source.size; ++i) {
        cout << source.array[i] << " ";
    }
}

int main() {
    array_str source = {5, {1,2,3,4,5}};
    array_str dest = {5, {0,0,0,0,0}};

    // STAMPA DEI DUE ARRAY
    cout << "Stampa degli array prima dello scambio: " << endl;
    printArray(source);
    cout << endl;
    printArray(dest);
    cout << endl;

    reverseArray(source, dest);

    // STAMPA DEI DUE ARRAY DOPO LO SCAMBIO
    cout << "Stampa degli array dopo lo scambio: " << endl;
    printArray(source);
    cout << endl;
    printArray(dest);


    

}