#include <iostream>
using namespace std;

void hello() {
    cout << "Hello, world\n";
}

void hellomany(int n) {
    cout << "Hello, we are " << n << endl;
}

int givemefive() {
    return 5;
}

int prossimo (int n) {
    return n + 1;
}

int somma(int a, int b) {
    return a + b;
}

int main() {
    hello();
    hellomany(5);
    cout <<  givemefive();
    cout << endl;
    cout << prossimo(4);
    cout << endl;
    cout << somma(2, 3);
}