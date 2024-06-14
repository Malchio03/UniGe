#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int x = 40; // Variabile globale condivisa

void piano_thread() {
    for (int i = 0; i < 10; ++i) {
        x += 4;
        
        std::cout << "Piano: " << x << std::endl;
        // sleep 0.5
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void kalimba_thread() {
    for (int i = 0; i < 10; ++i) {
        x -= 4;

        std::cout << "Kalimba: " << x << std::endl;
        // sleep 0.5
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread t1(piano_thread);
    std::thread t2(kalimba_thread);

    t1.join();
    t2.join();

    return 0;
}
