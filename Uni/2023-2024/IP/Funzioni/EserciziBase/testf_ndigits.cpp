#include <iostream>
using namespace std;

int getLength(int n) {
    int i = 0;
    while (n > 0) {
        n = n / 10;
        i++;
    }
    return i;
}

int main() {
    int a[5] = {100, 234, 27458, 4, 0};

    for (int i = 0; i < 5; ++i) {
        cout << boolalpha;
        cout << "Il numero " << a[i] << " ha : ";
        cout << getLength(a[i]) << " cifre";
        cout << endl;
    }
}