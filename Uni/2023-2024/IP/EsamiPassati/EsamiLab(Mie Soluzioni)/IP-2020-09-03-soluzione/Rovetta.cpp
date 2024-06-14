#include "names.h"
#include <fstream>
#include <iostream>


// legge (e restituisce) un Name interattivamente da tastiera,
// chiedendo all'utente prima il nome e poi il cognome
Name readNameFromKeyboard()
{
  Name n;

  // dovendo scrivere delle stringhe ci sono pochi controlli di correttezza
  // che si possano fare; si potrebbe forse chiedere che non venga inserita
  // più di una stringa alla volta, o che l'input sia una maiuscola seguita
  // da sole minuscole, ma queste caratteristiche non sono specificate dal testo
  std::cerr << "Nome?    ";
  std::cin >> n.name;
  std::cerr << "Cognome? ";
  std::cin >> n.surname;

  return n;
}

// converte un Name in una stringa stampabile, la restituisce
std::string toString(const Name n)
{
  return n.name + " " + n.surname;
}

// aggiunge un Name a una lista nomi
void append(std::vector<Name> &list, const Name n)
{
  list.push_back(n);
}

// stampa una intera lista nomi (std::vector di Name)
void printNameList(const std::vector<Name> &list)
{
  for (int i=0; i<list.size(); i++) std::cout << toString(list[i]) << "\n";
}

// ordina una lista nomi (std::vector di Name);
// orderBy contiene il nome del campo ("name" o "surname") secondo cui ordinare
void sortNameList(std::vector<Name> &list, const std::string orderBy)
{
  // se orderBy ha un valore non valido, non ordina
  if (orderBy!="name" && orderBy!="surname") return;

  // insertion sort semplice, con il ciclo più interno specializzato nei due casi
  for (int i=1;i<list.size();i++) {
    if (orderBy=="name") {
      int j=i;
      while(j>0 && list[j-1].name>list[j].name) {
        Name tmpn = list[j];
        list[j]=list[j-1];
        list[j-1]=tmpn;
        --j;
      }
    }
    else {
      int j=i;
      while(j>0 && list[j-1].surname>list[j].surname) {
        Name tmpn = list[j];
        list[j]=list[j-1];
        list[j-1]=tmpn;
        --j;
      }
    }
  }
}

// verifica se una lista nomi (std::vector di Name) e' ordinata;
// orderBy contiene il nome del campo ("name" o "surname") secondo cui verificare
// l'ordinamento
bool isSorted(const std::vector<Name> &list, const std::string orderBy)
{
  // se orderBy ha un valore non valido, restituisce comunque false
  if (orderBy!="name" && orderBy!="surname") return false;

  // se trova un elemento fuori posto restituisce false ; se una volta scorso tutto
  // il vector non ne ha trovati, allora restituisce  true
  for (int i=1; i<list.size(); i++) {
    if ( (orderBy=="name" && list[i].name<list[i-1].name)
      || (orderBy=="surname" && list[i].surname<list[i-1].surname)
        ) return false;
  }
  return true;
}

// a partire da una lista nomi crea una lista contenente i nomi o i cognomi
// senza ripetizioni. select contiene il nome del campo da usare ("name" o "surname").
// Se list non è ordinata secondo il campo selezionato, restituisce vector vuoto.
std::vector<std::string>  unique(const std::vector<Name> &list, const std::string select)
{
  std::vector<std::string> u = {};

  // se select ha un valore non valido, restituisce lista vuota
  if (list.size()==0 || !isSorted(list,select)) return u;

  // esempio di uso dell'operatore condizionale A?B:C (ternario, tre argomenti)
  u.push_back( select=="name"? list[0].name : list[0].surname );

  for (int i=1; i<list.size(); i++) {
    if (select == "name" && list[i].name!=u[u.size()-1]) u.push_back(list[i].name);
    if (select == "surname" && list[i].surname!=u[u.size()-1]) u.push_back(list[i].surname);
  }
  // --- ATTENZIONE che qui non si può usare else: se non e' vero il primo if,
  // non e' detto che sia automaticamente vero il secondo (logica).
  // --- u.size()-1 e' l'indice dell'ultimo elemento del vector
  // e u[u.size()-1] e' l'ultimo elemento.
  // Si puo' anche usare direttamente la funzione membro u.back(), ma non l'abbiamo
  // mai usata durante il lab
  return u;
}
