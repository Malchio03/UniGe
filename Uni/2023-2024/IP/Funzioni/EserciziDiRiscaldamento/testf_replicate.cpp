#include <iostream>
using namespace std;

void replicate (int N, char c) {
    for (int i = 1; i <= N; ++i) {
        cout << c;
    }
}

int main() {
    replicate(10, 'x');
    cout << endl;
    replicate(1, 'x');
    cout << endl;
    replicate(0, 'x');
    cout << endl;
    replicate(-10, 'x');
    cout << endl;
}
