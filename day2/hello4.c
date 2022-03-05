#include "pthread.h"
#include "stdio.h"

long int count = 0;
pthread_mutex_t count_lock;

void *thread1(void *arg){
    pthread_mutex_lock(&count_lock);
    for (int i = 0; i < 50000; i++)
    {
        count++;
    }
    pthread_mutex_unlock(&count_lock);

    return NULL;
}

void *thread2(void *arg){
    pthread_mutex_lock(&count_lock);
    for (int i = 50000; i < 1000000; i++)
    {
        count++;
    }
    pthread_mutex_unlock(&count_lock);

    return NULL;
}

int main(){
    int i = 0;
    int n = 10000;
    int sum = 0;
    pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_mutex_init(&count_lock, NULL);

    pthread_create(&thread_id1, NULL, thread1, NULL);
    pthread_create(&thread_id2, NULL, thread2, NULL);
    
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_mutex_destroy(&count_lock);

    printf("sum = %ld \n", count);
    
    return 0;
}