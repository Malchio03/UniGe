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

    double t = 0.0001;
    if (abs(P1.x - P2.x) < t && abs(P1.y - P2.y) < t ) {
        cout << "I punti sono uguali" << endl;
    } else {
        cout << "Il secondo punto e ";
        if (P2.y > P1.y) {
            cout << "in alto ";
        } else {
            cout << "in basso ";
        }

        if (P2.x > P1.x) {
            cout << "a destra ";
        } else {
            cout << "a sinistra ";
        }
        cout << "rispetto al primo";
    }

    
}