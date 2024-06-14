#include <cstddef> 
#include <iostream>
#include <stdexcept>
#include <vector> 
#include <fstream> 
#include <chrono>

using namespace std::chrono;
using namespace std;

// Implementa LIST con liste doppiamente collegate (doubly linked lists, DLL), semplici
 
namespace list{
 
typedef int Elem;

struct node;

typedef node* List;

const int FINEINPUT = -1000000;
const int EMPTYELEM = -1000000;

List const emptyList = nullptr;


/************************* operazioni stateful (con side effect) ******************************************/

void addBack(Elem, List&);  /* inserisce l'elemento alla fine della lista */
void addFront(Elem, List&); /* inserisce l'elemento all'inizio della lista */
void removeElem(Elem, List&); /* cancella l'elemento Elem dalla lista  */
bool isEmpty(const List&);
int size(const List&);
void createEmpty(List&);
}

list::List readFromFile(string);         /* legge il contenuto di una lista da file */
list::List readFromStdin();              /* legge il contenuto di una lista da standard input */
void print(const list::List&);           /* stampa la lista */

