#include <iostream>
#include "list.h"

void add_to_list(List &list, const std::string &elem) {
    List new_cell = new Cell;
    new_cell->elem = elem;
    new_cell->next = nullptr;
    if (!list) {
        list = new_cell;
    } else {
        List temp = list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_cell;
    }
}

void delete_list(List &list) {
    while (list) {
        List temp = list;
        list = list->next;
        delete temp;
    }
}

void test_computeListSize() {
    int nTest = 1;

    {
        List list = nullptr;
        unsigned int result = computeListSize(list);
        std::cout << "Test " << nTest << ": " << (result == 0 ? "superato" : "fallito") << std::endl;
        nTest++;
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        unsigned int result = computeListSize(list);
        std::cout << "Test " << nTest << ": " << (result == 1 ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        add_to_list(list, "B");
        unsigned int result = computeListSize(list);
        std::cout << "Test " << nTest << ": " << (result == 2 ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }
}

void test_insertElemInListAtIndex() {
    int nTest = 1;

    {
        List list = nullptr;
        bool result = insertElemInListAtIndex(list, "B", 0);
        std::cout << "Test " << nTest << ": " << (result ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        bool result = insertElemInListAtIndex(list, "B", 1);
        std::cout << "Test " << nTest << ": " << (result ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        bool result = insertElemInListAtIndex(list, "B", 2);
        std::cout << "Test " << nTest << ": " << (result ? "fallito" : "superato") << std::endl;
        nTest++;
        delete_list(list);
    }
}

void test_deleteLastInstanceOfElemInList() {
    int nTest = 1;

    {
        List list = nullptr;
        add_to_list(list, "A");
        add_to_list(list, "B");
        add_to_list(list, "A");
        add_to_list(list, "D");
        add_to_list(list, "C");
        add_to_list(list, "D");

        deleteLastInstanceOfElemInList(list, "D");
        bool passed = (list->next->next->next->next->elem == "C" && list->next->next->next->next->next == nullptr);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        add_to_list(list, "B");
        add_to_list(list, "A");
        add_to_list(list, "D");
        add_to_list(list, "C");
        add_to_list(list, "D");

        deleteLastInstanceOfElemInList(list, "A");
        bool passed = (list->next->next->next->next->elem == "D" && list->next->next->next->next->next == nullptr);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }

    {
        List list = nullptr;
        add_to_list(list, "A");
        add_to_list(list, "B");
        add_to_list(list, "A");
        add_to_list(list, "D");
        add_to_list(list, "C");
        add_to_list(list, "D");

        deleteLastInstanceOfElemInList(list, "C");
        bool passed = (list->next->next->next->next->elem == "D" && list->next->next->next->next->next == nullptr);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
        delete_list(list);
    }
}

int main() {
    test_computeListSize();
    test_insertElemInListAtIndex();
    test_deleteLastInstanceOfElemInList();
    return 0;
}
