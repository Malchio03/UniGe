#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double re;  
    double im;  
    double modulo; 
    double fase; 
};

int main() {
    
    Complex numero1;
    cout << "Inserisci la parte reale del primo numero complesso: ";
    cin >> numero1.re;
    cout << "Inserisci la parte immaginaria del primo numero complesso: ";
    cin >> numero1.im;
    numero1.modulo = sqrt(numero1.re * numero1.re + numero1.im * numero1.im);
    numero1.fase = atan2(numero1.im, numero1.re);

    
    Complex numero2;
    cout << "\nInserisci la parte reale del secondo numero complesso: ";
    cin >> numero2.re;
    cout << "Inserisci la parte immaginaria del secondo numero complesso: ";
    cin >> numero2.im;
    numero2.modulo = sqrt(numero2.re * numero2.re + numero2.im * numero2.im);
    numero2.fase = atan2(numero2.im, numero2.re);

    // Somma dei numeri complessi
    Complex somma;
    somma.re = numero1.re + numero2.re;
    somma.im = numero1.im + numero2.im;
    somma.modulo = sqrt(somma.re * somma.re + somma.im * somma.im);
    somma.fase = atan2(somma.im, somma.re);

    // Differenza dei numeri complessi
    Complex differenza;
    differenza.re = numero1.re - numero2.re;
    differenza.im = numero1.im - numero2.im;
    differenza.modulo = sqrt(differenza.re * differenza.re + differenza.im * differenza.im);
    differenza.fase = atan2(differenza.im, differenza.re);

    // Prodotto dei numeri complessi
    Complex prodotto;
    prodotto.modulo = numero1.modulo * numero2.modulo;
    prodotto.fase = numero1.fase + numero2.fase;
    prodotto.re = prodotto.modulo * cos(prodotto.fase);
    prodotto.im = prodotto.modulo * sin(prodotto.fase);

    // Rapporto dei numeri complessi
    Complex rapporto;
    rapporto.modulo = numero1.modulo / numero2.modulo;
    rapporto.fase = numero1.fase - numero2.fase;
    rapporto.re = rapporto.modulo * cos(rapporto.fase);
    rapporto.im = rapporto.modulo * sin(rapporto.fase);

    
    cout << "\nSomma dei numeri complessi:" << endl;
    cout << "Parte reale: " << somma.re << ", Parte immaginaria: " << somma.im << endl;
    cout << "Modulo: " << somma.modulo << ", Fase: " << somma.fase << " rad" << endl;

    cout << "\nDifferenza dei numeri complessi:" << endl;
    cout << "Parte reale: " << differenza.re << ", Parte immaginaria: " << differenza.im << endl;
    cout << "Modulo: " << differenza.modulo << ", Fase: " << differenza.fase << " rad" << endl;

    cout << "\nProdotto dei numeri complessi:" << endl;
    cout << "Parte reale: " << prodotto.re << ", Parte immaginaria: " << prodotto.im << endl;
    cout << "Modulo: " << prodotto.modulo << ", Fase: " << prodotto.fase << " rad" << endl;

    cout << "\nRapporto dei numeri complessi:" << endl;
    cout << "Parte reale: " << rapporto.re << ", Parte immaginaria: " << rapporto.im << endl;
    cout << "Modulo: " << rapporto.modulo << ", Fase: " << rapporto.fase << " rad" << endl;

    return 0;
}
