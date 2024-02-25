#include <iostream>

using namespace std;

int main() {

    const int N = 30;
    int a[N] = {
        2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
        22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
        42, 44, 46, 48, 50, 52, 54, 56, 58, 60
    };

    int item;
    cout << "Quale elemento vuoi cercare? ";
    cin >> item;

    bool found = false;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        if (a[i] == item) {
            found = true;
            break;
        }
        count ++;
    }

    if (found) {
        cout << "numeri di accessi alla memoria: " << count;
    } else {
        cout << "Elemento non trovato";
    }
}