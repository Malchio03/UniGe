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

//Es 3
//Inserisce un nuovo elemento
void insert(dhash_table& dht,Elem e){

// caso base: elemento esiste già
//if (isPresent(dht, e)) return;

cell *aux = new cell;
aux -> next = emptydllist;
aux -> prev = emptydllist;
aux -> elem = e;

cell *cur_T2 = dht.T2[h2(e)];
cell *cur_T1 = dht.T1[h1(e)];

// caso 1: t2 < t1
if (size(cur_T2) < size(cur_T1)) {

  // lista vuota
  if (cur_T2 == emptydllist || cur_T2 -> elem > e) {
    if (cur_T2 != emptydllist) {
      cur_T2 -> prev = aux;
    }
    aux -> next = cur_T2;
    cur_T2 = aux;
  } else {
    // scorro per trovare il punto d'inserimento
    while(cur_T2 -> next != emptydllist && cur_T2 -> next -> elem < e) {
      cur_T2 = cur_T2 -> next;
    }
    aux -> prev = cur_T2;
    aux -> next = cur_T2 -> next;
    cur_T2 -> next -> prev = aux;
    cur_T2 -> next = aux;
  }
} else {
  // lista vuota
  if (cur_T1 == emptydllist || cur_T1 -> elem > e) {
    if (cur_T1 != emptydllist) {
      cur_T1 -> prev = aux;
    }
    aux -> next = cur_T1;
    cur_T1 = aux;
  } else {
    while(cur_T1 -> next != emptydllist && cur_T1 -> next -> elem < e) {
      cur_T1 = cur_T1 -> next;
    }
    aux -> prev = cur_T1;
    aux -> next = cur_T1 -> next;
    cur_T1 -> next -> prev = aux;
    cur_T1 -> next = aux;
  }
}
return;
}
