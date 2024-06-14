#include <iostream>
#include <string>
#include <thread>
using namespace std;

void A (string messaggio) {
    cout << messaggio;
}

void B (string messaggio) {
    cout << messaggio;
}

void C (string messaggio) {
    cout << messaggio;
}

void D (string messaggio) {
    cout << messaggio;
}

void E (string messaggio) {
    cout << messaggio;
}

int main() {
    // eseguo A e B in parallelo
    thread t1(A, "hello world");
    thread t2(B, "!!!");

    // attendo la fine di A e B
    t1.join();
    t2.join();

    // eseguo C 
    thread t3(C, "ciao");

    t3.join();

    // eseguo D e E in parallelo
    thread t4(D, "Ciao ");
    thread t5(E, "Mondo");

    // attendo la fine di D e E
    t4.join();
    t5.join();
}