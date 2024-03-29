#include <iostream>
#include <string>
using namespace std;

struct OutOfRangeError {
    string functionName;
    string paramName;
    string paramValue;

};

void replicate(int length, char c) {
    if (length <= 0) {
        OutOfRangeError err;
        err.functionName = "replicate";
        err.paramName = "length";
        err.paramValue = length;
        throw err;
    }
    for (int i = 1; i <= length; ++i) {
        cout << c << " ";
    }
}

int main() {
    try {
        cout << "Inserisci un numero maggiore di 0: ";
        int len;
        cin >> len;
        cout << "Inserisci il carattere da replicare: ";
        char c;
        cin >> c;
        replicate(len, c);
    } catch (string& err) {
        cout << err;
    }
}