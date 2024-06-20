// FILE DA MODIFICARE
#include <iostream>
#include "ASD-stack.h"

using namespace stack;
using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack stack::createEmpty(){
	Stack sret;
	sret.size = 0;
	sret.maxsize = BLOCKDIM;
	sret.data = new Elem[BLOCKDIM];
	return sret;
}

/* restituisce true se lo stack e' vuoto */
bool stack::isEmpty(const Stack& st){
    return st.size == 0;
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
/* NB: se stack implementato con array dinamico, 
   quando necessario implementare ridimensionamento in espansione*/
void stack::push(const Elem el, Stack& st){
   // to do
if (st.size >= st.maxsize) {
		Elem* aux = new Elem[st.maxsize + BLOCKDIM];
		for (unsigned int i = 0; i < st.size; i++) {
			aux[i] = st.data[i];
		}
		
		delete[] st.data;
		st.data = aux;
		st.maxsize += BLOCKDIM;
	}
	st.data[st.size] = el;
	st.size++;
   	
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
/* NB: se stack implementato con array dinamico, 
   quando necessario implementare ridimensionamento in contrazione*/
Elem stack::pop(Stack& st){
   if(st.size == 0) {
      string error = "Lista vuota";
      throw error;
   }
   
   Elem ret = st.data[st.size-1];
   st.size--;

   // Ridimensionamento dell'array se necessario
   if(st.size < st.maxsize - BLOCKDIM) {
      st.maxsize -= BLOCKDIM;
      Elem* new_data = new Elem[st.maxsize];
      for(unsigned int i = 0; i < st.size; i++) {
         new_data[i] = st.data[i];
      }
      delete[] st.data;
      st.data = new_data;
   }

   return ret;
}
