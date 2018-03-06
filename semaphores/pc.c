#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#define N 5


int buffer[N];

int in = 0, out = 0;


sem_t mutex, full, empty;

void initSemaphores() {


    sem_init(&mutex, 0, 1);
    

    sem_init(&full, 0, 0);
    

    sem_init(&empty, 0, N);
} 


void *producer() {
    

    int i;
    for (i = 0; i < 10; i++) {


        sem_wait(&empty);
        

        sem_wait(&mutex);
        
        printf("Produced item is: %d\n",i);
        

        buffer[in] = i;
        in = (in + 1) % N;
        sleep(1);

        sem_post(&mutex);

        sem_post(&full);
    
    }

}



void *consumer() {
    
    int item;
    

    int i;
    for (i = 0; i < 10; i++) {
        

        sem_wait(&full);
        

        sem_wait(&mutex);
        

        item = buffer[out];
         
        printf("Consumed item is: %d\n", item);
        out = (out + 1) % N;
        sleep(1);
        

        sem_post(&mutex);
        

        sem_post(&empty);
    
    }

}
      
      
      
        
int main() {
            
    initSemaphores();
    
   
    pthread_t produce, consume;
    

    pthread_create(&produce ,NULL, producer, NULL);
    pthread_create(&consume, NULL, consumer, NULL);
    
    pthread_join(produce, NULL);
    pthread_join(consume, NULL);
    
    return 0;
}