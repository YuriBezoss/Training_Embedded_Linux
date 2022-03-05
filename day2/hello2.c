#include "pthread.h"
#include "stdio.h"

long int count = 0;
int is_printf = 0;

void *thread_test(void *arg){
    long int n = 5000000000;
    for (long int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            count += 1;
        }
    }
    printf("sum = %ld \n", count);
}

int main(){
    int i = 0;
    long int n = 20000000000;
    long int sum = 0;
    pthread_t thread_id1, thread_id2, thread_id3, thread_id4;
    pthread_t thread_id;

    pthread_create(&thread_id1, NULL, thread_test, &sum);
    pthread_join(thread_id1, NULL);

    pthread_create(&thread_id2, NULL, thread_test, &sum);
    pthread_join(thread_id2, NULL);

    pthread_create(&thread_id3, NULL, thread_test, &sum);
    pthread_join(thread_id3, NULL);

    pthread_create(&thread_id4, NULL, thread_test, &sum);
    pthread_join(thread_id4, NULL);
    
    printf("sum = %ld \n", count);

    return 0;
}