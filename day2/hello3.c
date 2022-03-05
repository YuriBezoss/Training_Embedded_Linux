#include "pthread.h"
#include "stdio.h"

long int count = 0;

void *thread1(void *arg){
    for (int i = 0; i < 50000; i++)
    {
        count++;
    }

    return NULL;
}

void *thread2(void *arg){
    for (int i = 50000; i < 1000000; i++)
    {
        count++;
    }

    return NULL;
}

int main(){
    int i = 0;
    int n = 10000;
    int sum = 0;
    pthread_t thread_id1;
    pthread_t thread_id2;

    pthread_create(&thread_id1, NULL, thread1, NULL);
    pthread_create(&thread_id2, NULL, thread2, NULL);
    
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("sum = %ld \n", count);
    
    return 0;
}