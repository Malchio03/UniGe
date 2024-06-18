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
}

