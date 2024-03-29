#include <iostream>
using namespace std;

bool isOne(float a, float b, float c) {
    float result = a * b * c;
    result /= a;
    result /= b;
    result /= c;

    return result == 1;
}

int main() {
    float num1, num2, num3;
    cout << "Inserisci tre numeri float: ";
    cin >> num1 >> num2 >> num3;

    bool result = isOne(num1, num2, num3);
    
    if (result) {
        cout << "Il risultato dell'operazione è 1." << endl;
    } else {
        cout << "Il risultato dell'operazione non è 1." << endl;
    }
}
