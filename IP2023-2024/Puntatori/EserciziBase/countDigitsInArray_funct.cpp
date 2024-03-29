#include <iostream>

using namespace std;

unsigned int countDigitsInArray(char *v, int N) {
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i] >= '0' && v[i] <= '9') {
            index++;
        }
    }
    return index;
}

int main() {
    const int N = 6;
    char v[N] = {'f','4','c','3','5','R'};

    cout << countDigitsInArray(v, N);
}