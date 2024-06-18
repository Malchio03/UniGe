#include <iostream>
#include <string>

using namespace std;

bool isNumber(const string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test case 1: stringa contenente solo numeri
    string str1 = "12345";
    cout << str1 << " è un numero? " << (isNumber(str1) ? "Sì" : "No") << endl;

    // Test case 2: stringa contenente un mix di numeri e caratteri non numerici
    string str2 = "1234a";
    cout << str2 << " è un numero? " << (isNumber(str2) ? "Sì" : "No") << endl;

    // Test case 3: stringa vuota
    string str3 = "";
    cout << "Stringa vuota è un numero? " << (isNumber(str3) ? "Sì" : "No") << endl;

    // Test case 4: stringa contenente solo spazi
    string str4 = "     ";
    cout << str4 << " è un numero? " << (isNumber(str4) ? "Sì" : "No") << endl;

    return 0;
}
