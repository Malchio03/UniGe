#include "priority-circ.h"

//Es 1
//Ritorna il numero di elementi (string) nella coda
unsigned int nbElem(const list& li){
  unsigned int count = 0;

  // caso base, la lista e vuota
  if (li == emptyList) return 0;

  // puntatore per scorrere le priorita
  list cur = li;

  while(cur != emptyList){
    // controllo la sua queue, saltando la sentinella
    dll aux = (cur -> queue) -> next2;
    while(aux!= cur -> queue) { // faccio questo perche significa che arrivo alla fine della lista con sentinella
      // bisogna saltare la sentinella, per ora testo senza saltarla
      ++count;
      aux = aux -> next2;
    }
    cur = cur -> next;
  }
 
  return count;
}


