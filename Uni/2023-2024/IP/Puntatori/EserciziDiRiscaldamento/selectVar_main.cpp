#include "selectVar_funct.h"
#include <iostream>

using namespace std;

int main() {
    char ch1 = 'a';
    char ch2 = 'b';
    char ch3 = 'c';

    char* selected = selectVar(ch1, ch2, ch3);
    if (selected == &ch1) {
        cout << "hai scelto ch1 che ha valore = " << ch1;
    } else if (selected == &ch2) {
        cout << "hai scelto ch2 che ha valore = " << ch2;
    } else if (selected == &ch3) {
        cout << "hai scelto ch1 che ha valore = " << ch3;
    } else {
        cout << "non hai scelto niente";
    }
}