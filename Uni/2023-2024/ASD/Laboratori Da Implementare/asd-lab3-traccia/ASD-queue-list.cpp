// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-queue-list.h"

using namespace queue;
using namespace std;

//implementazione di una doubly linked list
struct queue::cell{
   Elem el;
   cell *next;
   cell *prev;
};

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

/* restituisce la coda vuota */
Queue queue::createEmpty(){
   // to do
   Queue qret;
   return qret;
} 

/* restituisce true se la queue e' vuota */
bool queue::isEmpty(const Queue& q){
   // to do
   return true;
}

/* inserisce l'elemento "da una parte" della coda */
void queue::enqueue(Elem e, Queue& q){
   // to do
}

/* cancella l'elemento (se esiste) "dall'altra parte */
/*della coda" e lo restituisce; se la coda è vuota solleva */
/*una eccezione di tipo string*/
Elem queue::dequeue(Queue& q){
   // to do
   Elem ret;
   return ret;
}

/* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo*/ 
/*se la coda è vuota solleva una eccezione di tipo string*/
Elem queue::first(Queue& q){
   // to do
   Elem ret;
   return ret;
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
/* riempie una coda da file */
Queue queue::readFromFile(std::string name_file){
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Queue qret=createEmpty();
   while (getline (infile,read_data)){
      if(read_data.length()>0){
         enqueue(stoi(read_data),qret);
      } 
   }
   return qret;
}

/* legge il contenuto di una coda da standard input */
Queue queue::readFromStdin(){
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Queue qret=createEmpty();
   string read_data;
   cin>>read_data;
   while(read_data!="END"){
      enqueue(stoi(read_data),qret);
      cin>>read_data;
   }
   return qret;
}

/* stampa la coda*/
void queue::print(const Queue& q){
   cout<<tostring(q)<<endl;
}

/* produce una string contenente la coda*/
std::string queue::tostring(const Queue& q){
   string out="";
   out+="{";
   list l=q.li;
   while(l!=EMPTYLIST){
      out+=to_string(l->el);
      if(l!=q.end){
         out+=",";
      }
      l=l->next;
   }
   out+="}";
   return out;
}

