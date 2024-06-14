#ifndef DOUBLE
#define DOUBLE
#include<string>
struct cell{ // elemento della lista
   std::string data;
   cell* next;
   cell* prev;
};
typedef cell* list;

void createEmpty(list &l);
// Creo lista "vuota"
void headInsert(list &l, std::string s);
// inserisce un elemento contenente s in testa alla lista l
void tailInsert(list &l, std::string s);
// inserisce un elemento contenente s in coda alla lista l
void print(const list &l);
// stampa tutti gli elementi della lista l
// in linea separati da "->"
unsigned int size(const list &l);
// ritorna il numero di elementi della lista l
bool isEmpty(const list &l);
// ritorna true se la lista l e vuota, false altrimenti
std::string getElem(const list &l, unsigned int i);
// ritorna il contenuto dell'i-esimo elemento della lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void insertAt(list &l, std::string s, unsigned int i);
// inserisce un elemento contenente s in posizione i nella lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteAt(list &l, unsigned int i);
// cancella l'elemento in posizione i dalla lista l
// - se la lista l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteOnce(list &l, std::string s);
// cancella dalla lista l il primo elemento contenente s
// (partendo dall'inizio)
void deleteALL(list &l, std::string s);
// cancella dalla lista l tutti gli elementi contenenti s
#endif