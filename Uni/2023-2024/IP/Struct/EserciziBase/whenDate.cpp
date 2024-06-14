#include <iostream>
using namespace std;

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main() {
    Date D;
    D.day = 25;
    D.month = 2;
    D.year = 2024;

    Date D1;

    cout << "Inserisci l'anno: ";
    cin >> D1.year;

    // Verifica se l'anno è bisestile
    bool leapYear = (D1.year % 4 == 0 && D1.year % 100 != 0) || (D1.year % 400 == 0);

    cout << "Inserisci il mese: ";
    cin >> D1.month;

    // Verifica la correttezza del mese inserito
    if (D1.month < 1 || D1.month > 12) {
        cout << "Mese non valido." << endl;
        return 1;
    }

    cout << "Inserisci il giorno: ";
    cin >> D1.day;

    // Verifica il numero di giorni nel mese inserito
    int maxDaysInMonth;
    if (D1.month == 2) {
        if (leapYear) {
            maxDaysInMonth = 29;
        } else {
            maxDaysInMonth = 28;
        }
    } else if (D1.month == 4 || D1.month == 6 || D1.month == 9 || D1.month == 11) {
        maxDaysInMonth = 30;
    } else {
        maxDaysInMonth = 31;
    }

    // Verifica la correttezza del giorno inserito
    if (D1.day < 1 || D1.day > maxDaysInMonth) {
        cout << "Giorno non valido." << endl;
        return 1;
    }

    if (D1.year > D.year) {
        cout << "La data inserita è futura";
        return 20;
    } else if (D1.year == D.year && D1.day == D.day && D1.month == D.month) {
        cout << "La data è presente";
        return 21;
    } else if (D1.year < D.year) {
        cout << "La data è passata";
        return 22;
    } else if ((D1.year == D.year) && ((D1.day < D.day) || (D1.month < D.month))) {
        cout << "La data è passata";
        return 23;
    } else if ((D1.year == D.year) && ((D1.day > D.day) || (D1.month > D.month))) {
        cout << "La data è futura";
        return 24;
    }
}
