#include <iostream>
#include <string>
#include "circular.h"

using namespace std;

int main() {
    try {
        list myList = nullptr;
        headInsert(myList, "1");
        headInsert(myList, "2");
        headInsert(myList, "4");
        headInsert(myList, "14");
        insertAtTail(myList, "1");

        print(myList);
        cout << endl;

        cout << "Size: " << size(myList) << endl;

        cout << "InsertAt: ";
        insertAt(myList, "1", 2);

        print(myList);
        cout << endl;

        cout << "deleteAt: ";
        deleteAt(myList, 4);

        print(myList);
        cout << endl;

        cout << "getElem: " << getElem(myList, 3) << endl;

        cout << "DeleteOnce: ";
        deleteOnce(myList, "1");

        print(myList);
        cout << endl;

        cout << "DeleteAll: ";
        deleteALL(myList, "1");

        print(myList);
        cout << endl;
    
    } catch(string &err) {
        cout << err;
    }
}