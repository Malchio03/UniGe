#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  // caso tragitto vuoto
  if (isEmpty(tr)) {
    TragittoElem *aux = new TragittoElem;
    aux -> tappa = t;
    aux -> next = nullptr;
    tr = aux;
    return;
  }

   TragittoElem *aux = new TragittoElem;
   aux -> tappa = t;

    TragittoElem *cur = tr;

    while ( cur -> next != nullptr) {
      cur = cur -> next;
    }

    cur -> next = aux;

}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  if (isEmpty(tr)) {
    return false;
  }
  TragittoElem *temp = tr;
  t = temp -> tappa;
  tr = tr -> next;
  delete temp;

  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
    tragitto::TragittoElem* temp = tr;
    while (temp != nullptr) {
        std::cout << "[" << temp->tappa.distanza << " " << temp->tappa.citta << "] ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
