#include <iostream>
#include <string>
#include <thread>
using namespace std;

void stampa (string messaggio) {
    cout << messaggio;
}

int main() {
    thread t1(stampa, "hello world");

    t1.join();
}