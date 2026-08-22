#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "semaphor.h"

#define N 5

void *philosophers(void *ptr);

pthread_mutex_t chopsticks[N];
pthread_t threads[N];
my_semaphore room;

int main() {
    int id[N] = {0, 1, 2, 3, 4};

    for (int i = 0; i < N; ++i) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // init semaforo
    my_sem_init(&room, N - 1);

    for (int i = 0; i < N; ++i) {
        pthread_create(&threads[i], NULL, philosophers, &id[i]);
    }

    for (int i = 0; i < N; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; ++i) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    // destroy semafoto
    my_sem_destroy(&room);
    
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
        
        // entra nella sala
        my_sem_wait(&room);

        pthread_mutex_lock(&chopsticks[left_chopstick]);
        printf("Filosofo %d: ha la bacchetta sinistra\n", ph_id);

        pthread_mutex_lock(&chopsticks[right_chopstick]);
        printf("Filosofo %d: ha la bacchetta destra\n", ph_id);

        printf("Filosofo %d: sta mangiando\n", ph_id);
        sleep(2);

        pthread_mutex_unlock(&chopsticks[left_chopstick]);
        pthread_mutex_unlock(&chopsticks[right_chopstick]);

        // esce dalla sala
        my_sem_signal(&room);
    }
    return NULL;
}