#include "ternary-tree.h"

//Inserisce un nuovo elemento nel albero se questo elemento e' positivo
//e non e' gia' presente nel albero
void insert(Elem e,terTree& tr){
  // valore negativo, non valido
  if (e < 0 ) return;

  // caso albero vuoto
  if (tr == emptyTerTree) {
    terTree albero = new terNode;
    tr -> v1 = e;
    tr -> v2 = -1;
    tr -> left = emptyTerTree;
    tr -> middle = emptyTerTree; 
    tr -> right = emptyTerTree;
    return;
  }

  // se elemento già presente, esco
  if (tr -> v1 == e || tr -> v2 == e) return;

  // caso nodo ha solo v1
  if (tr -> v2 == -1) {
    // caso in cui e sia > v1
    if (e > tr -> v1) {
      tr -> v2 = e;
    } else {
      // devo swappare
      tr -> v2 = tr -> v1;
      tr -> v1 = e;
    }
    return;
  }

  // tutti gli altri casi
  
  // se e è più piccolo di v1 corrente vado nel figlio sinistro, esempio tr3
  if (e < tr -> v1 && e < tr -> v2) {
    insert(e, tr -> left);
  } else if(e > tr -> v1 && e < tr -> v2) {
    insert(e, tr -> middle);
  } else {
    insert(e, tr -> right);
  }

}
