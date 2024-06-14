#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int* v;

    // Per allocare un blocco di memoria necessaria per memorizzare N elementi di tipo T si usa new T[N]
    v = new int[N];

    for (int i = 0; i < N; ++i) {
        v[i] = 2 * i + 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << *(v + i) << " ";
    }

    delete[] v;

    v = new int[N *2];

    for (int i = 0; i < N; ++i) {
        v[i] = 2 * i + 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << *(v + i) << " ";
    }

    delete[] v;
}