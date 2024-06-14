#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

int partion(int a[], int inizio, int fine) {
    int pivot = a[inizio];
    int i = inizio + 1;

    for (int j = inizio + 1; j <= fine; ++j) {
        if (a[j] < pivot) {
            swap(a, i, j);
            ++i;
        }
    }
    swap(a, inizio, i - 1);
    return i - 1;
}

void quickSort(int a[], int inizio, int fine) {
    if (inizio < fine) {
        int pivot = partion(a, inizio, fine);
        quickSort(a, inizio, pivot - 1);
        quickSort(a, pivot + 1, fine);
    }
}

int main() {
    int array[7] = {6, 3, 7, 5, 1, 2, 4};
    quickSort(array, 0, 6);

    // Stampa l'array ordinato
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
