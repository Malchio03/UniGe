#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione. 
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo, 
a livello concettuale, su un puntatore a un nodo dell'albero. 
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */ 



/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
    Label label;    
    treeNode *firstChild;
    treeNode *nextSibling;
};



/*******************************************************************************************************/
// funzione ausiliaria: data un'etichetta l crea il nodo con quella etichetta e ne restituisce il puntatore 
Tree createNode(const Label l)
{ 
    Tree t = new treeNode;
    t->label = l;
    t->firstChild = t->nextSibling = emptyTree;
    return t;
}



/*******************************************************************************************************/
// funzione ausiliaria: data un'etichetta l e un albero t (ovvero, un albero la cui radice
// è il nodo puntato da t), restituisce il puntatore al nodo dell'albero t che ha quell'etichetta (emptyTree 
// se nessun nodo ha quell'etichetta)
Tree getNode(const Label l, const Tree& t)
{ 
// se l'albero e' vuoto o l'etichetta e' vuota, restituisco il nodo vuoto
    if (isEmpty(t) || l==emptyLabel)
        return emptyTree;

// se l'etichetta dell'albero è quella cercata, restituisco t
    if (t->label == l) 
        return t;

// Chiamata ricorsiva di getNode su ciascuno dei figli di t, finché una delle chiamate non restituisce un valore diverso da emptyTree
    Tree auxT = t->firstChild;
    Tree resNode;
    while (auxT != emptyTree) {
        resNode = getNode(l, auxT);
        if (resNode == emptyTree) // non ho trovato cercando in questo sottoalbero, devo proseguire la scansione dei fratelli 
           auxT = auxT->nextSibling;
        else                      // ho trovato: lo restituisco
           return resNode;
    }   
return emptyTree; // se arrivo fino a qui, vuole dire che al termine di una ricerca esaustiva nell'albero il nodo non è stato trovato 
}



/*******************************************************************************************************/
// funzione ausiliaria: dato un puntatore a un nodo restituisce il puntatore al suo ultimo figlio ovvero 
// a quello più a destra nella catena dei fratelli - se esiste
// Serve nella deleteElem 
Tree lastChild(const Tree& t)
{ 
    // se l'albero e' vuoto oppure non ha figli restituisce il nodo vuoto
    if (isEmpty(t) || isEmpty(t->firstChild))
        return emptyTree;

    Tree prevChild = t->firstChild;             // il firstChild non e' vuoto; pongo prevChild uguale al firstChild
    Tree currentChild = prevChild->nextSibling; // pongo currentChild uguale al figlio successivo
    while (!isEmpty(currentChild)) 
    {
        prevChild = currentChild;  // avanzo finché currentChild diventa vuoto
        currentChild = currentChild->nextSibling;    
    }   
return prevChild; // restituisco l'ultimo nodo non vuoto
}



/*******************************************************************************************************/
// funzione ausiliaria: dato un albero t e un'etichetta l, restituisce il puntatore al fratello precedente 
// (ovvero più a sinistra) a quello con l'etichetta data, se esiste nell'albero
// Serve nella deleteElem 
Tree prevSibling(const Label l, const Tree& t)
{ 
    // se l'albero e' vuoto oppure non ha figli restituisce il nodo vuoto
    if (isEmpty(t) || isEmpty(t->firstChild) || l==emptyLabel)
        return emptyTree;

    if ((t->firstChild)->label == l) // se il nodo ha come primo figlio quello con l'etichetta cercata, non ha fratelli precedenti
         return emptyTree;
    else
       {
       Tree prevChild = t->firstChild;             // il firstChild non e' vuoto; pongo prevChild uguale al firstChild
       Tree currentChild = prevChild->nextSibling; // pongo currentChild uguale al figlio successivo
       Tree auxT;
       while (!isEmpty(currentChild) && currentChild->label != l) 
          {
          prevChild = currentChild;  // avanzo finché currentChild diventa vuoto
          currentChild = currentChild->nextSibling;    
          }   
       if (!isEmpty(currentChild) && currentChild->label == l) 
          return prevChild; // se sono uscito dal while perché ho trovato l'etichetta, restituisco il prev
       else 
          {
          currentChild = t->firstChild;
          while (!isEmpty(currentChild)) 
             {  
             auxT = prevSibling(l, currentChild);
             if (!isEmpty(auxT)) 
                return auxT;
             else 
                currentChild = currentChild->nextSibling;    
             }  
          }
       }
return emptyTree;
}



/*******************************************************************************************************/
// funzione ausiliaria di father: restituisce true se il nodo puntato da t ha un figlio con l'etichetta l
bool hasChildWithLabel(const Label l, const Tree& t)
{
if (isEmpty(t)) return false;

Tree child = t->firstChild;
while (!isEmpty(child))
   {
    if (child->label == l) 
       return true;
    else 
       child = child->nextSibling;
    }
return false;
}



/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree& t)
{ 
   return (t==emptyTree);
}



/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL 
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato 
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo 
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree& t)
{
   if ((labelOfNodeInTree == emptyLabel) && isEmpty(t)) // labelOfNodeInTree è l'etichetta vuota e l'albero è vuoto
      {
      t = createNode(labelOfNodeToAdd);  // creo il nodo; t che era vuoto diventa l'albero con il solo nodo appena creato
      return OK;                         // restituisco OK
      }

   if (member(labelOfNodeToAdd, t)) 
       return FAIL; // nell'albero esiste già un nodo con etichetta labelOfNodeToAdd, restituisco FAIL

   Tree auxT = getNode(labelOfNodeInTree, t); // recupero il puntatore al nodo dell'albero che ha etichetta labelOfNodeInTree

   if (auxT == emptyTree)
     return FAIL; // nell'albero non esiste un nodo con etichetta labelOfNodeInTree, restituisco FAIL
   else // ho trovato il nodo auxT a cui aggiungere il figlio
     {
     Tree child = createNode(labelOfNodeToAdd); // creo un nodo child con l'etichetta labelOfNodeToAdd
     child->nextSibling = auxT->firstChild;     // il primo fratello di child sarà quello che era il primo figlio di auxT
     auxT->firstChild = child;                  // child diventa il primo figlio di auxT
     }
   return OK;
}     



/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree& t)
{
     if (!member(l,t))
         return FAIL; // nell'albero non esiste un nodo con etichetta l, restituisco FAIL
 
     Tree fatherTree = getNode(father(l,t), t); // cerco il puntatore al padre del nodo da rimuovere
     if (isEmpty(fatherTree))  // se fatherTree e' vuoto, vuole dire che sto tentando di cancellare la radice 
           {
           if (degree(l, t)==0) // posso rimuovere la radice solo se non ha figli, nel qual caso
              {
               delete t;        // dealloco
               t = emptyTree;   // e t diventa l'albero vuoto
              }
            else 
               return FAIL;   // altrimenti non posso rimuoverla e restituisco FAIL
           } 
     else // sto tentando di rimuovere un nodo interno, del quale ho trovato il padre fatherTree
           {
           Tree nodeToRemove = getNode(l, t);      // recupero il puntatore al nodo da rimuovere
           Tree lastCh = lastChild(fatherTree); // recupero il puntatore al nodo dell'ultimo fratello del nodo da rimuovere (potrebbe essere il nodo stesso, se è l'ultimo) 
           lastCh->nextSibling = nodeToRemove->firstChild; // i figli del nodo da rimuovere diventano suoi fratelli 
           Tree prevSibl = prevSibling(l, t);              // recupero il puntatore al fratello precedente rispetto al nodo da rimuovere
if (isEmpty(prevSibl))  // se non c'é nessun fratello precedente, il nodo da rimuovere e' il primo: devo cambiare il puntatore al firstChild nel padre 
                fatherTree->firstChild = (fatherTree->firstChild)->nextSibling;
           else  // altrimenti, devo "saltare" il nodo da rimuovere nella catena dei fratelli
                prevSibl->nextSibling = nodeToRemove->nextSibling;
           delete nodeToRemove; // in ogni caso, alla fine dealloco il nodo da rimuovere
           }
     
     return OK;     
}



/*******************************************************************************************************/
// deleteChild: funzione ausiliaria, viene chiamata solo se si e' verificato che il nodo etichettato con l e' uno dei figli di t
void deleteChild(const Label l, Tree& t)
{
   Tree auxT = t->firstChild;    // so che il firstChild c'é perché chiamo deleteChild solo se ho già verificato qs condizione
   Tree prev = createEmpty();    // il prev all'inizio e' vuoto
   while(auxT->label != l)
      {
      prev = auxT;
      auxT = auxT->nextSibling;
      }
   // quando esco da questo while, auxT punta al nodo da cancellare
   Tree lastSibling = auxT;

   while(!isEmpty(lastSibling->nextSibling))
      lastSibling = lastSibling->nextSibling;
   // quando esco da questo while, lastSibling punta al fratello più a destra del nodo da cancellare
  
   lastSibling->nextSibling = auxT->firstChild; // attacco i figli del nodo da cancellare al suo ultimo fratello

   if (isEmpty(prev))  // se non c'é nessun fratello precedente, il nodo da rimuovere e' il primo: devo cambiare il puntatore al firstChild nel padre 
      t->firstChild = (t->firstChild)->nextSibling;
   else  // altrimenti, devo "saltare" il nodo da rimuovere nella catena dei fratelli
      prev->nextSibling = auxT->nextSibling;
    
   delete auxT; // in ogni caso, alla fine dealloco il nodo da rimuovere        
}



/*******************************************************************************************************/
// deleteElemAux (versione ricorsiva), funzione ausiliaria, rimuove dall'albero il nodo etichettato con la Label l, se esiste
Error deleteElemAux(const Label l, Tree& t)
{
   if (isEmpty(t)) return FAIL;  // se t e' vuoto non c'e' niente da cancellare

   if (hasChildWithLabel(l, t))  // se t è il padre del nodo da rimuovere    
      {
      deleteChild(l, t);         // rimuovo il figlio di t etichiettato con l
      return OK;                 // e restituisco OK
      }
   
   Tree child = t->firstChild;   // altrimenti richiamo ricorsivamente sui figli di t finche' o cancello, o non ci sono piu' figli da esplorare
   while (!isEmpty(child))
      {
      if (deleteElemAux(l, child) == OK)
          return OK;
      else 
          child = child->nextSibling;
      }
  return FAIL;
}



/*******************************************************************************************************/
// deleteElem (versione ricorsiva) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemR(const Label l, Tree& t)
{
     if (!isEmpty(t) && t->label == l) // il nodo da rimuovere e' la radice; si puo' rimuovere solo se non ha figli
        {
         if (degree(l, t)==0) // posso rimuovere la radice solo se non ha figli, nel qual caso
           {
            delete t;        // dealloco
            t = emptyTree;   // e t diventa l'albero vuoto
           }
           else 
             return FAIL;   // altrimenti non posso rimuoverla e restituisco FAIL
         }
      
     return deleteElemAux(l, t);  // se sono arrivato fino a qui senza uscire dalla funzione, chiamo la funzione ausiliaria, che non fa i controlli relativi al caso "radice"
}



/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero 
// (o sottoalbero) t e se il padre esiste. 
// Restituisce la costante emptyLabel altrimenti
Label tree::father(const Label l, const Tree& t)
{ 
if (isEmpty(t)) return emptyLabel;
 
if (hasChildWithLabel(l, t)) return t->label;

Tree child = t->firstChild;
Label auxL;
while (!isEmpty(child))
    { 
       auxL = father(l, child);
       if (auxL != emptyLabel)
          return auxL;
       else 
          child = child->nextSibling;
    }
return emptyLabel;  
}



/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette 
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola 
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree& t)
{
Tree auxT = getNode(l, t);
list::List lst = list::createEmpty();

if (!isEmpty(auxT))
   {
   Tree child = auxT->firstChild;
   while (!isEmpty(child))
      {
      list::addBack(child->label,lst);
      child = child->nextSibling;
      }
    }
return lst;
}



/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste 
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree& t)
{
if (!member(l,t))
   return -1;
else 
   return list::size(children(l, t)); // non è l'implementazione più efficiente, ma il codice è molto compatto e leggibile!
}



/*******************************************************************************************************/
// ancestorsAux (versione ricorsiva) restituisce true se nel sottoalbero radicato in t e' stata trovata 
// l'etichetta cercata; il parametro lst passato per riferimento viene modificato di conseguenza
bool ancestorsAux(const Label l, const Tree& t, list::List& lst)
{
if (isEmpty(t)) return false; // se t e' vuoto restituisco false

if (hasChildWithLabel(l, t))  // se uno dei figli di t ha l'etichetta cercata, t è il primo dei suoi ancestors: devo mettere la sua etichetta nella lista e restituire true
   {
   list::addFront(t->label, lst);
   return true;
   }

// altrimenti esploro i figli di t finché non ne trovo uno in cui e' presente la label l; quando una delle chiamate restituisce true, aggiungo l'etichetta di t alla lista restituita dalla chiamata, e restituisco true
Tree auxT= t->firstChild;
while (!isEmpty(auxT))
   {
   if (ancestorsAux(l, auxT, lst))
      {
      list::addFront(t->label, lst);
      return true;
      }
   else 
      auxT = auxT->nextSibling;
   } 
return false;
}



/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsR(const Label l, const Tree& t)
{
list::List lst = list::createEmpty();
ancestorsAux(l, t, lst);
return lst;
}



/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree& t)
{
list::List lst = list::createEmpty();
if (father(l, t) == emptyLabel ||  isEmpty(t)) return lst;

// Idea dell'algoritmo: risalgo la lista dei padri finché non trovo la radice;
// inserisco nella lista in modo che la radice sia sempre il primo elemento
Label rootLabel = t->label;
Label auxL = l;
while (auxL!=rootLabel)
   {
   auxL = father(auxL, t); 
   list::addFront(auxL,lst);
} 
return lst;
}



/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune 
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree& t)
{
// Idea dell'algoritmo: creo le liste degli ancestor delle due etichette e le confronto
list::List lst1 = ancestorsR(label1, t);
list::List lst2 = ancestorsR(label2, t);
if (list::isEmpty(lst1) || list::isEmpty(lst2)) return emptyLabel; // se una delle due liste di ancestor e' vuota, non c'e' antenato comune

// altrimenti inizio a scandire le liste dal primo elemento, che deve esistere e deve per forza essere la radice
// e mi fermo quando i due elementi della lista sono diversi, o quando una delle due liste finisce
int index = 0; 
while (list::get(index, lst1) == list::get(index, lst2) && index<list::size(lst1) && index<list::size(lst2))
   index++;

// restituisco l'elemento in posizione precedente a quello del primo elemento diverso
return get(index-1,lst1);
}



/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree& t)
{ 
// se l'albero e' vuoto, l'etichetta non c'è e restituisco false
    if (isEmpty(t))
        return false;

// se l'etichetta dell'albero è quella cercata, restituisco true
    if (t->label == l) 
        return true;

// Chiamata ricorsiva di member su ciascuno dei figli di t, finché una delle chiamate non restituisce un valore diverso da false
    Tree auxT = t->firstChild;
    while (auxT != emptyTree) {
        if (!member(l, auxT)) // non ho trovato cercando in questo sottoalbero, devo proseguire la scansione dei fratelli 
           auxT = auxT->nextSibling;
        else                      // ho trovato: restituisco true
           return true;
    }   
return false; // se arrivo fino a qui, vuole dire che al termine di una ricerca esaustiva nell'albero il nodo non è stato trovato 
}



/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst
int tree::numNodes(const Tree& t)
{
 if (isEmpty(t)) return 0;
 Tree auxT = t->firstChild;
 int res = 0;
 while (auxT != emptyTree) 
     {
     res += numNodes(auxT);
     auxT = auxT->nextSibling;
     }   
return res+1; 
}



/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty()
{
return emptyTree;
}



/*******************************************************************************************************/
// Funzione ausiliaria per la visualizzazione strutturata
void printTree(const Tree& t, int depth) {
    if (isEmpty(t)) return;

    string indent = "--";
// Inserisco indentazione corrispondente alla profondita' raggiunta
    for (int i=0; i<depth; i++)
        cout << indent;

// Visualizzo il contenuto informativo associato a t
    cout << t->label << endl;

// Chiamata ricorsiva di printTree su ciascuno dei figli di t (profondita' incrementata di 1)
    Tree auxT = t->firstChild;
    while (!isEmpty(auxT)) {
        printTree(auxT, depth+1);
        auxT = auxT->nextSibling;
    }
}



/*******************************************************************************************************/
// Visualizzazione strutturata: parto dal livello 0
void printTree(const Tree& t) {
    printTree(t, 0);
}



/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad 
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per 
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla 
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando getNode e qualche funzione ausiliaria che operi 
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione... 
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per 
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream& str)
{
    Tree t = createEmpty(); 
    string line;
    Label rootLabel, fatherLabel, childLabel;
    getline(str, line);  
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())  
        {        
	instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
        while (!instream.eof())            // finche' la riga corrente non e' terminata
            { 
            instream >> childLabel;              // leggo la prossima etichetta
            removeBlanksAndLower(childLabel);    // la normalizzo
            addElem(fatherLabel, childLabel, t); // e la attacco al padre
            }
        getline(str, line);  
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



/****************************************************************/
Tree readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}  
    return readFromStream(ifs);
}

