#include <iostream>
#include "ternary-tree.h"

using namespace std;

//Ritorna una string con le valore (diverse da -1) degli elementi nel albero
//Separate da spazi e ordinate in ordine crescente
//La string finisce con uno spazio
std::string printElem(const terTree& tr){
  string stampa = "";

  if (tr == emptyTerTree) return ""; // caso albero vuoto esco

  // scorro prima tutti i figli sinistri
  stampa += printElem(tr -> left);

  if (tr -> v1 != -1) {
    stampa += to_string(tr->v1) + " ";
  }

  // scorro figli centro
  stampa += printElem(tr -> middle);

  if (tr -> v2 != -1) {
    stampa += to_string(tr->v2) + " ";
  }

  // scorro figli destri
  stampa += printElem(tr -> right);

  return stampa;
}


