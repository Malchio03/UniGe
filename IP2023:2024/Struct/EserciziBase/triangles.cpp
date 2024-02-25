#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Triangle {
    Point vertice1;
    Point vertice2;
    Point vertice3;
    double area;
    double perimetro;
};

int main() {
    Triangle triangle;
    cout << "Inserisci le coordinate del primo vertice (x y): ";
    cin >> triangle.vertice1.x >> triangle.vertice1.y;

    cout << "Inserisci le coordinate del secondo vertice (x y): ";
    cin >> triangle.vertice2.x >> triangle.vertice2.y;

    cout << "Inserisci le coordinate del terzo vertice (x y): ";
    cin >> triangle.vertice3.x >> triangle.vertice3.y;

    // Calcolo del perimetro
    double lato1 = sqrt(pow(triangle.vertice2.x - triangle.vertice1.x, 2) + pow(triangle.vertice2.y - triangle.vertice1.y, 2));
    double lato2 = sqrt(pow(triangle.vertice3.x - triangle.vertice2.x, 2) + pow(triangle.vertice3.y - triangle.vertice2.y, 2));
    double lato3 = sqrt(pow(triangle.vertice1.x - triangle.vertice3.x, 2) + pow(triangle.vertice1.y - triangle.vertice3.y, 2));
    triangle.perimetro = lato1 + lato2 + lato3;

    // Calcolo dell'area
    double semiperimetro = triangle.perimetro / 2;
    triangle.area = sqrt(semiperimetro * (semiperimetro - lato1) * (semiperimetro - lato2) * (semiperimetro - lato3));

    cout << "Perimetro: " << triangle.perimetro << endl;
    cout << "Area: " << triangle.area;
}
