/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"


// Funzioni ausiliarie che non appartengono al TDD 

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2)
{
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1; 
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;
      
  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1; 
    else return index2;
}

// funzione ausiliaria per scambiare due elementi
void swap(priorityQueue::PriorityQueue &pq, int pos1, int pos2){
	priorityQueue::Elem aux = pq.data[pos1];
	pq.data[pos1] = pq.data[pos2];
	pq.data[pos2] = aux;
}

void moveDown(priorityQueue::PriorityQueue& pq, int index) {
    int leftChild = 2 * index + 1; // Calcola l'indice del figlio sinistro
    int rightChild = 2 * index + 2; // Calcola l'indice del figlio destro
    int smallest = index; // Inizialmente, assume che l'elemento corrente sia il più piccolo

    // Se il figlio sinistro esiste ed è più piccolo dell'elemento corrente, aggiorna l'indice del più piccolo
    if (leftChild < pq.size && pq.data[leftChild].timeStamp < pq.data[smallest].timeStamp) {
        smallest = leftChild;
    }

    // Se il figlio destro esiste ed è più piccolo dell'elemento corrente, aggiorna l'indice del più piccolo
    if (rightChild < pq.size && pq.data[rightChild].timeStamp < pq.data[smallest].timeStamp) {
        smallest = rightChild;
    }

    // Se l'elemento corrente non è il più piccolo, scambialo con l'elemento più piccolo e ricorsivamente applica moveDown
    if (smallest != index) {
        swap(pq, index, smallest);
        moveDown(pq, smallest);
    }
}

// funzione ausiliare: sposta un elemento verso l'alto nell'heap per mantenere le proprietà dell'heap.
void moveUp(priorityQueue::PriorityQueue &pq, int index) {
  while(index > 0) {
    int parentIndex = (index - 1) / 2; // viene utilizzato per trovare l'indice del genitore di un nodo in un heap binario rappresentato come array.
    if (pq.data[index].timeStamp >= pq.data[parentIndex].timeStamp) {   // Questa riga controlla se l'elemento corrente è maggiore o uguale al genitore. Se sì, il ciclo si interrompe poiché l'elemento è nella posizione corretta.s
      break;
    }
    swap(pq, index, parentIndex);
    index = parentIndex;
  }
}


// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim) {
  PriorityQueue pq;
  pq.data = new Elem[dim];
  pq.size = 0;
  pq.maxsize = dim;
  return pq;
}

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq)
{
  return pq.size == 0;
} 

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem) {

  // caso dimensione piena
  if (pq.size == pq.maxsize) {
    return false;
  }

  // anche il caso in cui la coda sia vuota è preso in considerazione
  pq.data[pq.size] = elem;
  moveUp(pq, pq.size);        // Ripristina le proprietà dell'heap spostando l'elemento verso l'alto
  ++pq.size;
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res) {
  if (isEmpty(pq)) {
    return false;
  }
  res = pq.data[0];
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq) {  
  if (isEmpty(pq)) {
    return false;
  }
  pq.data[0] = pq.data[pq.size - 1];
  pq.size--;
  moveDown(pq, 0);
  return true;
}