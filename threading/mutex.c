#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int x = 0;
pthread_mutex_t mutex;

void* writet1(){


    for(int i=0;i<100000000;i++){
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
}



int main(){

    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&t1,NULL,&writet1,NULL);
    pthread_create(&t2,NULL,&writet1,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);


    printf("%d\n",x);
    pthread_mutex_destroy(&mutex);

    return 0;
}