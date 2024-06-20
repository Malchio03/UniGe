#include <string>
#include <iostream>
#include "ASD-aritexpr.h"
#include "ASD-token.h"
#include "ASD-stack.h"

using namespace stack;
using namespace std;

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica*/
/*solleva un eccezione di tipo string*/
/*con valore: "Lexical Error" se st non è composta da tokens*/
/*e valore: "Syntactical Error" se st è ben formata*/
int compute_arithmetic_expr(const string& st){
	Stack pila = stack::createEmpty();
	string ST = st;
	string Syn = "Syntactical error";
	Elem el, op;
	while (nextToken(ST, el)) {// string non è vuota
		if (el.k == 0 || el.k == 2 || el.k == 3 || el.k == 4 || el.k == 5){

			stack::push(el,pila);  // "(","numero","+","*","-"

		} else if (el.k == 1) {						//")"
			int secondo = 0;
			int primo = 0;
			el = stack::pop(pila);		//-1°
			if(el.k!=2)		throw Syn; // se -1° non è un numero
			else	secondo=el.val;
			op = stack::pop(pila);		// -2° in op
			el = stack::pop(pila);		// -3°
			if (el.k!=2)		throw Syn; // se -3° non è un numero
			else	primo=el.val;
			el = stack::pop(pila);		// -4°
			if(el.k !=0)		throw Syn; // se -4° non è un (
			if(op.k != 3 && op.k!= 4 && op.k!= 5)		throw Syn; // se -2° non è +; -; *;
			else if(op.k==3){ 	// se è un +
				el.k = NUMERO;	// sostituisco ( con il risultato
				el.val = primo + secondo;
				stack::push(el,pila);
			}
			else if(op.k == 4){ 	//se è un -
				el.k = NUMERO;	// sostituisco ( con il risultato
				el.val = primo - secondo;
				stack::push(el,pila);
			}
			else if(op.k == 5){ 	// se è un *
				el.k = NUMERO;	// sostituisco ( con il risultato
				el.val = primo * secondo;
				stack::push(el,pila);
			}
		}
	}
	el = stack::pop(pila);
	if(pila.size != 0 || el.k != 2)		throw Syn;
return el.val;
}
