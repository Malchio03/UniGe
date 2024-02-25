#include <iostream>
using namespace std;

int main() {
    int b, B;
    do {
        cout << "Inserisci prima base " << endl;
        cin >> b;
        cout << "Inserisci seconda base " << endl;
        cin >> B;
        if (b > B) {
            cout << "Errore, la prima base deve essere <= della seconda" << endl;
        }
    } while(b > B);

    int h = (B - b) + 1;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < b + i; ++j) {
            cout << "x";
        }
        cout << endl;
    }

}
