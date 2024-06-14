#include <iostream>
using namespace std;

void shiftRightArray(int* t,int size) {
    int temp = *(t + 0);
    for (int i = 0; i < size - 1; ++i) {
        *(t + i) = *(t + i + 1);
    }
    *(t + size - 1) = temp;

}

int main() {
    const int N = 7;
    int arr[N] = {1, 2, 3, 4, 5, 6, 7};

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
