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
        cout << c;
    }
}

void triangle(int length) {
    if (length <= 0) {
        OutOfRangeError err;
        err.functionName = "triangle";
        err.paramName = "length";
        err.paramValue = length;
        throw err;
    }
    for (int i = 1; i <= length; ++i) {
        replicate(i, '*');
        cout << endl;
    }
}

int main() {
    try {
        cout << "Inserisci un numero maggiore di 0: ";
        int len;
        cin >> len;
        triangle(len);
    } catch (string& err) {
        cout << err;
    }
}