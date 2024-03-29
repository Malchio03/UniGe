#include <iostream>
#include <string>
#include "string_list.h"
using namespace std;

int main() {
    list l = nullptr;
    tailInsert(l, "2");
    tailInsert(l, "3");
    headInsert(l, "1");
    tailInsert(l, "ok");
    tailInsert(l, "ok");

    print(l);

    cout << endl;

    cout << "Dimensione lista: " << size(l);

    cout << boolalpha;
    cout << "\nLa lista è vuota: " << isEmpty(l) << endl;

      try {
        string elem = getElem(l, 2); 
        cout << "Elemento alla posizione 2: " << elem << endl;
    } catch (const string& err) {
        cout << err << endl;
    }
    cout << "Insert At:" << endl;
    try {
        insertAt(l, "ok", 1);
    } catch (const string& err){
        cout << err << endl;
    }

    print(l);

    cout << endl;

    cout << "delete At:";
    try {
        deleteAt(l, 0);
    } catch(const string& err) {
        cout << err;
    }

    cout << endl;
   
    print(l);

    cout << endl;

    cout << "deleteOnce:" << endl;

    deleteOnce(l, "2");
    print(l);

    cout << endl;

    cout << "deleteAll:" << endl;
    deleteAll(l, "3");

    print(l);
}