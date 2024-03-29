#include <iostream>
using namespace std;

int factorial(int n) {
    if (n < 0) {
        cout << "Errore: n negativo";
        return - 1;
    }
    if (n == 0) {
        return 1;
    }

    for (int i = n - 1; i > 1; --i) {
        n = n * i;
    }
    return n;
}

int main() {
    cout << "Inserisci un numero positivo: ";
    int num;
    cin >> num;
    
    int result = factorial(num);

    if (num != 0){
       cout << result << " è il fattoriale di " << num;
    }
}
