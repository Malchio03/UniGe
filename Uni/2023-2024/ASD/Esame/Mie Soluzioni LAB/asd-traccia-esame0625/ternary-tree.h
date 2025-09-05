#include <string>
#include <cstddef>

typedef int Elem;

struct terNode{
  Elem v1;
  Elem v2;
  terNode *left;
  terNode *middle;
  terNode *right;
};

typedef terNode *terTree;

const terTree emptyTerTree=nullptr;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di elementi (positivi) nel albero
unsigned int nbElem(const terTree&);

//Es 2
//Inserisce un nuovo elemento nel albero se questo elemento e' positivo
//e non e' gia' presente nel albero
void insert(Elem, terTree&);

//Es 3
//Ritorna una string con le valore (diverse da -1) degli elementi nel albero
//Separate da spazi e ordinate in ordine crescente
//La string finisce con uno spazio
std::string printElem(const terTree&);
