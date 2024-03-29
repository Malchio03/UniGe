#include <iostream>
using namespace std;


void printArray(int *s, int size) {
    for (int i = 0; i <= size - 1; ++i) {
        cout << *s << " ";
        s++;
    }
}

void printArrayWithIndex(int s[], int size) {
    for (int i = 0; i <= size - 1; ++i) {
        cout << s[i] << " ";
    }
}


int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = nullptr;
    p = a;

    cout << "PrintArray con puntatore: " << endl;
    printArray(p, 5);
    cout << endl;

    cout << "PrintArray senza aritmetica dei puntatori: " << endl;
    printArrayWithIndex(a, 5); 

    int b[1] = {1};
    p = b;
    cout << endl;

    cout << "PrintArray con puntatore: " << endl;
    printArray(p, 1);

    cout << endl;
    cout << "PrintArray senza aritmetica dei puntatori: " << endl;
    printArrayWithIndex(b, 1); 

    int c[0];
    p = c;
    cout << endl;

    cout << "PrintArray con puntatore: " << endl;
    printArray(p, 0);
    cout << endl;
    
    cout << "PrintArray senza aritmetica dei puntatori: " << endl;
    printArrayWithIndex(c, 0); 
}