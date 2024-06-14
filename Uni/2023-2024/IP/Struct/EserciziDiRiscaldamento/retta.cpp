#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct StraightLine {
    double m;  // coefficente angolare
    double q; // quota
};

struct Point {
    double x;
    double y;
};

int main() {
    Point P;
    StraightLine R;

    cout << "Inserire i parametri della retta R: ";
    cin >> R.m >> R.q;

    cout << "Inserire le coordinate del punto P: ";
    cin >> P.x >> P.y;

    cout << "La retta R di equazione y = " << R.m << "x + " << R.q << endl;

    double distanza = abs(P.y - R.m * P.x - R.q);
    const double tolleranza = 0.0001; 
    if (distanza < tolleranza) {
        cout << "La retta passa per il punto di coordinate (" << P.x << ", " << P.y << ")" << endl;
    } else {
        cout << "La retta non passa per il punto di coordinate (" << P.x << ", " << P.y << ")" << endl;
    }
}
