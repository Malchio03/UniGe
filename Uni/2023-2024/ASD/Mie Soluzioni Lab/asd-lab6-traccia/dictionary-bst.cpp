#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  Elem info;
  bstNode* leftChild;
  bstNode* rightChild;
};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  //TODO
  return d == emptyDictionary;
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  Dictionary d = emptyDictionary;
  return d;
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  // Se il nodo corrente è vuoto, alloco nuovo nodo e gli assegno i valori k e v passati
  // come argomento; il figlio destro e sinistro sono vuoti;
  if (isEmpty(d)) {
    bstNode *newNode = new bstNode;
    (newNode -> info).key = k;
    (newNode -> info).value = v;
    newNode -> leftChild = emptyNode;
    newNode -> rightChild = emptyNode;
    d = newNode;
    return OK;
  }
  //altrimenti procedo discendendo nell'albero mediante chiamate ricorsive
  // e nel momento in cui troviamo un nodo vuoto durante la ricerca, lo sostituiamo con il puntatore al nodo appena creato.
  // A questo punto il nuovo nodo sara nel posto giusto,
  // ovvero nel punto in cui la funzione search lo trovera.

  // Se il nodo corrente non e' vuoto, cerchiamo la chiave k con un algoritmo ricorsivo analogo a quello della search; nel caso in cui la chiave ci sia, non dobbiamo re-inserirla e restituiamo FAIL;
  if ((d->info).key == k) return FAIL; // ho trovato un nodo la cui chiave e' k: non devo inserire la nuova coppia perche' la chiave e' gia' presente

  if((d->info).key > k) {
    // Se l'elemento da inserire ha chiave < della chiave del nodo corrente, lo inserisco (se possibile) a sinistra con una chiamata ricorsiva a insertElem
    return insertElem(k, v, d -> leftChild);
  } else {
    // se l'elemento da inserire ha chiave >= della chiave del nodo corrente, lo inserisco (se possibile) a destra con una chiamata ricorsiva a insertElem 
    return insertElem(k, v, d -> rightChild);
  }
}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){

  // albero vuoto: impossibile trovare l'elemento
  if (isEmpty(d)) {
    return emptyValue;
  }

  // se trovo l'elemento restituisco il valore
  if ((d -> info).key == k) {
    return (d -> info).value;
  }

  if ((d -> info).key > k) {
    // l'elemento cercato ha chiave < della chiave cercata, scendo a sx con una chiamata ricorsiva su d->leftChild
    return search(k, d -> leftChild);
  } else {
    // l'elemento cercato ha chiave >= della chiave cercata, scendo a dx con una chiamata ricorsiva su d->rightChild
    return search(k, d->rightChild);
  }
}


/****************************************************************/
// Funzione ausiliaria della deleteElem: rimuove l'elemento con chiave minore in un albero non vuoto e restituisce il dictionary Elem (ovvero la coppia (key, value) ) corrispondente all'elemento rimosso. 
Elem deleteMin(Dictionary& d) {
  if (d -> leftChild == emptyNode) {    // se il figlio sinistro di d e' vuoto vuole dire che d contiene l'elemento del dizionario con chiave minima: lo devo cancellare e restituire
    Elem tmpElem = d -> info;           // la variabile tmpElem contiene la coppia (key, value) del nodo corrente
    Dictionary tmpNode = d -> rightChild;   // La variabile tmpNode contiene il puntatore al figlio destro del nodo corrente
    delete d;    // dealloco il nodo corrente d
    d = tmpNode;  // rimpiazzio d con il suo figlio destro
    return tmpElem; // restituisco la variabile tmpElem in cui avevo memorizzato (key, value) dell'elemento con chiave minima
  } else {
    // se il figlio sinistro di d NON e' vuoto, bisogna discendere a sinistra nell'albero per cercare e cancellare l'elemento che ha chiave minima; lo facciamo con una chiamata ricorsiva a deleteMin passando come argomento il puntatore al figlio sinistro di d
    return deleteMin(d->leftChild);
  }
}

//Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary& d){
  // se d e' vuoto non c'e' niente da cancellare e restituisco FAIL
  if (isEmpty(d)) {
    return FAIL;
  }

  // se (d->elem).key == k ho trovato l'elemento da cancellare
  if ((d -> info).key == k) {
    // CASO 1: entrambi i figli di d sono vuoti. Devo solo deallocare e porre d = emptyNode
    if ((d -> rightChild == emptyNode) && (d->leftChild == emptyNode)) {
      delete d;
      d = emptyNode;
    } 

    // CASO 2: il figlio sinistro di d e' vuoto, ma il figlio destro non lo e': rimpiazzo d con il figlio destro
    else if (d -> leftChild == emptyNode) {
      Dictionary tmpNode = d -> rightChild;   // la variabile tmpNode contiene il puntatore al figlio destro del nodo corrente
      delete d;  // dealloco il nodo corrente d
      d = tmpNode;  // rimpiazzo d con il suo figlio destro
    }

    // CASO 3: il figlio destro di d e' vuoto, ma il figlio sinistro non lo e': rimpiazzo d con il figlio sinistro
    else if (d -> rightChild == emptyNode) {
      Dictionary tmpNode = d -> leftChild;  // la variabile tmpNode contiene il puntatore al figlio sinistro del nodo corrente
      delete d; // dealloco il nodo corrente d
      d = tmpNode; // rimpiazzo d con il suo figlio sinistro
    }

    // CASO 4: nessuno dei figli di d e' vuoto: cancello (usando la funzione ausiliaria deleteMin) il nodo con chiave minima nell'albero corrispondente al figlio destro di d e assegno al campo "elem" di d il valore del nodo cancellato
    else {
      d -> info = deleteMin(d -> rightChild);
    }

    return OK;
  }

  if ((d->info).key > k)
      // l'elemento da cancellare ha chiave < della chiave cercata, scendo a sx con una chiamata ricorsiva su d->leftChild perche', se l'elemento e' presente, lo trovero' nel ramo sinistro dell'albero e lo dovro' cancellare da li'
      return deleteElem(k, d->leftChild);
  else
      // l'elemento da cancellare ha chiave >= della chiave cercata, scendo a dx con una chiamata ricorsiva su d->rightChild perche', se l'elemento e' presente, lo trovero' nel ramo destro dell'albero e lo dovro' cancellare da li'
      return deleteElem(k, d->rightChild); 
}

//Funzione da implementare
void print(const Dictionary& d) {
  // Albero vuoto, non fare nulla
  if (isEmpty(d)) {
    return;
  }

  if (d -> leftChild != emptyNode) {
    print(d -> leftChild);
  }
  
  cout << (d -> info).key << ": " << (d->info).value << "\n";
  
  if (d -> rightChild != emptyNode) {
    print (d -> rightChild);
  }

}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
