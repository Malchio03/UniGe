#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Triangle {
    Point vertex1;
    Point vertex2;
    Point vertex3;
    double area;
};

int main() {
    Triangle triangle1, triangle2, triangle3;

    // Input per il primo triangolo
    cout << "Triangolo 1:" << endl;
    cout << "Inserisci le coordinate del primo vertice (x y): ";
    cin >> triangle1.vertex1.x >> triangle1.vertex1.y;
    cout << "Inserisci le coordinate del secondo vertice (x y): ";
    cin >> triangle1.vertex2.x >> triangle1.vertex2.y;
    cout << "Inserisci le coordinate del terzo vertice (x y): ";
    cin >> triangle1.vertex3.x >> triangle1.vertex3.y;

    // Input per il secondo triangolo
    cout << "\nTriangolo 2:" << endl;
    cout << "Inserisci le coordinate del primo vertice (x y): ";
    cin >> triangle2.vertex1.x >> triangle2.vertex1.y;
    cout << "Inserisci le coordinate del secondo vertice (x y): ";
    cin >> triangle2.vertex2.x >> triangle2.vertex2.y;
    cout << "Inserisci le coordinate del terzo vertice (x y): ";
    cin >> triangle2.vertex3.x >> triangle2.vertex3.y;

    // Input per il terzo triangolo
    cout << "\nTriangolo 3:" << endl;
    cout << "Inserisci le coordinate del primo vertice (x y): ";
    cin >> triangle3.vertex1.x >> triangle3.vertex1.y;
    cout << "Inserisci le coordinate del secondo vertice (x y): ";
    cin >> triangle3.vertex2.x >> triangle3.vertex2.y;
    cout << "Inserisci le coordinate del terzo vertice (x y): ";
    cin >> triangle3.vertex3.x >> triangle3.vertex3.y;

    // Calcolo delle aree dei tre triangoli
    double side1_1 = sqrt(pow(triangle1.vertex2.x - triangle1.vertex1.x, 2) + pow(triangle1.vertex2.y - triangle1.vertex1.y, 2));
    double side2_1 = sqrt(pow(triangle1.vertex3.x - triangle1.vertex2.x, 2) + pow(triangle1.vertex3.y - triangle1.vertex2.y, 2));
    double side3_1 = sqrt(pow(triangle1.vertex1.x - triangle1.vertex3.x, 2) + pow(triangle1.vertex1.y - triangle1.vertex3.y, 2));
    double semiperimeter_1 = (side1_1 + side2_1 + side3_1) / 2;
    triangle1.area = sqrt(semiperimeter_1 * (semiperimeter_1 - side1_1) * (semiperimeter_1 - side2_1) * (semiperimeter_1 - side3_1));

    double side1_2 = sqrt(pow(triangle2.vertex2.x - triangle2.vertex1.x, 2) + pow(triangle2.vertex2.y - triangle2.vertex1.y, 2));
    double side2_2 = sqrt(pow(triangle2.vertex3.x - triangle2.vertex2.x, 2) + pow(triangle2.vertex3.y - triangle2.vertex2.y, 2));
    double side3_2 = sqrt(pow(triangle2.vertex1.x - triangle2.vertex3.x, 2) + pow(triangle2.vertex1.y - triangle2.vertex3.y, 2));
    double semiperimeter_2 = (side1_2 + side2_2 + side3_2) / 2;
    triangle2.area = sqrt(semiperimeter_2 * (semiperimeter_2 - side1_2) * (semiperimeter_2 - side2_2) * (semiperimeter_2 - side3_2));

    double side1_3 = sqrt(pow(triangle3.vertex2.x - triangle3.vertex1.x, 2) + pow(triangle3.vertex2.y - triangle3.vertex1.y, 2));
    double side2_3 = sqrt(pow(triangle3.vertex3.x - triangle3.vertex2.x, 2) + pow(triangle3.vertex3.y - triangle3.vertex2.y, 2));
    double side3_3 = sqrt(pow(triangle3.vertex1.x - triangle3.vertex3.x, 2) + pow(triangle3.vertex1.y - triangle3.vertex3.y, 2));
    double semiperimeter_3 = (side1_3 + side2_3 + side3_3) / 2;
    triangle3.area = sqrt(semiperimeter_3 * (semiperimeter_3 - side1_3) * (semiperimeter_3 - side2_3) * (semiperimeter_3 - side3_3));

    // Trova l'area massima e identifica il triangolo corrispondente
    double maxArea = triangle1.area;
    int maxIndex = 1;

    if (triangle2.area > maxArea) {
        maxArea = triangle2.area;
        maxIndex = 2;
    }

    if (triangle3.area > maxArea) {
        maxArea = triangle3.area;
        maxIndex = 3;
    }

    cout << "\nIl triangolo con area maggiore è il triangolo " << maxIndex << " con area " << maxArea << endl;
}
