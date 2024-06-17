#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  // TO DO
}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  // TO DO
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  // TO DO
}
