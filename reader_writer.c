#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;  // Semaphores
int read_count = 0; // Number of active readers

void *reader(void *arg) {
    int id = *(int *)arg;
    
    sem_wait(&mutex);  // Lock mutex to update read_count
    read_count++;
    if (read_count == 1) {
        sem_wait(&wrt); // First reader locks writers
    }
    sem_post(&mutex);  // Unlock mutex

    // Reading section
    printf("Reader %d is reading\n", id);
    sleep(1);  // Simulate reading time

    sem_wait(&mutex);  // Lock mutex to update read_count
    read_count--;
    if (read_count == 0) {
        sem_post(&wrt); // Last reader unlocks writers
    }
    sem_post(&mutex);  // Unlock mutex

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    
    sem_wait(&wrt); // Writer locks resource exclusively

    // Writing section
    printf("Writer %d is writing\n", id);
    sleep(2);  // Simulate writing time

    sem_post(&wrt); // Unlock resource after writing

    return NULL;
}

int main() {
    pthread_t readers[5], writers[2];
    int reader_ids[5] = {1, 2, 3, 4, 5};
    int writer_ids[2] = {1, 2};

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader and writer threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
