#include <iostream>
#include <string>
#include <cmath>
using namespace std;

 struct Point {
        double x;
        double y;
    };

int main() {
    Point P1;
    Point P2;

    cout << "Inserire le coordinate del punto P1: ";
    cin >> P1.x >> P1.y;

    cout << "Inserire le coordinate del punto P2: ";
    cin >> P2.x >> P2.y;

    double parentesi_x = pow(P2.x - P1.x, 2);
    double parentesi_y = pow(P2.y - P1.y, 2);

    double distanza = sqrt(parentesi_x + parentesi_y);

    cout << "La distanza tra i due punti vale: " << distanza;
    
}