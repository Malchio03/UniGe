#include <iostream>

using namespace std;

int main() {
    char answer;

    do {
        cout << "\nR o r colore rosso" << endl;
        cout << "V o v colore verde" << endl;
        cout << "B o b colore blu" << endl;
        cout << "G o g colore giallo" << endl;
        cout << "A o a colore arancione" << endl;
        cout << "Fai una scelta: ";
        cin >> answer;

        switch (answer) {
            case 'R':
            case 'r':
                cout << "\nHai scelto rosso" << endl;
                break;
            case 'V':
            case 'v':
                cout << "\nHai scelto verde" << endl;
                break;
            case 'B':
            case 'b':
                cout << "\nHai scelto blu" << endl;
                break;
            case 'G':
            case 'g':
                cout << "\nHai scelto giallo" << endl;
                break;
            case 'A':
            case 'a':
                cout << "\nHai scelto arancione" << endl;
                break;
            default:
                cout << "\nScelta non valida" << endl;
        }
    } while(answer != 'R' && answer != 'r' && answer != 'V' && answer != 'v' && answer != 'B' && answer != 'b' && answer != 'G' && answer != 'g' && answer != 'A' && answer != 'a');

}
