#ifndef LISTA
#define LISTA
#include <string>
#include <iostream>

// tipo contenuto della Cella
typedef std::string City;

// tipo Cell di una lista doppiamente linkata
struct Cell {
    City city;
    struct Cell* next;
    struct Cell* prev;
};
// tipo lista
typedef Cell* List;

void inserimentoInTesta(List &list, City newCity);
std::string stampaAndata(List list);
std::string stampaRitorno(List list);
std::string stampaAdiacenti(List list, City newCity);

#endif
