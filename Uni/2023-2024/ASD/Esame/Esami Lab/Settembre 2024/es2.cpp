#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 2
//Verifica se una parola è nell'dizionario
//Ritorna true se è presente e false altrimenti
bool isPresent(string st, const dictTree& dt){
  if (dt == emptyDictTree) {
    return false;
  }

  dictNode *cur = dt;
  for (unsigned int i = 0; i < st.size(); ++i) {
    while (cur != emptyDictTree && cur -> val != st[i]) {
      cur = cur -> brother;   // ci troviamo nella prima lettera, ci spostiamo nel fratello
    }
    // non esiste il fratello, non esiste la frase
    if (cur == emptyDictTree) {
      return false;
    }
    cur = cur -> son;
  }

  // parola trovata
  while (cur != emptyDictTree) {
    if (cur -> val == 8) {
      return true;
    }
    cur = cur -> brother;
  }

  return false;
}
