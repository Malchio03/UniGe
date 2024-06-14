#include <iostream>
using namespace std;

bool isUpper(char* array, int size) {
    for (int i = 0; i < size; ++i) {
        if (*(array + i) < 'A' || *(array + i) > 'Z') {
            return false;
        }
    }
    return true;
}

int main() {
    const int N = 2;
    const int M = 3;

    char a[N][M] = {{'A', 'a', 'F'}, {'D', 'N', 'Z'}};

    cout << boolalpha;

    // Scorrere l'array utilizzando l'aritmetica dei puntatori
    for (int i = 0; i < N; ++i) {
        if (isUpper(a[i], M)) {
            cout << "La riga " << i << " contiene solo caratteri maiuscoli." << endl;
        } else {
            cout << "La riga " << i << " contiene caratteri non maiuscoli." << endl;
        }
    }
}
