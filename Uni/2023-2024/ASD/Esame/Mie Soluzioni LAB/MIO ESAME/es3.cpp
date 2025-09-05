#include "priority-circ.h"

//Es 3
//Ritorna l'elemeto piu' vecchio con la priorita'ì piu' bassa della coda
//Se la coda e' vuota, ritora la string vuota ""
std::string removeFirst(list& li) {
  if (li == emptyList) return ""; // caso lista vuota

  // Trovo la cella con priorità minima
  list cur = li, minCell = li;
  while (cur != emptyList) {
      if (cur->priority < minCell->priority)
          minCell = cur;
      cur = cur->next;
  }

  //  Prendo il primo dopo la sentinella)
  dll aux = minCell->queue->next2;
  std::string valore = aux->val;

  // Rimuovo aux dalla coda circolare
  aux->prev2->next2 = aux->next2;
  aux->next2->prev2 = aux->prev2;
  delete aux;

  // Se la coda ora è vuota, elimino la cell
  if (minCell->queue->next2 == minCell->queue) {
      // coda vuota
      if (minCell == li) {
          // caso speciale: minCell è in testa
          li = li->next;
      } else {
          // scollego minCell dalla lista
          list prec = li;
          while (prec->next != minCell) prec = prec->next;
          prec->next = minCell->next;
      }
      delete minCell->queue; // elimino la sentinella
      delete minCell;
  }

  return valore;
}


 