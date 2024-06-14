#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

 int notes[] = {52, 55, 59, 40};
 int i = 0;

void playNote(int note) {
    std::cout << "Playing note: " << notes[note] << std::endl;
}

void foo(int x) {
    std::thread thread(playNote, x);
    thread.join();
}

int main() {
    
    // 3.times do
    for (int j = 0; j < 3; j++) {
        foo(i);
        i++;
    }
    return 0;
}
