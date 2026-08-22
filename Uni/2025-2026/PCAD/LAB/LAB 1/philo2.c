#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Prototipo
void *philosophers(void *ptr);

pthread_mutex_t chopsticks[5];
pthread_t threads[5];

int main() {
    int id[5] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_create(&threads[i], NULL, philosophers, &id[i]);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_mutex_destroy(&chopsticks[i]);
    }
    return 0;
}

void *philosophers(void *ptr) {
    // prendo id univoco
    int ph_id = *(int *)ptr; 
    int left_chopstick = ph_id;
    int right_chopstick = (ph_id + 1) % 5; 

    for(unsigned int i = 0; i < 5; ++i) {
        printf("Filosofo %d: sta pensando\n", ph_id);
        sleep(2); 
        if (ph_id == 2){
            pthread_mutex_lock(&chopsticks[right_chopstick]);
            printf("Filosofo %d: ha la sua bacchetta destra\n", ph_id);
            pthread_mutex_lock(&chopsticks[left_chopstick]);
            printf("Filosofo %d: ha la sua bacchetta sinistra\n", ph_id);
        } else {
            // prendo bacchetta sinistra
            pthread_mutex_lock(&chopsticks[left_chopstick]);
            printf("Filosofo %d: ha la sua bacchetta sinistra\n", ph_id);
            // prend bacchetta destra
            pthread_mutex_lock(&chopsticks[right_chopstick]);
            printf("Filosofo %d: ha la sua bacchetta destra\n", ph_id);
        }
        sleep(2);
        // mangio
        printf("Filosofo %d: sta mangiando\n", ph_id);
        sleep(4);
        // rilascio
        pthread_mutex_unlock(&chopsticks[left_chopstick]);
        pthread_mutex_unlock(&chopsticks[right_chopstick]);
    }
 
    printf("Filosofo %d: ha rilasciato le sue due bacchette\n", ph_id);
    return NULL;
}