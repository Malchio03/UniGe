//FILE DA MODIFICARE
#include <iostream>
#include "ASD-token.h"
#include <string> 

using namespace std;

/**************************************************/
/*      funzioni ausiliari                 */
/**************************************************/

bool isNumber(const string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}



/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

bool nextToken(string &st, token &tok) {
  string err = "Lexical error";
  if (st == "") {
    return false; 
  }
  string s = st.substr(0,1);   //prendo 1° carettere
  // elimino tutti spazi iniziali
  while(s == " "){   
    st.erase(0,1);
    s = st.substr(0,1);
  }
  if(s == "(" || s == "+" || s == "-" || s == "*") {
    if(s == "("){
      tok.k = PARENTESI_APERTA;
      }
    else if(s == "+"){
     tok.k = OP_SOMMA;
    }
    else if(s == "-"){
     tok.k = OP_SOTTRAZIONE;
    }
    else if(s == "*"){
    tok.k = OP_MOLTIPLICAZIONE;
    }
    st.erase(0,1);
    s = st.substr(0,1);
    if(s != " ") throw err;
    while(s == " ") {
        st.erase(0,1);
        s = st.substr(0,1);
    }
    return true;
} else if(s == ")") {
    st.erase(0,1);
    s = st.substr(0,1);
    if(s != " " && s != "") throw err;
    while(s == " ") {
        st.erase(0,1);
        s = st.substr(0,1);
    }
    tok.k = PARENTESI_CHIUSA;
    return true;
}
  else if(isNumber(s)) {
    int value = 0;
    while(s >= "0" && s <= "9") {
        value = value * 10 + stoi(s);
        st.erase(0,1);
        s = st.substr(0,1);
    }
    if(s != " " && s != "") throw err;
    while(s == " ") {
        st.erase(0,1);
        s = st.substr(0,1);
    }
    tok.k = NUMERO;
    tok.val = value;
    return true;
}
  throw err; //non è un token: (; ); Numero; operazioni
}








                            // alternativa

/*bool nextToken(string &st, token &tok) {
    // Elimina gli spazi all'inizio
    while (!st.empty() && st[0] == ' ') {
        st.erase(0, 1);
    }

    // Se la stringa è vuota dopo l'eliminazione degli spazi, ritorna false
    if (st.empty()) {
        return false;
    }

    // Se il primo carattere è una parentesi aperta, il token è di tipo PARENTESI_APERTA
    if (st[0] == '(') {
        tok.k = PARENTESI_APERTA;
        tok.val = 0; // Valore non significativo per questo tipo di token
        st.erase(0, 1); // Rimuove la parentesi aperta dalla stringa
        return true;
    }
    // Se il primo carattere è una parentesi chiusa, il token è di tipo PARENTESI_CHIUSA
    else if (st[0] == ')') {
        tok.k = PARENTESI_CHIUSA;
        tok.val = 0; // Valore non significativo per questo tipo di token
        st.erase(0, 1); // Rimuove la parentesi chiusa dalla stringa
        return true;
    }
    // Se il primo carattere è un numero, estrai il numero come token di tipo NUMERO
    else if (isdigit(st[0])) {
        string num_str;
        int i = 0;
        while (i < st.size() && (isdigit(st[i]) || st[i] == '.')) {
            num_str += st[i++];
        }

        // Controlla se il token è un numero valido
        if (!isNumber(num_str)) {
            throw string("Errore: Token non valido");
        }

        // Converte la stringa in un numero intero e lo assegna al campo val del token
        tok.val = stoi(num_str);
        tok.k = NUMERO;
        st.erase(0, i); // Rimuove il numero dalla stringa
        return true;
    }
    // Altrimenti, solleva un'eccezione per un token di tipo sconosciuto
    else {
        throw string("Errore: Token non riconosciuto");
    }
}*/

