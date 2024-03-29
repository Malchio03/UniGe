#include <iostream>
using namespace std;

unsigned int maxArray(int *a, int size) {
    if (size == 0) {
        string err = "Size vale 0";
        throw err;
    }
    unsigned int max = 0;
    for (int i = 0; i < size; ++i) {
        if (*(a + i) > max) {
            max = *(a + i);
        }
    }
    return max;
}

int main() {
    const int N = 4;
    int a[N] = {1,22,300,4};
    cout << maxArray(a, N);
}