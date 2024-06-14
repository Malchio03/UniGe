#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "db.h"
using namespace std;

// ------ PRIMA PARTE: funzioni per il tipo Index

// Invece di mettere il codice di manipolazione della lista sparso in vari
// punti all'interno del mio programma, definisco in un'unica posizione le
// funzioni per qualunque operazione mi serva fare su Index. In questo modo
// non mi interessa ricordare come e' fatto un index, e volendo potrei
// cambiarlo senza toccare il resto del programma.

// NOTA: Tutta questa prima parte potrebbe essere un file separato index.cpp,
// con il suo index.h, o addirittura già compilate in una libreria. Non e'
// pero' richiesto in questo testo d'esame ne' di fare un sorgente separato,
// ne' di compilarlo come libreria. Era invece richiesto di inserire le
// definizioni (tipo, prototipi di funzioni) nel file dbdef


// NOTA: Per mia scelta, ogni funzione che opera su Index ha un nome che inizia
// con il prefisso Index_ Vengono istruzioni un po' piu' lunghe, ma esplicite

// NOTA: In caso di errore (tipicamente se voglio leggere una lista vuota)
// sollevo eccezione, per semplicita' di tipo stringa

// NOTA: un puntatore vuoto vale 0, quindi usato al posto di un bool
// equivale a false; qualunque cosa che non sia 0 vale true


// restituisce il successore
Index Index_nextof(Index C)
{
  if(C) return C->next;
  else throw "null pointer";
}

// alloca un nuovo Index vuoto
Index Index_new()
{
  Index nc = new cell;
  nc->next = Index_empty;
  nc->info = nullptr;
  return nc;
}

// Assegna un valore al campo info
Index Index_setinfo(Index C, Record * rp)
{
  if(C) C->info = rp;
  return C;
}

// Legge il valore di info
Record* Index_getinfo(Index C)
{
  if(C) return C->info;
  else throw "null pointer";
}

// "Appende", ovvero inserisce in coda, un elemento
Index Index_append(Index C, Index np)
{
  if(C) C->next = np;
  else throw "out of range";
  return C;
}




// ------ SECONDA PARTE: funzioni per confrontare Record

// Non era richiesto di fare funzioni sul tipo Record come lo era
// per il tipo Index. Pero' queste due funzioni sono richieste.
// Valgono le stesse considerazioni fatte nella prima parte riguardo
// alle funzioni su Index.

// NOTA: secondo la buona pratica le dichiarazioni andrebbero nel file db.h, 
// quindi in dbdef (la parte che potete modificare); oppure in un file
// apposito Record.h. Pero' siccome non e' esplicitamente richiesto dal testo 
// non l'ho fatto.


// Confronto tra due record
int Record_compare(Record r1, Record r2, int c)
{
  if (c<0 || c>3) throw "Field index is out of range";
  // confronto nei quattro casi.
  // restituisco -1 se il primo e' maggiore, 1 se il secondo
  // e' maggiore, 0 altrimenti (ovvero se sono uguali)
  switch(c) {
    // NOTA: break inutile dopo ogni case, c'e' gia' un return
    case 0:
      if (r1.nome>r2.nome) return -1;
      else if (r1.nome<r2.nome) return 1;
      else return 0;
    case 1:
      if (r1.cognome>r2.cognome) return -1;
      else if (r1.cognome<r2.cognome) return 1;
      else return 0;
    case 2:
      if (r1.matricola>r2.matricola) return -1;
      else if (r1.matricola<r2.matricola) return 1;
      else return 0;
    case 3:
      if (r1.media>r2.media) return -1;
      else if (r1.media<r2.media) return 1;
      else return 0;
    // NOTA: default inutile, i casi diversi sono già stati esclusi
   //       facendo il  controllo iniziale
  }
}

int Record_comparestring(string s, Record r2, int c)
{
  // Siccome ho gia' una funzione per confrontare i record,
  // per confrontare con un singolo valore stringa creo un record
  // fittizio, gli assegno il valore del campo che mi interessa,
  // e poi confronto il record dato e il record fittizio
  if (c<0 || c>1) throw "Field index is out of range";
  Record r1;
  if (c==0) r1.nome = s;
  else r1.cognome=s;
  return Record_compare(r1, r2, c);
}




// ------ TERZA PARTE: funzioni richieste dal testo

// legge un Db da file - Il file deve chiamarsi "test.txt"
Db leggidb()
{
  ifstream f;

  f.open("test.txt");
  if (!f.is_open()) throw "Error opening file\n";

  // leggirecord restituisce il valore di successo (true) o di
  // fallimento (false) della lettura
  Record r;
  Db d;
  while(leggirecord(f, r)) d.push_back(r);
  f.close();
  return d;
}


// scrive un Db su schermo
void scrividb(Db & d)
{
  if (d.size()==0) return;
  for(int i=0; i<d.size(); i++) scrivirecord(d[i]);
}

// restituisce un Index ordinato secondo il campo c-esimo
// L'obiettivo e' ordinare l'Index anziche' il database
// Ordinare una copia del database non risolve il problema
Index indsort(Db & d, int c)
{
  if (d.size()==0) return Index_empty;

  Index ndx = Index_empty;
  // inserimento ordinato
  for(int i=0; i<d.size(); i++) {
    Index tmp = Index_new(); // creo l'elemento da aggiungere
    tmp = Index_setinfo(tmp,&d[i]); // gli assegno il valore

    if (ndx == Index_empty) {
    // caso 1, indice ancora vuoto
      ndx = tmp;
    }
    else
    if (Record_compare(d[i],*Index_getinfo(ndx),c)>0){
    // caso 2, devo inserire in testa
      tmp = Index_append(tmp,ndx);
      ndx = tmp;
    }
    else {
    // caso 3, cerco posizione giusta e inserisco
      // tengo due puntatori consecutivi
      Index cur = ndx;
      Index curnext = Index_nextof(cur);
      // il nuovo elemento verra' inserito fra i due
      // (appendo tmp a cur, e poi appendo curnext a tmp).
      // All'ultimo elemento, quando la posizione giusta e' in coda,
      // il secondo puntatore curnext sara' nullo: non ci preoccupa,
      // assegnare nullptr non da' errore

      while (
          // ...finche' non trovo la fine della lista...
          curnext != Index_empty
          // ...e la posizione non e' ancora quella giusta...
          && Record_compare(d[i],*Index_getinfo(curnext),c)<0) {
        // ...scorro in avanti:
        cur = curnext;
        curnext = Index_nextof(cur);
      }
      // appendo il cursore prossimo (resto della lista) in coda a tmp
      tmp = Index_append(tmp,curnext);
      // appendo tmp in coda al cursore corrente
      cur = Index_append(cur,tmp); 
    }
  }
  return ndx;
}

// scrive su schermo il contenuto di un Index
// se l'Index non e' vuoto, scrivo il contenuto del primo elemento
// e poi scrivo il resto della lista
// (altrimenti non faccio niente, no else, no return perche' la funzione
// ha tipo restituito void)
void scriviindex(Index ndx)
{
  if(ndx) {
    scrivirecord(*Index_getinfo(ndx));
    scriviindex(Index_nextof(ndx));
  }
}

// seleziona record che soddisfano un criterio
Index selectwhere(Db & d, int c, string q, bool v)
{
  Index ndx = Index_empty; // l'indice da restituire
  Index cur; // cursore - lo inizializzo al primo inserimento, vedi sotto

  if (c>1) throw "out of range";
  for(int i=0; i<d.size(); i++) {
    // per leggibilita', uso una variabile ausiliaria invece di scrivere
    // un solo  if con una condizione molto complessa:

    bool da_tenere; // true quando il record corrente e' da tenere

    // v indica il verso del confronto (>= oppure <)
    if (v) da_tenere = Record_comparestring(q,d[i],c)>=0;
    else da_tenere = Record_comparestring(q,d[i],c)<0;

    if (da_tenere) {
      Index tmp = Index_setinfo(Index_new(), &d[i]);
      // due casi: primo inserimento (indice ancora vuoto)...
      if (ndx == Index_empty) {
        ndx = tmp;
        cur = ndx;
      }
      // ...e caso generale
      else {
        cur = Index_append(cur, tmp);
        cur = Index_nextof(cur);
      }
    }
  }
  return ndx;
}
