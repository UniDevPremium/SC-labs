#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "e3.h"

unsigned int *shared_array;

// Inserire qui la soluzione
void* run(void* arg){
    thread_data_t data = *(thread_data_t*)arg;
    shared_array[data.tid] = data.it * data.val;
    return NULL;
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val){
    shared_array = (unsigned int*)malloc(th * sizeof(unsigned int));
    if(shared_array == NULL) {
        // Gestire errore di allocazione
        perror("Errore di allocazione della memoria!\n");
        exit(1);
    }
    // array di thread_data_t
    thread_data_t* arr = (thread_data_t*)malloc(th * sizeof(thread_data_t));
    if(arr == NULL){
        // Gestire errore di allocazione
        perror("Errore di allocazione della memoria!\n");
        exit(1);
    }
    int i;
    for(i = 0; i < th; i++){
        arr[i].it = it;
        arr[i].val = val;
        arr[i].tid = i;
    }
    // fork thread
    pthread_t threads[th];
    for(i = 0; i < th; i++){
        int res = pthread_create(&threads[i], NULL, run, (void*)&arr[i]);
        if(res != 0){
            perror("Errore nella creazione dei thread!\n");
            exit(1);
        }
    }
    // join thread
    for(i = 0; i < th; i++){
        pthread_join(threads[i], NULL);
    }
    // calcolo somma
    unsigned int sum = 0;
    for(i = 0; i < th; i++) sum += shared_array[i];


    free(shared_array);
    free(arr);
    return sum;
}