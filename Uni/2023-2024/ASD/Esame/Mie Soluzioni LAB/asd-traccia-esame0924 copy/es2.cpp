#include "dict-tree.h"

using namespace std;

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 2
//Verifica se una parola è nell'dizionario
//Ritorna true se è presente e false altrimenti
bool isPresent(string st, const dictTree& dt){
  if (dt == emptyDictTree) return false;

  if (dt -> val != st[0]) return false;

  // caso particolare, la stringa vale 1
  if (st.length() == 1) return dt -> val == st[0];

  // sono arrivato alla fine della stringa
  if (dt -> son != emptyDictTree && dt -> son -> val == '8'){
    return dt -> val == st[0];
  }

  if (dt -> val == st[0]) {
    return isPresent(st.substr(1), dt -> son);
  }

  return isPresent(st, dt -> brother);
}
