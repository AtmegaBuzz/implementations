#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int x = 0;

void* readr(){

    while(1){
        sleep(1);
        printf("Val of x is %d\n",x);
    }
    return NULL;
}

void* writer(){

    while(1){
        sleep(1);
        x++;
    }
    return NULL;
}

int main(){



    pthread_t t1, t2;

    pthread_create(&t1,NULL,&readr,NULL);
    pthread_create(&t2,NULL,&writer,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);


    return 0;
}