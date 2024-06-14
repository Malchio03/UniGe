#include <iostream>
#include <thread>
#include <chrono>

void piano_thread() {
    int x = 40;
    for (int i = 0; i < 10; ++i) {
        x += 4;
        // sleep 0.5
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // play x
        std::cout << "Piano: " << x << std::endl;
    }
}

void kalimba_thread() {
    int x = 40;
    for (int i = 0; i < 10; ++i) {
        x -= 4;
        // sleep 0.5
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // play x
        std::cout << "Kalimba: " << x << std::endl;
    }
}

int main() {
    std::thread t1(piano_thread);
    std::thread t2(kalimba_thread);

    t1.join();
    t2.join();

    return 0;
}
