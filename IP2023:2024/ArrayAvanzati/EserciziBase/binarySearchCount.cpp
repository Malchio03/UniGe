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
    int max = N - 1;
    int mid = 0;
    int min = 0;
    int count = 0;

    while (min <= max && !found) {
        mid = (max + min) / 2;
        count++;
        if (a[mid] == item) {
            found = true;
            break;
        } else if (a[mid] > item) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    if (found) {
        cout << "Accessi di memoria: " << count;
    } else {
        cout << "Elemento non trovato";
    }

}