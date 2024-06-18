#include <string>
#include <iostream>
#include "ASD-aritexpr.h"
#include "ASD-token.h"
#include "ASD-stack.h"

using namespace std;
using namespace stack;

int compute_arithmetic_expr(const string& st_orig) {
    string st = st_orig; // Copia della stringa originale per evitare modifiche non volute

    Stack operandi = createEmpty(); // Stack per tenere traccia degli operandi
    Stack operatori = createEmpty(); // Stack per tenere traccia degli operatori

    token tok;
    int result = 0;
    bool has_operand = false;

    // Itera sulla stringa st per ottenere i token e valutare l'espressione
    while (nextToken(st, tok)) {
        // Se il token è un numero, inseriscilo nello stack degli operandi
        if (tok.k == NUMERO) {
            push(tok, operandi);
            has_operand = true;
        }
        // Se il token è un operatore, inseriscilo nello stack degli operatori
        else {
            if (tok.k != PARENTESI_APERTA && tok.k != PARENTESI_CHIUSA) {
                push(tok, operatori);
            }
        }

        // Se ci sono almeno due operandi e un operatore, esegui il calcolo
        if (!isEmpty(operandi) && !isEmpty(operatori)) {
            token op = pop(operatori);
            int operand2 = pop(operandi).val;
            int operand1 = pop(operandi).val;
            switch (op.k) {
                case OP_SOMMA:
                    push(token{operand1 + operand2, NUMERO}, operandi);
                    break;
                case OP_SOTTRAZIONE:
                    push(token{operand1 - operand2, NUMERO}, operandi);
                    break;
                case OP_MOLTIPLICAZIONE:
                    push(token{operand1 * operand2, NUMERO}, operandi);
                    break;
            }
        }
    }

    // Se la pila degli operandi contiene un solo elemento, restituiscilo come risultato
    if (!isEmpty(operandi) && isEmpty(operatori) && has_operand) {
        result = pop(operandi).val;
    } else {
        // Altrimenti, se ci sono errori lessicali o sintattici, solleva un'eccezione
        throw string("Syntactical Error");
    }

    return result;
}
