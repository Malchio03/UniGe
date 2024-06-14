#include <iostream>
#include <cmath>
using namespace std;



bool Radice(double x, double sqrt_x) {
   return sqrt(x) == sqrt_x;
}



int main() {
    bool a = Radice(25.3268614564, 5.03258);
    cout << a;
}