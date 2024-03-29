#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partion(int* array, int start, int end) {
     int pivot = array[end];
     int i = start - 1;

     for (int j = start; j <= end - 1; j++) {
          if (array[j] < pivot) {
               i++;
               int temp = array[i];
               array[i] = array[j];
               array[j] = temp;
          }
     }
     i++;
     int temp = array[i];
     array[i] = array[end];
     array[end] = temp;
     return i;
}

void quickSort(int* array, int start, int end) {
     if (end <= start) return; // Caso base

     int pivot = partion(array, start, end);
     quickSort(array, start, pivot - 1);
     quickSort(array, pivot + 1, end);
}

int main() {
    int array[9] = {8, 2, 5, 3, 9, 4, 7, 6, 1};

    // 0 sarebbe inizio array e 8 fine array
    quickSort(array, 0, 8);

    // Stampa l'array ordinato
    for (int i = 0; i < 9; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
