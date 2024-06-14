// Programma per il calcolo a complemento a 1

#include <iostream>
#include <thread>
#include <vector>
#include <array>

const int ARRAY_SIZE = 100;
const int THREAD_COUNT = 5;
std::array<int, ARRAY_SIZE> binaryArray;
std::array<int, ARRAY_SIZE> complementArray;

// Funzione che calcola il complemento a 1 per una porzione dell'array
void calculateComplement(int start, int end) {
    for (int i = start; i < end; ++i) {
        complementArray[i] = binaryArray[i] == 0 ? 1 : 0;
    }
}

int main() {
    // Inizializzare l'array binario con valori a caso (0 e 1)
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        binaryArray[i] = i % 2; // Esempio: alternare tra 0 e 1
    }

    // Creare i thread
    std::vector<std::thread> threads;
    int segmentSize = ARRAY_SIZE / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; ++i) {
        int start = i * segmentSize;
        int end = (i == THREAD_COUNT - 1) ? ARRAY_SIZE : (i + 1) * segmentSize;
        threads.emplace_back(calculateComplement, start, end);
    }

    // Attendere che tutti i thread terminino
    for (auto& t : threads) {
        t.join();
    }

    // Stampare il risultato
    std::cout << "Original Array: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << binaryArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Complement Array: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << complementArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
