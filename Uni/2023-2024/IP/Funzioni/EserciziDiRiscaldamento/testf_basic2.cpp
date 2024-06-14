#include <iostream>
using namespace std;

// Prototipi delle funzioni
void hello(); 
void hellomany(int); 
int givemefive(); 
int prossimo(int); 
int somma(int, int); 

int main() {

    hello();

    
    hellomany(5);

   
    cout << "Il valore restituito da givemefive è: " << givemefive() << endl;

    
    cout << "Il prossimo di 4 è: " << prossimo(4) << endl;

   
    cout << "La somma di 2 e 3 è: " << somma(2, 3) << endl;
}

// Definizione delle funzioni
void hello() {
    cout << "Hello, world\n";
}

void hellomany(int n) {
    cout << "Hello, we are " << n << endl;
}

int givemefive() {
    return 5;
}

int prossimo(int n) {
    return n + 1;
}

int somma(int a, int b) {
    return a + b;
}
