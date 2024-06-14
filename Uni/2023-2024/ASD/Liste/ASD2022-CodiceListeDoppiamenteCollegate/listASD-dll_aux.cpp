#include "listASD-dll.h"

using namespace list;

struct list::node {
Elem info;
node *prev;
node *next;
};

/****************************************************************/


list::List readFromStream(istream& str)
{
    List l;
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        addFront(e, l);   // aggiunge l'elemento all'inizio della lista
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
   List q = l;  // q va alla testa della lista
   while (q != emptyList)     // avanza finche' non finisce la lista
     {
      cout << q->info << "; ";
      q = q->next; 
      }
}


void list::addBack(Elem e,  List& l)        /* inserisce l'elemento alla fine della lista */
{
     node* aux = new node;
     aux->info = e;
     aux->next = emptyList;
     if (l==emptyList)
     {        
        aux->prev = emptyList;
        l = aux;
     } 
     else
     {
     List q = l;  // q va alla testa della lista 
        while (q->next != emptyList)
           q = q->next;        
     aux->prev = q;
     q->next=aux;
     }
}


void list::addFront(Elem e, List& l)        /* inserisce l'elemento all'inizio della lista */
{
     node* aux = new node;
     aux->info = e;
     aux->next = l;
     aux->prev = emptyList;
     if (l!=emptyList) 
         l->prev=aux;
     l = aux;
}     
     

void list::removeElem(Elem e, List& l) /* cancella la prima occorrenza di e nella lista; per esercizio: creare una versione che cancella tutte le occorrenze di e dalla lista */
{
List q;

if (l == emptyList)  /* se la lista è vuota, non devo cancellare niente */
   return; 
   
if (l->info == e)    /* se l'elemento da rimuovere è il primo, oltre a cancellarlo, l'inizio della lista, puntato da l, cambia (devo aggiornare il puntatore l, che punterà al secondo elemento) */
{
   q = l->next;
   if (q != emptyList)
    	q->prev=emptyList;
   delete l;
   l = q;
   return; 			
}

q = l;              /* caso in cui la lista non è vuota e l'elemento da rimuovere non e' il primo */
bool removed = false;

while (q != emptyList && !removed)    // avanza finche' la lista non è stata scandita tutta o l'elemento non è stato rimosso
	{
	if (q->info == e)             // quando trovo l'elemento cercato
    		{
    		if (q->next != emptyList) // aggiorno i puntatori next e prev delle celle precedente e successiva, facendo attenzione a non accedere campi di un puntatore nullo
    			q->next->prev=q->prev;
    		
    		if (q->prev != emptyList)  // inutile, visto che l'unico elemento con prev empty è il primo e lo abbiamo trattato a parte      	
    		        q->prev->next=q->next;
    		
    		delete q;                // cancello l'elemento q
    		removed = true;          // interrompo la scansione ponendo removed a true
                }
        else
        	q = q->next;        
	}
}


bool list::isEmpty(const List& l)  /* restituisce true se la lista e' vuota */
{
   return (l==emptyList);
}


void list::createEmpty(List& l)   /* l diventa la lista vuota  */
{
   l = emptyList;
}

int list::size(const List& l)      /* restituisce la dimensione della lista */
{
   int counter = 0;
   List q = l; // q  va alla testa della lista
   while (q != emptyList)    // avanza finche' non finisce la lista
	{
         q = q->next;
         ++counter;  // incrementa counter
        }
   return counter;
}

