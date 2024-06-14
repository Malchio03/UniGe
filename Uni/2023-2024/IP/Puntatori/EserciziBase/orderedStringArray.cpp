#include <iostream>
#include <string>
using namespace std;

bool orderedStringArray(string *t, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*(t + i) > *(t + j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int N = 5;
    string arr[N] = {"apple", "banana", "grape", "orange", "pear"};

    cout << boolalpha;
    cout << "Is the string array ordered? " << orderedStringArray(arr, N) << endl;
}