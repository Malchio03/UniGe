#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Rect {
    Point top_left;
    Point bottom_right;
};

int main() {
    Rect R, R2;

    cout << "Inserisci le coordinate del primo rettangolo: ";
    cin >> R.top_left.x >> R.top_left.y >> R.bottom_right.x >> R.bottom_right.y ;

    cout << "Inserisci le coordinate del secondo rettangolo: ";
    cin >> R2.top_left.x >> R2.top_left.y >> R2.bottom_right.x >> R2.bottom_right.y ;

    // Verifica se il primo rettangolo è completamente contenuto nel secondo rettangolo
    if (R.top_left.x >= R2.top_left.x && R.top_left.y >= R2.top_left.y &&
        R.bottom_right.x <= R2.bottom_right.x && R.bottom_right.y <= R2.bottom_right.y) {
        cout << "Il primo rettangolo è contenuto nel secondo rettangolo." << endl;
    }
    // Verifica se il secondo rettangolo è completamente contenuto nel primo rettangolo
    else if (R2.top_left.x >= R.top_left.x && R2.top_left.y >= R.top_left.y &&
               R2.bottom_right.x <= R.bottom_right.x && R2.bottom_right.y <= R.bottom_right.y) {
        cout << "Il secondo rettangolo è contenuto nel primo rettangolo." << endl;
    }
    else {
        cout << "I rettangoli non sono contenuti uno nell'altro." << endl;
    }

}
