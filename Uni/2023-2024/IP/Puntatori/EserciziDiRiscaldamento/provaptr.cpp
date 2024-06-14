#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";

    string *p = &s1;

    cout << "p contiene: " << p << endl;
    cout << "mentre con *p si ottiene: " << *p << endl;

    // assegnare all'area di memoria puntata da p la stringa "Ciao"
    *p = "Ciao";

    cout << "p contiene: " << p << endl;
    cout << "mentre con *p si ottiene: " << *p << endl;

    p = &s2;

    cout << "p contiene: " << p << endl;
    cout << "mentre con *p si ottiene: " << *p << endl;


    *p = "Mondo";

    cout << "p contiene: " << p << endl;
    cout << "mentre con *p si ottiene: " << *p << endl;

    cout << "Variabile s1 : " << s1  << " " << &s1  << endl;
    cout << "Variabile s2 : " << s2 << " " << &s2  << endl;

}