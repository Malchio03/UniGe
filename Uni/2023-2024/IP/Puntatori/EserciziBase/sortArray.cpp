#include <iostream>
using namespace std;

void sortArrayInv(int* t, int size){
    int index;
    for (int i = 0; i < size - 1; ++i) {
        index = i;
        for (int j = i + 1; j < size; ++j) {
            if (t[j] > t[index]) {
                index = j;
            }
        }
        int temp = t[i];
        t[i] = t[index];
        t[index] = temp;
    }
}

int main() {
    const int N = 7;
    int arr[N] = {1, 20, 3, 4, 5, 6, 7};

    // Esegui l'ordinamento
    sortArrayInv(arr, N);

    cout << "Array dopo lo shift: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
