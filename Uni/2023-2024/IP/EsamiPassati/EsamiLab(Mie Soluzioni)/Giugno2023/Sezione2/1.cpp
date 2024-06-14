#include <iostream>
#include "list.h"
#include <string>

std::string stampaAndata(List list) {
    std::string out = "";

    Cell *cur = list;
    while (cur != nullptr) {
        out = out + cur -> city;
        if (cur -> next != nullptr) {
            out = out + ",";
        }
        cur = cur -> next;
    }
    return out;
}
