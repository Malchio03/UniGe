#include "list.h"
#include <string> 
#include <iostream>

using namespace std;

string stampaAdiacenti(List list, City newCity) {
    while (list != nullptr) {
        if (list->city == newCity) {
            std::string prevCity = "-";
            std::string nextCity = "-";
            if (list->prev != nullptr) {
                prevCity = list->prev->city;
            }
            if (list->next != nullptr) {
                nextCity = list->next->city;
            }
            return prevCity + "," + newCity + "," + nextCity;
        }
        list = list->next;
    }
    return "-,-,-"; 
}




