#include "string_ord_list.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ordList l = nullptr;
    ordList l2 = nullptr;

    insertElement(l, "2");
    insertElement(l, "1");
    insertElement(l, "22");
    insertElement(l, "3");
    //readList(l);

    insertElement(l2, "2");
    insertElement(l2, "3");
    insertElement(l2, "4");
    insertElement(l2, "22");
    insertElement(l2, "1");

    cout << "Prima lista: " << endl;
    printList(l);

    cout << endl;

    cout << "Seconda lista: " << endl;
    printList(l2);

    cout << endl;

    //cout << "Dimensione lista: " << listSize(l);

    cout << "concatLists: " << endl;
    ordList concactList = concatLists(l, l2);

    printList(concactList);

    cout << endl;

    cout << "UnionLists: " << endl;
    ordList UnionList = unionLists(l, l2);

    printList(UnionList);

    cout << endl;

    cout << "IntersectLists: " << endl;
    ordList IntersectLists = intersectLists(l, l2);

    printList(IntersectLists);





}
