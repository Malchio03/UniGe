#include <iostream>
#include <cmath>
using namespace std;


void divide(int a, int b, int q, int r) {
    q = a / b;
    r = (a % b);

    cout << "Resto: " << r << endl;
    cout << "Quoziente: " << q << endl;

}



int main() {
    int a = 144;
    int b = 4;
    int q;
    int r;

    divide(a, b, q, r);
}