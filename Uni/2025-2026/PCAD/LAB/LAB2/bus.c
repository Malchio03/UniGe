#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int N = 15;
const int C = 6;

int count = 0;
int in_viaggio = 0; // flag di stato

// bus
pthread_mutex_t mutex_bus = PTHREAD_MUTEX_INITIALIZER;

// bus che aspetta che entra la gente (bus vuoto)
pthread_cond_t bus_vuoto = PTHREAD_COND_INITIALIZER;
// bus che è in viaggio
pthread_cond_t bus_pieno = PTHREAD_COND_INITIALIZER;
// bus che è tornato  = persone possono uscire
pthread_cond_t bus_ritornato = PTHREAD_COND_INITIALIZER;

void *bus1(void *ptr){
    while(1)
    {
        pthread_mutex_lock(&mutex_bus);
        while(count < C)
        {   
            pthread_cond_wait(&bus_vuoto, &mutex_bus);
        }
        
        in_viaggio = 1; // blocca i nuovi imbarchi
        printf("il bus sta viaggiando\n");
        
        pthread_mutex_unlock(&mutex_bus);
        sleep(4);

        // bus arriva a destinazione

        pthread_mutex_lock(&mutex_bus);
        printf("bus arrivato al punto di partenza\n");

        // facciamo scendere tutti i passeggeri
        pthread_cond_broadcast(&bus_ritornato); 
        while(count > 0)
        {
            pthread_cond_wait(&bus_vuoto, &mutex_bus);    // finchè ci sono persone le facciamo scendere
        }
        
        in_viaggio = 0; // sblocca i nuovi imbarchi
        
        pthread_mutex_unlock(&mutex_bus);
    }
    return NULL;
}

void *passeggeri(void *ptr)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_bus);
        
        while(count == C || in_viaggio == 1)
        {
            pthread_cond_wait(&bus_ritornato, &mutex_bus); // aspetto che scendano tutti
        }

        // sale sul bus
        ++count;
        printf("Il passeggiero %d è salito\n", count);

        // se sono l'ultimo allora sveglio il bus per partire
        pthread_cond_signal(&bus_vuoto);

        // il bus fa il giro, il cliente aspetta
        pthread_cond_wait(&bus_ritornato, &mutex_bus);

        // scende dal bus
        --count;
        printf("Passeggero %d sceso\n", count + 1); // +1 per stampare da terminale il numero corretto

        // se è l'ultimo a scendere, avvisa il bus che è completamente vuoto
        if (count == 0)
            pthread_cond_signal(&bus_vuoto);

        pthread_mutex_unlock(&mutex_bus);
        sleep(4);
    }
    return NULL;
}

int main() {
    pthread_t bus_thread;
    pthread_t passenger_thread[N];
    int id[N];

    // creazione del thread bus
    pthread_create(&bus_thread, NULL, bus1, NULL);

    // creazione dei thread passeggeri
    for (int i = 0; i < N; i++) {
        id[i] = i + 1; 
        pthread_create(&passenger_thread[i], NULL, passeggeri, &id[i]);
    }

    // join dei thread (attesa)
    pthread_join(bus_thread, NULL);
    for (int i = 0; i < N; i++) {
        pthread_join(passenger_thread[i], NULL);
    }

    return 0;
}