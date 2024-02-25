#include <iostream>
#include <string>
using namespace std;

struct Student {
    string matricola;
    string nome;
    string cognome;
    string Data_di_nascita;
    double voto_medio;
};

int main() {
    const int N = 3;

    Student studenti[N];
    for (int i = 0; i < N; i++) {
        cout << "\nInserisci informazioni per lo studente " << i + 1 << ":" << endl;
        cout << "Matricola: ";
        cin >> studenti[i].matricola;
        cout << "Nome: ";
        cin >> studenti[i].nome;
        cout << "Cognome: ";
        cin >> studenti[i].cognome;
        cout << "Data di nascita (AAAA/MM/GG): ";
        cin >> studenti[i].Data_di_nascita;
        cout << "Voto medio: ";
        cin >> studenti[i].voto_medio;
    }

    //  SortDown per l'ordinamento
    int index;
    for (int i = 0; i < N - 1; ++i) {
        index = i;
        for (int j = i + 1; j < N; ++j) {
            if (studenti[j].Data_di_nascita > studenti[index].Data_di_nascita) {
                index = j;
            }
        }
        Student temp = studenti[i];
        studenti[i] = studenti[index];
        studenti[index] = temp;
    }

    // Stampa gli studenti ordinati
    cout << "\nElenco degli studenti in ordine decrescente di data di nascita:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "\nStudente " << i + 1 << ":" << endl;
        cout << "Matricola: " << studenti[i].matricola << endl;
        cout << "Nome: " << studenti[i].nome << endl;
        cout << "Cognome: " << studenti[i].cognome << endl;
        cout << "Data di nascita: " << studenti[i].Data_di_nascita << endl;
        cout << "Voto medio: " << studenti[i].voto_medio << endl;
    }
}
