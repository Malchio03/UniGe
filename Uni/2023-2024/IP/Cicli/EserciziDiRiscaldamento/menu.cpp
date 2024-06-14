#include <iostream>

using namespace std;

int main() {
   int answer;

   do {
    cout << "\n1 Prima scelta" << endl;
    cout << "2 Seconda scelta" << endl;
    cout << "3 Terza scelta" << endl;
    cout << "0 Uscita programma" << endl;
    cout << "Fai una scelta: " << endl;
    cin >> answer;

    switch (answer) {
            case 1:
                cout << "\nHai fatto la prima scelta" << endl;
                break;
            case 2:
                cout << "\nHai fatto la seconda scelta" << endl;
                break;
            case 3:
                cout << "\nHai fatto la terza scelta" << endl;
                break;
            case 0:
                cout << "\nHai scelto di uscire dal programma." << endl;
                break;
            default:
                cout << "\nScelta non valida" << endl;
                break;
        }
   } while(answer != 0);
}