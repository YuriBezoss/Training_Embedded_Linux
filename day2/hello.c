#include "pthread.h"
#include "stdio.h"

int is_printf = 0;

void *get_user_intput(void *arg){
    printf("in ket qua?");
    scanf("%d", &is_printf);
}

int main(){
    int i = 0;
    int n = 10000;
    int sum = 0;
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, get_user_intput, NULL);
    for (i = 0; i < n; i++)
    {
        sum = sum + i;
    }
    pthread_join(thread_id, NULL);

    if(is_printf)
        printf("sum = %d \n", sum);
    
    return 0;
}