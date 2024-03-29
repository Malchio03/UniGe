#include <iostream>
#include <string>
#include <sstream>
#include "plist.h"

using namespace std;

// Implementazioni funzioni per il tipo PList

void PList_print(PList &L)
{
  if(!L){
    cout<<".\n";
    return;
  }
  cout<<L->cont;
  if(L->next)cout<<" -> ";
  PList_print(L->next);
}


void PList_create(PList &L)
{
  L = nullptr;
}


int main()
{
  PList L;
  cout<<"#Creazione nuova lista\n";
  PList_create(L);
  PList_print(L);
  try {
    cout<<"#Test: aggiunta 1 a lista vuota\n";
    PList_insert(L,1);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: aggiunta 2 a lista non vuota\n";
    PList_insert(L,2);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: aggiunta 1 a lista che contiene gia' 1\n";
    PList_insert(L,1);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: aggiunta 3 a lista non vuota\n";
    PList_insert(L,3);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: rimozione di 3 da lista che contiene 3\n";
    PList_delete(L,3);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: rimozione di 3 da lista che non contiene 3\n";
    PList_delete(L,3);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: rimozione di 1 da lista che contiene 1\n";
    PList_delete(L,1);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: rimozione di 2 da lista che contiene solo 2\n";
    PList_delete(L,2);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  try {
    cout<<"#Test: rimozione di 2 da lista vuota\n";
    PList_delete(L,2);
    PList_print(L);
  }
  catch (...) {
      cout << "Exception\n";
      return -1;
  }
  return 0;
}
