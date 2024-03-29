#include "double.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    list l = nullptr;
    headInsert(l, "2");
    tailInsert(l, "52");
    headInsert(l, "3");
    tailInsert(l, "4");
    tailInsert(l, "5");
    print(l);

    cout << endl;

    cout << "Dimensione lista: " << size(l) << endl;

    cout << boolalpha;
    cout << "La lista è vuota: " << isEmpty(l) << endl;

    // Test di getElem
    try {
        cout << "Elemento i-esimo: " << getElem(l, 0) << endl; 
    } catch(string &err) {
        cout << err << endl;
    }

    // Test di insert at
    try {
        insertAt(l, "9" , 0);
    } catch(string &err) {
        cout << err << endl;
    }

    print(l);

    cout << endl;

    // Test di delete once
    try {
        deleteOnce(l, "ciao");
    } catch(string &err) {
        cout << err;
    }

    cout << endl;
    print(l);

    deleteALL(l, "5");
    cout << endl;
    print(l);

    deleteALL(l, "2");
    cout << endl;
    print(l);
}