#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 3
//Ritorna la coppia piu' piccola dell'albero
//Se l'albero e' vuoto, ritorna noPair
intpair minPair(const pairBstTree& pbst) {
	if (pbst == emptyPairBstTree) return noPair;

	if (pbst->left1 == emptyPairBstTree) {
		// se bst2 non esiste allora sicuramente la coppia non esiste
		if (pbst->bst2 == emptyPairBstTree2) return noPair;

		// cerco in profonditè in bst2
		pairBstTree2 bst2 = pbst->bst2;
		while (bst2->left2 != emptyPairBstTree2) {
			bst2 = bst2->left2;
		}

		intpair coppia;
		coppia.v1 = pbst->el;
		coppia.v2 = bst2->el;
		return coppia;
	}

	// cerco ricorsivamente su pbst1
	return minPair(pbst->left1);
}

