#include "double.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    list l;
    createEmpty(l);

    headInsert(l, "2");
    tailInsert(l, "3");
    headInsert(l, "1");
    tailInsert(l, "3");
    tailInsert(l, "1");
    print(l);

    cout << endl;

    cout << "Size: " << size(l) << endl;

    cout << boolalpha;
    cout << "Lista è vuota: " << isEmpty(l) << endl;

    try {
        cout << "Elemento i-esimo: " << getElem(l, 2) << endl;
    } catch (string& err) {
        cout << err << endl;
    }

    try {
        cout << "insertAT: " << endl;
        insertAt(l, "ok" , 2);
    } catch (string& err) {
        cout << err << endl;
    }

    print(l);

    cout << endl;

    try {
        cout << "deleteAT: " << endl;
        deleteAt(l, 4);
    } catch (string& err) {
        cout << err << endl;
    }
    print(l);

    cout << endl;

    try {
        cout << "deleteOnce: " << endl;
        deleteOnce(l, "32");
    } catch (string& err) {
        cout << err << endl;
    }
    print(l);

    cout << endl;

    try {
        cout << "deleteALL: " << endl;
        deleteALL(l, "2");
    } catch (string& err) {
        cout << err << endl;
    }
    print(l);
}