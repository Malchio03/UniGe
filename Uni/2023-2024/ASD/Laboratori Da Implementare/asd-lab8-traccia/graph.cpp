#include <iostream>

#include "graph.h"

using namespace graph;

struct graph::vertexNode {
  //TODO
}

/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/
// Restituisce il grafo vuoto
Graph graph::createEmptyGraph(){
  //TODO
}

// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false 
bool graph::addVertex(Label l, Graph& g){
  //TODO
}

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph& g){
  //TODO
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){
  return g == emptyGraph;
}

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph& g){
  //TODO
}

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph& g){
  //TODO
}

// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int& degree, const Graph& g) {
  //TODO
}

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
  //TODO
}

// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph& g) {
  //TODO
}

// Calcola, se esiste, un cammino tra due vertici
// Il primo argomento e il vertice di partenza
// Il secondo argomento e il vertice di arrivo
// Il terzo argomento conterrà la lista delle etichette degli
// vertici visitati sul cammino (senza il vertice di partenza, ne il vertice
// di arrivo)
// Si assume che il chiamante fornisca inizialmente una lista vuota.
// Il quarto argomento è il peso del cammino
// La funziona ritorna false, se il vertice di partenza e uguale al vertice
// di arrivo, o se non c'e un cammino tra i due vertici, altrimenti
// ritorna true
bool graph::findPath(Label v1, Label v2, list::List& path, Weight& weight, const Graph& g) {
  //TODO
}

// Svuota un grafo
void graph::clear(graph::Graph& g){
 //TODO
}

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph& g) {
  //TODO
}
