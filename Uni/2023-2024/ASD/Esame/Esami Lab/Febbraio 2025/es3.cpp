#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Verifica se un elemento e' presente
bool isPresent(const dhash_table& dht,Elem e){

  for (unsigned int i = 0; i < tableDim; ++i) {
 
   cell *cur = dht.T1[h1(e)];
    // Caso 1: lista T1
    while(cur != emptydllist) {
     if (cur -> elem == e) {
       return true;
     }
     cur = cur -> next;
   }
 
   // Caso 2: lista T2
   cell *cur2 = dht.T2[h1(e)];
   while(cur2 != emptydllist) {
     if (cur2 -> elem == e) {
       return true;
     }
     cur2 = cur2 -> next;
   }
  }
 
   return false;
 }

 unsigned int size(dllist &l) {
  unsigned int count = 0;
  dllist cur = l;
  while(cur != emptydllist){
    ++count;
    cur = cur -> next;
  }
  return count;
 }


void insert2(dllist &l, Elem e) {
  cell *aux = new cell;
  aux->next = emptydllist;
  aux->prev = emptydllist;
  aux->elem = e;

  // caso lista vuota o testa maggiore dell'elemento da inserire
  if (l == emptydllist || l -> elem > e) {
    if (l != emptydllist) { // entro in questa if nel caso di l -> elem > e
      l -> prev = aux;
    }
    aux -> next = l;
    l = aux;
  } 
  // tutti altri casi
  else {
    dllist cur = l; // uso un puntatore per scorrere la lista
    while (cur -> next != emptydllist && (cur -> next) -> elem < e) {
      cur = cur -> next;
    }
    aux->prev = cur;
    aux->next = cur -> next;
    // caso in cui dovessi avere (cur -> next) -> elem > e
    if (cur -> next != emptydllist) {
      (cur -> next) -> prev = aux;
    }
    cur -> next = aux;   // vale per entrambi i casi sopra
  }
}

//Es 3
//Inserisce un nuovo elemento
void insert(dhash_table& dht, Elem e) {

  // passo base: l'elemento esiste già
  if (isPresent(dht, e)) return;

  cell *aux = new cell;
  aux->next = emptydllist;
  aux->prev = emptydllist;
  aux->elem = e;

  dllist& cur_T1 = dht.T1[h1(e)];
  dllist& cur_T2 = dht.T2[h2(e)];

  // caso 1: t2 < t1
  if (size(cur_T2) < size(cur_T1)) {
    insert2(cur_T2, e);
  } else {
    insert2(cur_T1, e);
  }
}