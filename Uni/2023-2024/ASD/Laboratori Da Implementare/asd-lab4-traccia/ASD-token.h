#ifndef ASD_TOKEN_H
#define ASD_TOKEN_H

#include <string>

//Tipi di dato semplici
enum kind {PARENTESI_APERTA, PARENTESI_CHIUSA, NUMERO, OP_SOMMA,
OP_SOTTRAZIONE, OP_MOLTIPLICAZIONE};

struct token {
  int val;
  kind k;
};

/**************************************************/
/*       prototipi di funzioni da implementare    */
/**************************************************/
//funzione che estrae il prossimo token della string st
//lo mette in tok e modifica st,
//ritorna true se c'era un token da estrarre,
//ritorna false se non c'era da estrarre e si e arrivato alla fine di st,
//solleva una eccezione di tipo string se legge un token di tipo sconosciuto
bool nextToken(std::string &st, token &tok);

#endif
