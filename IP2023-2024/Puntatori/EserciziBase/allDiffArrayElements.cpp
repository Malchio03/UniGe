#include <iostream>
using namespace std;

bool allDiffArrayElements(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*(a + i) == *(a + j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int N = 4;
    int a[N] = {22 ,4,22};
    cout << boolalpha;
    cout << allDiffArrayElements(a, N);
}