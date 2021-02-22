#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int number = 0;

void* thread_1_function(void* arg){
    for(int i = 0; i < 100; i++){
        sleep(2);
        number++;
        printf("thread 1 : %d\n", number);
    }
    
    return NULL;
}

void* thread_2_function(void* arg){
    for(int i = 0; i < 100; i++){
        sleep(1);
        number++;
        printf("thread 2 : %d\n", number);
    }
    return NULL;
}

void main()
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, thread_1_function, NULL);
    pthread_create(&thread_2, NULL, thread_2_function, NULL);
    pthread_exit(NULL);
}

