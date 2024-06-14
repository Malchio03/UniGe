#include <iostream>
#include <thread>
using namespace std; 

// Funzione eseguita dal thread
void threadFunction(int id) {
    std::cout << "Thread " << id << " is running\n";
}

int main() {
    // Creare due thread
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);

    // Attendere che i thread terminino
    t1.join();
    t2.join();

    std::cout << "Threads have finished execution\n";
    return 0;
}
