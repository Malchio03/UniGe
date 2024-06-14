#include "listASD-dll.h"

using namespace list;

struct list::node {
Elem info;
node *prev;
node *next;
};

/****************************************************************/


List copy(const List& l)
{
List newList = createEmpty();
List q = l->next;  // q "salta la sentinella" e va alla testa della lista l
   while (q != l)     // avanza finche' non finisce la lista, inserendo gli elementi di l in newList
      addBack(q->info, newList);
return newList;      
}

list::List readFromStream(istream& str)
{
    List l = createEmpty();
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        addBack(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
    return l;
}

list::List readFromFile(string nome_file)  /* legge il contenuto di una lista da file */
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}



list::List readFromStdin()         /* legge il contenuto di una lista da standard input */
{
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   return readFromStream((std::cin));
}


void print(const List& l)           /* stampa la lista */
{
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l)     // avanza finche' non finisce la lista
     {
      cout << q->info << "; ";
      q = q->next; 
      }
}




// Ricerca di un intero nella lista. Restituisce il puntatore al nodo che lo
// contiene, oppure alla sentinella se non e' presente il valore cercato
List searchElemPointer(Elem e, List l)
{
List q = l->next;            // q "salta la sentinella" e va alla testa della lista
while (q != l && q->info != e) // avanza finche' non finisce la lista o non trovi e
	q = q->next;
return q;
}


// Ricerca di un intero nella lista. Restituisce il puntatore al nodo che lo
// contiene, oppure alla sentinella se non e' presente il valore cercato
List searchPositionPointer(int pos, List l)
{
List q = l->next;  // q "salta la sentinella" e va alla testa della lista
int counter = 0;           
while (q != l && counter < pos) // avanza finche' non finisce la lista o non trova la posizione pos
     {
      q = q->next; 
      ++counter;    
      }
return q;
}


// Inserimento di un intero n prima del nodo puntato da p 
void insertBeforePointer(Elem e, List& p)
{
List q = new node;
q->info = e;
q->prev = p->prev;
q->next = p;
p->prev = q;
q->prev->next=q;
}


void list::clear(List& l)                 /* "smantella" la lista svuotandola */
{
List q = l->next;  // q "salta la sentinella" e va alla testa della lista
List aux;
while (q != l)    // avanza finche' non finisce la lista o non trova la posizione pos
     {aux = q;
      q = q->next; 
      delete aux; // dealloco ogni elemento della lista
      }
l->prev = l->next = l; // risitemo i puntatori next e prev di l in modo che puntino a l stessa

}


Elem list::get(int pos, const List& l)        /* restituisce l'elemento in posizione pos se presente; restituisce un elemento che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
{
   int size = list::size(l);
   if (0 > pos || pos >= size) return EMPTYELEM; // la posizione non corrisponde a un elemento presente nella lista, restituisco l'elemento vuoto
   if (pos == (size-1)) return (l->prev)->info; // la posizione e' quella dell'ultimo elemento; anziche' scandire la lista dal principio, lo restituisco in tempo costante
   List q = searchPositionPointer(pos, l); // mi posiziono sull'elemento che occupa la posizione pos
   return q->info;                         // e restituisco il contenuto informativo di quell'elemento
}


List list::setF(int pos, Elem e, const List& l)
{
   List newList = copy(l);
   set(pos, e, newList);
   return newList;
}


void list::set(int pos, Elem e, List& l)        /* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
{
   int size = list::size(l); 
   if (0 > pos || pos >= size) return; // la posizione non corrisponde a un elemento presente nella lista, restituisco l'elemento vuoto
   if (pos == (size-1)) (l->prev)->info=e; // la posizione e' quella dell'ultimo elemento; anziche' scandire la lista dal principio, aggiorno questo elemento
   List q = searchPositionPointer(pos, l);
   if (q!=l) q->info = e;
}


List list::addF(int pos, Elem e, const List& l)
{
   List newList = copy(l);
   add(pos, e, newList);
   return newList;
}

void list::add(int pos, Elem e, List& l)        /* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
{                                               
  int size = list::size(l);
  if (0 > pos || pos > size) return;           /* se pos > size e' fuori range */
  if (pos == size) 
   {
    insertBeforePointer(e, l);                   /* se pos == size aggiunge in coda */
    return;
   }
  List q = searchPositionPointer(pos, l);
  insertBeforePointer(e, q);
}


List list::addBackF(Elem e, const List& l)
{
   List newList = copy(l);
   addBack(e, newList);
   return newList;
}

void list::addBack(Elem e,  List& l)        /* inserisce l'elemento alla fine della lista */
{
     insertBeforePointer(e, l);
}


List list::addFrontF(Elem e, const List& l)
{
   List newList = copy(l);
   addFront(e, newList);
   return newList;
}

void list::addFront(Elem e, List& l)        /* inserisce l'elemento all'inizio della lista */
{
     insertBeforePointer(e, l->next);
}


List list::removePosF(int pos, const List& l)
{
   List newList = copy(l);
   removePos(pos, newList);
   return newList;
}

void list::removePos(int pos, List& l)           /* cancella l'elemento in posizione pos dalla lista */
{
List q;
int size = list::size(l);
if (0 > pos || pos >= size) return; // la posizione non corrisponde a un elemento presente nella lista, restituisco l'elemento vuoto
if (pos == (size-1)) 
   q = (l->prev); // la posizione e' quella dell'ultimo elemento; anziche' scandire la lista dal principio, aggiorno questo elemento
else
   q = searchPositionPointer(pos, l);
if (q != l)
    {
    q->next->prev=q->prev;
    q->prev->next=q->next;
    delete q;
    }
}


/* cancella la prima occorrenza dell'elemento elem, se presente, dalla lista */
/* 
void list::removeEl(Elem e, List& l)          
{
List q = searchElemPointer(e, l);
if (q != l)
    {
    q->next->prev=q->prev;
    q->prev->next=q->next;
    delete q;
    }
}
*/

bool list::isEmpty(const List& l)         /* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
{
   return (l->next == l);
}


int list::size(const List& l)           /* restituisce la dimensione della lista */
{
   int counter = 0;
   List q = l->next; // q "salta la sentinella" e va alla testa della lista
   while (q != l)    // avanza finche' non finisce la lista
	{
         q = q->next;
         ++counter;  // incrementa counter
        }
   return counter;
}



List list::createEmpty()
{
List l;
createEmpty(l);
return l;
}

void list::createEmpty(List& l)           /* crea la lista vuota */
{
   // Crea il nodo sentinella
   l = new node;
   // Concatenalo circolarmente a se stesso
   l->prev = l->next = l;
}


