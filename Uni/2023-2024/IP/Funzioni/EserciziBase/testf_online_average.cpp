#include <iostream>
using namespace std;

double onlineAverage() {
    char answer;
    int n;
    double sum = 0;
    int i = 0;

    do {
        cout << "Inserisci un numero reale: ";
        cin >> n;

        sum += n;
        i++;

        cout << "Vuoi continuare? (y per continuare, n per smettere) ";
        cin >> answer;
    } while (answer != 'n');

    return sum / i;
}

int main() {
    cout << "La media dei numeri inseriti è: " << onlineAverage() << endl;
}