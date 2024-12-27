#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 3
//Ritorna la parola piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna la string vuota ""
string minWord(const dictTree& dt){
  if (dt == emptyDictTree) {
    return "";
  } 

  string word = "";
  dictNode *cur = dt;
  
  while (cur != emptyDictTree) {
    if (cur -> val == 8) {
      return word;
    }
    word += cur -> val;
    cur = cur -> son;
  }

  return word;

}

