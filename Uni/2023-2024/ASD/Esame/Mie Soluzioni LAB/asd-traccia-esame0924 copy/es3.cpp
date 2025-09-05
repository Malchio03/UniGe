#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 3
//Ritorna la parola piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna la string vuota ""
string minWord(const dictTree& dt){

  if (dt == emptyDictTree) return "";

  string stampa = "";

  dictTree albero = dt;

  while(albero != emptyDictTree && albero -> val != '8') {
    stampa += albero ->val;
    albero = albero -> son;
  }

  return stampa;
}

