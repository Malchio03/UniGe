#include <iostream>
using namespace std;

void shiftRightArray(int* t,int size) {
    int temp = *(t + size - 1);
    for (int i = 0; i < size; ++i) {
        *(t + i) = *(t + i + 1);
    }

}

int main() {
    const int N = 5;
    int arr[N] = {1, 2, 3, 4, 5};

    cout << "Array prima dello shift: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Esegui lo shift verso destra
    shiftRightArray(arr, N);

    cout << "Array dopo lo shift: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
