#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int* v;
    int* p;

    v = new int[N];
    p = new int[N];

    // CASO 1 => unico caso corretto
    delete[] v;
    delete[] p

    // CASO 2
    v = new int[N];
    delete[] v;
    delete[] p; // Provoca memory leak, poiché p non è stato deallocato

}