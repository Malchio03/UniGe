#include <iostream>
#include <vector>

using namespace std;


// Funzione 3: Fonde le due metà.


/*
prende in input due sequenze o sotto sequenze, scorre le due sequenze, elemento per elemento, confrontando a mano a mano gli elementi tra di loro ,
l’elemento minore lo inserisce nella sequenza risultante, quello maggiore viene usato per il confronto successivo se una delle due sequenze termina
gli elementi dell’altra sequenza(che sono già ordinati) vengono messi in coda theta(n) per ogni livello.

*/
void fondi(vector<int> &v, unsigned int inizio, unsigned int centro, unsigned int fine) {

    // Dichiario e riempio i due vettori
    vector<int> vsinistra, vdestra;

    for(unsigned int i = inizio; i <= centro; ++i) {
        vsinistra.push_back(v[i]);
    }

    for(unsigned int i = centro + 1; i <= fine; ++i) {
        vdestra.push_back(v[i]);
    }

    // dichiaro gli indici neccessari 
    unsigned int indicesinistra = 0;
    unsigned int maxsin = vsinistra.size();
    unsigned int indicedestra = 0; 
    unsigned int maxdes = vdestra.size();

    // scorro i due vettori, elemento per elemento, confrontando mano a mano gli elementi tra loro
    for (unsigned int i = inizio; i <= fine; ++i) {
        if (indicesinistra < maxsin && indicedestra < maxdes) {
            if (vsinistra[indicesinistra] < vdestra[indicedestra]) {
                v[i] = vsinistra[indicesinistra];
                ++indicesinistra;
                continue;   // permette di evitare gli altri if e di passare direttamente alla prossima iterazione
            }
            else {
                v[i] = vdestra[indicedestra];
                ++indicedestra;
                continue;
            }
        }

        // se uno dei due vettori non confronta elementi, vuol dire che questi sono i più grandi e vengono aggiunti in coda
        if (indicesinistra == maxsin && indicedestra < maxdes) {
            v[i] = vdestra[indicedestra];
            ++indicedestra;
            continue;
        }

        if (indicedestra == maxdes && indicesinistra < maxsin) {
            v[i] = vsinistra[indicesinistra];
            ++indicesinistra;
            continue;
        }
    }
}


// Funzione 2: Definisce le due metà (gli indici di inizio e di fine), le ordina chiamando fondi e grazie all’ultima chiamata di quest’ultima le mette assieme ordinandole.
void ms(vector<int> &v, unsigned int inizio, unsigned int fine) {
    if (inizio < fine) {
        unsigned int centro = (inizio + fine) / 2;
        ms(v,inizio, centro);
        ms(v, centro + 1, fine);
        fondi(v, inizio, centro, fine);
    }
}

// Funzione 1: Gestisce il caso di un vettore vuoto e chiama ms passando inizio e fine del vettore da ordinare.
void mergeSort(vector<int>& v) {
    if (v.size() != 0) {
        ms(v, 0, v.size() - 1);
    }
}

int main() {
    // Creazione di un vettore non ordinato
    vector<int> v = {7,2,4,5,3,1,5,6};

    // Stampiamo il vettore prima dell'ordinamento
    cout << "Vettore prima dell'ordinamento:" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    
    mergeSort(v);

    cout << "\nVettore dopo l'ordinamento:" << endl;

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

}

