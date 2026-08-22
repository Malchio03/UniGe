#include"my_barrier.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

my_barrier barrier;
void *thread(void *ptr) {
    int t_id = *(int *) ptr;
    printf("Thread %d: prima della barriera\n", t_id);
    pthread_my_barrier_wait(&barrier);
    printf("Thread %d: dopo la barriera\n", t_id);
   return NULL;
}

int main() {
   pthread_t threads[5];
   int id[5] = {0, 1, 2, 3, 4};
   unsigned int v = 5;

   pthread_my_barrier_init(&barrier, v);
    // creo threads
    for(unsigned int i = 0; i < v; ++i) {
        pthread_create(&threads[i], NULL, thread, &id[i]);
       // sleep(2);
    }
    // joino i threads
    for (unsigned int i = 0; i < v; ++i) {
        pthread_join(threads[i], NULL);
    }
}

unsigned int pthread_my_barrier_init(my_barrier *mb, unsigned int v) {
    if(v == 0) return -1;
    mb->vinit = v;
    mb->val = 0;  // non conta nulla
    pthread_mutex_init(&mb->lock, NULL);
    pthread_cond_init(&mb->varcond, NULL);

    return 0;
}

unsigned int pthread_my_barrier_wait(my_barrier *mb) {
    // blocchiamo chi mi sta chiamando
    pthread_mutex_lock(&mb->lock);
    mb->val++;

    if (mb->val == mb->vinit) {
        mb->val = 0;
        pthread_cond_broadcast(&mb->varcond);
    } else {
        pthread_cond_wait(&mb->varcond, &mb->lock);
        //sleep(2);
    }

    pthread_mutex_unlock(&mb->lock);
    return 0;
}

