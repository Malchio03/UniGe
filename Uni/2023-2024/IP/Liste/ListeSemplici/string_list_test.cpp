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




                    // Main alternativo


/*
int main() {
    list myList = nullptr;

    // Test headInsert
    headInsert(myList, "Hello");
    headInsert(myList, "World");
    headInsert(myList, "Test");

    // Print the list
    std::cout << "List after headInsert operations: ";
    print(myList);
    std::cout << std::endl;

    // Test tailInsert
    tailInsert(myList, "Tail1");
    tailInsert(myList, "Tail2");

    // Print the list
    std::cout << "List after tailInsert operations: ";
    print(myList);
    std::cout << std::endl;

    // Test size
    std::cout << "Size of the list: " << size(myList) << std::endl;

    // Test isEmpty
    std::cout << "Is the list empty? " << (isEmpty(myList) ? "Yes" : "No") << std::endl;

    // Test getElem
    try {
        std::cout << "Element at index 2: " << getElem(myList, 2) << std::endl;
    } catch (const std::string &e) {
        std::cerr << "Exception: " << e << std::endl;
    }

    // Test insertAt
    try {
        insertAt(myList, "ciao", 2);
        std::cout << "List after insertAt operation at index 2: " << std::endl;
        print(myList);
        std::cout << std::endl;
    } catch (const std::string &e) {
        std::cerr << "Exception: " << e << std::endl;
    }

    // Test deleteAt
    try {
        deleteAt(myList, 0);
        std::cout << "List after deleteAt operation at index 2: " << std::endl;
        print(myList);
        std::cout << std::endl;
    } catch (const std::string &e) {
        std::cerr << "Exception: " << e << std::endl;
    }

    // Test deleteOnce
    deleteOnce(myList, "World");
    std::cout << "List after deleteOnce operation for 'Tail1': " << std::endl;
    print(myList);
    std::cout << std::endl;
    // Test deleteAll
    deleteAll(myList, "Tail2");
    std::cout << "List after deleteAll operation for 'Tail2': " << std::endl;
    print(myList);
    std::cout << std::endl;

    // Test read function (you can uncomment and test it interactively)
    // std::cout << "Enter values for the list (enter 'STOP!' to end):" << std::endl;
    // read(myList);
    // std::cout << "List after read operation: ";
    // print(myList);
    // std::cout << std::endl;

    return 0;
*/

