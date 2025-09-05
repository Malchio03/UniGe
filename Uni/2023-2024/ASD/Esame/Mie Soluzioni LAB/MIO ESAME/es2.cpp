#include <iostream>
#include "priority-circ.h"

using namespace std;

//Es 2
//Inserisce una string con priorita' nella coda
//Se la string da inserire e' uguale a "" non fa nulla
void insertElem(list& li,string st,int pr){

  if (st == "") return; 

  // caso banale: lista vuota
  if (li == emptyList) {
    // devo creare la coda con priorita
    list aux = new cell;   // alloco la lista nuova
    aux -> next = emptyList; // sono solo, non ho successori
    aux -> priority = pr;
    li = aux;

    // qui creo la sentinella 
    dll sentinella = new dllCell;
    li -> queue = sentinella;

    // qui creo elemento lista circolare
    dll elemento_listaCirc = new dllCell;
    elemento_listaCirc -> val = st;
    elemento_listaCirc -> next2 = sentinella;
    elemento_listaCirc -> prev2 = sentinella;
    sentinella -> next2 = elemento_listaCirc;
    sentinella -> prev2 = elemento_listaCirc;
    return; //esco
  }

  // tutti gli altri casi
  
  // caso in cui NON sono nullptr ma non ho neanche successori
  if (li != emptyList && li -> next == emptyList){

    // prendo ultimo elemento della lista
    dll lastElem = (li -> queue)->prev2;

    // creo elem nuovo
    dll aux = new dllCell;

    aux -> val = st;
    aux -> next2 = li -> queue;
    lastElem -> next2 = aux;
    aux -> prev2 = lastElem;
    li -> queue -> prev2 = aux;
    return;
  }
  
  // caso in cui elemento la priorita sia minore

  


  return;
}

