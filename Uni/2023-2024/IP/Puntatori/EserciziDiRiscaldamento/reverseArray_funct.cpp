#include <iostream>
using namespace std;

void reverseArray(int *source, int* dest, int size) {
    if (&source == &dest) {
        string err = "Indirizzo di source uguale a quello di dest";
        throw err;
    }
    for (int i = 0; i < size; ++i) {
        dest[i] = source[size - 1 - i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
}

int main() {
    const int N = 4;
    int source[N] = {1, 2 , 3 , 4};
    int dest[N] = {0, 0, 0, 0};

    // STAMPA DEI DUE ARRAY
    cout << "Stampa degli array prima dello scambio: " << endl;
    printArray(source, N);
    cout << endl;
    printArray(dest, N);
    cout << endl;

    reverseArray(source, dest, N);

    // STAMPA DEI DUE ARRAY DOPO LO SCAMBIO
    cout << "Stampa degli array dopo lo scambio: " << endl;
    printArray(source, N);
    cout << endl;
    printArray(dest, N);


    

}