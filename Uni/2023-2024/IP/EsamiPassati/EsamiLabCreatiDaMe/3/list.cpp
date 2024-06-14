#include "list.h"
#include <iostream>

using namespace std;

void test_countOccurrences() {
    Cell c3 = {"C", nullptr};
    Cell c2 = {"B", &c3};
    Cell c1 = {"A", &c2};
    List list = &c1;

    cout << "Test countOccurrences:" << endl;
    bool test1 = (countOccurrences(list, "A") == 1);
    bool test2 = (countOccurrences(list, "B") == 1);
    bool test3 = (countOccurrences(list, "C") == 1);
    bool test4 = (countOccurrences(list, "D") == 0);

    cout << "Expected: 1, Got: " << countOccurrences(list, "A") << " - test superato? " << (test1 ? "si" : "no") << endl;
    cout << "Expected: 1, Got: " << countOccurrences(list, "B") << " - test superato? " << (test2 ? "si" : "no") << endl;
    cout << "Expected: 1, Got: " << countOccurrences(list, "C") << " - test superato? " << (test3 ? "si" : "no") << endl;
    cout << "Expected: 0, Got: " << countOccurrences(list, "D") << " - test superato? " << (test4 ? "si" : "no") << endl;
}

void test_insertElemInSortedOrder() {
    Cell c2 = {"B", nullptr};
    Cell c1 = {"A", &c2};
    List list = &c1;

    cout << "Test insertElemInSortedOrder:" << endl;
    insertElemInSortedOrder(list, "C");
    insertElemInSortedOrder(list, "D");
    insertElemInSortedOrder(list, "B");

    Cell* curr = list;
    bool testPassed = true;
    string expected[] = {"A", "B", "B", "C", "D"};
    int i = 0;
    while (curr) {
        if (curr->elem != expected[i]) {
            testPassed = false;
        }
        cout << curr->elem << " ";
        curr = curr->next;
        i++;
    }
    cout << endl << "test superato? " << (testPassed ? "si" : "no") << endl;
}

void test_reverseList() {
    Cell c4 = {"D", nullptr};
    Cell c3 = {"C", &c4};
    Cell c2 = {"B", &c3};
    Cell c1 = {"A", &c2};
    List list = &c1;

    cout << "Test reverseList:" << endl;
    reverseList(list);

    Cell* curr = list;
    bool testPassed = true;
    string expected[] = {"D", "C", "B", "A"};
    int i = 0;
    while (curr) {
        if (curr->elem != expected[i]) {
            testPassed = false;
        }
        cout << curr->elem << " ";
        curr = curr->next;
        i++;
    }
    cout << endl << "test superato? " << (testPassed ? "si" : "no") << endl;
}

int main() {
    test_countOccurrences();
    test_insertElemInSortedOrder();
    test_reverseList();
    return 0;
}
