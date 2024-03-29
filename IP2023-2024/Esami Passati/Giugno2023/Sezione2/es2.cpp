#include "list.h"
#include <string> 
#include <iostream>

using namespace std;

string stampaAndata(List list) {
    string out = "";
    Cell* cur = list;
    while(cur!= nullptr) {
        out = out + cur -> city;
        if (cur -> next != nullptr) {
            out = out + ",";
        }
        cur = cur -> next;
    }
    return out;
}
