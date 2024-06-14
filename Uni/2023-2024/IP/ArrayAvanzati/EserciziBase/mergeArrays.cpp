#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int N = 9;
    const int M = 10;

    int s1[N];
    int s2[M];

    int Dimensione_totale = N + M;

    int d[Dimensione_totale];

    // Popolo l'array s1 con i numeri generati
    for (int i = 0; i < N; ++i) {
        int randomNumber = (rand()%256);
        s1[i] = randomNumber;
    }

    // Stampa di s1
    cout << "array s1 (generato) = { ";
    for (int i = 0; i < N; ++i) {
        cout << s1[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    for (int i = 0; i < M; ++i) {
        int randomNumber = (rand()%256);
        s2[i] = randomNumber;
    }

    // Stampa di s2
    cout << "array s2 (generato) = { ";
    for (int i = 0; i < M; ++i) {
        cout << s2[i];
        if (i < M - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    // Ordino in modo crescente s1
    int index_s1;
    for (int i = 0; i < N; ++i) {
        index_s1 = i;
        for (int j = i + 1; j < N; ++j) {
            if (s1[j] < s1[index_s1]) {
                index_s1 = j;
            }
        }
        int temp = s1[i];
        s1[i] = s1[index_s1];
        s1[index_s1] = temp;
    }

    // Ordino in modo crescente s2
    int index_s2;
    for (int i = 0; i < M; ++i) {
        index_s2 = i;
        for (int j = i + 1; j < M; ++j) {
            if (s2[j] < s2[index_s2]) {
                index_s2 = j;
            }
        }
        int temp = s2[i];
        s2[i] = s2[index_s2];
        s2[index_s2] = temp;
    }

    // Stampa di s1
    cout << "array s1 (ordinato) = { ";
    for (int i = 0; i < N; ++i) {
        cout << s1[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    // Stampa di s2
    cout << "array s2 (generato) = { ";
    for (int i = 0; i < M; ++i) {
        cout << s2[i];
        if (i < M - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    // Copio gli elementi di s1 in d
    for (int i = 0; i < N; ++i) {
        d[i] = s1[i];
    }

    // Copio gli elementi di s2 in d
    for (int i = 0; i < M; ++i) {
        d[N + i] = s2[i];
    }

    // Ordino in modo crescente d
    int index_d;
    for (int i = 0; i < Dimensione_totale; ++i) {
        index_d = i;
        for (int j = i + 1; j < Dimensione_totale; ++j) {
            if (d[j] < d[index_d]) {
                index_d = j;
            }
        }
        int temp = d[i];
        d[i] = d[index_d];
        d[index_d] = temp;
    }

    // Stampa d
    cout << "array d = { ";
    for (int i = 0; i < Dimensione_totale; ++i) {
        cout << d[i];
        if (i < Dimensione_totale - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;




     
}
