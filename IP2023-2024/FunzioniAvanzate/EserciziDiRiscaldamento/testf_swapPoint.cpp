#include <iostream>
using namespace std;


struct Point {
    double x;
    double y;
};

// Se non passo per riferimento (&) la funzione non effettua lo scambio
void swapPoint(Point &P1, Point &P2) {
    double tempP1_x = P1.x;
    double tempP1_y = P1.y;

    P1.x = P2.x;
    P1.y = P2.y;

    P2.x = tempP1_x;
    P2.y = tempP1_y;

}

void printPoint(const Point& P) {
    cout << P.x << ", " << P.y << endl;
}

int main() {
    Point P1, P2;

    P1.x = 1.5;
    P1.y = 2.8;

    P2.x = 3.5;
    P2.y = 4.6;

    cout << "Valore di P1 prima dello scambio: " << endl;
    printPoint(P1);

    cout << "Valore di P2 prima dello scambio: " << endl;
    printPoint(P2);

    swapPoint(P1, P2);

    cout << "Valore di P1 dopo lo scambio: " << endl;
    printPoint(P1);

    cout << "Valore di P2 dopo lo scambio: " << endl;
    printPoint(P2);
    


}