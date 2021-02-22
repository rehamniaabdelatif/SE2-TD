#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int number = 0;
int conter = 0;

void* thread_1_function(void* arg){
    int i = 0;
    while (i < 100)
    {
        if (conter == 1){
            number++;
            printf("thread 1 : %d\n", number);
            conter = 0;
            i++;
        }  
    }
    
    return NULL;
}

void* thread_2_function(void* arg){
    int i = 0;
    while (i < 100)
    {
        if (conter == 0){
            number++;
            printf("thread 2 : %d\n", number);
            conter = 1;
            i++;
        }  
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
