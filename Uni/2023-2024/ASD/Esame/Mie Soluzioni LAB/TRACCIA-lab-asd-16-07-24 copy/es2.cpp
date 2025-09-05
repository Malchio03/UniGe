#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

void insertBst2(intpair p, pairBstTree2& pbst){
	if (isPresentBst2(p, pbst)) return; // esco
	
	if (pbst == emptyPairBstTree2) {
		pairBstTree2 albero2 = new pairBstNode2;
		albero2 -> el = p.v2;
		albero2 -> left2 = nullptr;
		albero2 -> right2 = nullptr;
		pbst = albero2;
		return;
	}
	if (p.v2 > pbst -> el) {
		insertBst2(p, pbst -> right2);
	} else {
		insertBst2(p, pbst -> left2);
	}
}

bool isPresentBst2(intpair p, pairBstTree2& pbst) {

	if (pbst == emptyPairBstTree2) return false;

	if (pbst -> el == p.v2) return true;

	if (p.v2 > pbst -> el) {
		return isPresentBst2(p, pbst -> right2);
	} else {
		return isPresentBst2(p, pbst -> left2);
	}

	return false;
}

//Es 2
//Inserisce una nuova coppia di interi nell'albero
//Ritorna false, se la coppia e' gia' presente e in questo caso non la inserisce
//Altrimenti ritorna true
bool insertPair(intpair p, pairBstTree& pbst){
	// caso vuoto
	if (pbst == emptyPairBstTree) {
		pairBstTree albero1 = new pairBstNode;
		albero1 -> el = p.v1;
		albero1 -> left1 = nullptr;
		albero1 -> right1 = nullptr;

		// creo il bst2
		pairBstTree2 albero2 = new pairBstNode2;
		albero2 -> el = p.v2;
		albero2 -> left2 = nullptr;
		albero2 -> right2 = nullptr;

		pbst = albero1;
		pbst -> bst2 = albero2;

		return true;
	}

	// tutti gli altri casi

	// controllo se la coppia esiste
	if (pbst -> el == p.v1) {
		// controllo il suo pbst2
		if (isPresentBst2(p, pbst -> bst2)) return false;		// esiste già la coppia

		insertBst2(p, pbst -> bst2);
		
		return true;
	}

	if (p.v1 > pbst -> el) {
		return insertPair(p, pbst -> right1);
	} else {
		return insertPair(p, pbst -> left1);
	}
}


