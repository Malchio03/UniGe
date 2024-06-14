#include <iostream>
#include "list.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  return b ? "SI" : "NO";
}
////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */

std::string printList(const List &l) {
    std::string out = "(";
    List current = l;
    while (current != nullptr) {
        if (current != l) out += ",";
        out += current->elem;
        current = current->next;
    }
    out += ")";
    return out;
}
////////////////////////////////////////////////////////////////////////////
int main(){
    int ret=0;
    int nTest=0;
    cout << std::boolalpha;
    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST contaElementi(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        unsigned int res =  contaElementi(l);
        unsigned int corr=0;
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "B");
        unsigned int res =  contaElementi(l);
        unsigned int corr=2;
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST aggiungiInTesta(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "B");
        List res = l;
        List corr = l; // Assuming l now points to a list (B, A)
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST eliminaElementi(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    // Test 1: Lista vuota
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        eliminaElementi(l, "A");
        List res = l;
        List corr = nullptr; // La lista corretta è ancora vuota
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    // Test 2: Elemento da eliminare non presente
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "B");
        eliminaElementi(l, "C");
        List res = l;
        List corr = nullptr;
        aggiungiInTesta(corr, "A");
        aggiungiInTesta(corr, "B"); // La lista corretta (B, A)
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    // Test 3: Eliminazione dell'unico elemento
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        eliminaElementi(l, "A");
        List res = l;
        List corr = nullptr; // La lista corretta è vuota
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    // Test 4: Eliminazione del primo elemento in una lista di più elementi
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "B");
        aggiungiInTesta(l, "C");
        eliminaElementi(l, "C");
        List res = l;
        List corr = nullptr;
        aggiungiInTesta(corr, "A");
        aggiungiInTesta(corr, "B"); // La lista corretta (B, A)
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    // Test 5: Eliminazione di un elemento nel mezzo
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "B");
        aggiungiInTesta(l, "C");
        eliminaElementi(l, "B");
        List res = l;
        List corr = nullptr;
        aggiungiInTesta(corr, "A");
        aggiungiInTesta(corr, "C"); // La lista corretta (C, A)
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    // Test 6: Eliminazione di tutti gli elementi uguali in una lista
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        List l = nullptr;
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "A");
        aggiungiInTesta(l, "A");
        eliminaElementi(l, "A");
        List res = l;
        List corr = nullptr; // La lista corretta è vuota
        cout << "\nLa lista data e': " << printList(l);
        cout << "\nLa funzione deve ritornare " << printList(corr);
        cout << "\nLa funzione ritorna " << printList(res);
        bool ans = (printList(res) == printList(corr));
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    
    cout << "\n";
    cout << "=======> NUMERO DI TEST SUPERATI: " << ret << "/" << nTest << endl;
    return ret;
}
