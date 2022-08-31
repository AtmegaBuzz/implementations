// simple implementation of vectors in c  
#include <stdio.h>
#include <stdlib.h>


typedef enum {VINT,VFLOAT,VCHAR} VType;


typedef struct{
    VType type;
    void* arr;
    int factor;
    int totalSize; // total size of array
    int size; // no of elements
} Vector;


Vector vectorCreate(VType type,int init_size,int factor);

int vectorResize(Vector *vec);
int vectorPushInt(Vector *vec,int elem);
int vectorPushFloat(Vector *vec,float elem);
int vectorPushChar(Vector *vec,char elem);
int vectorPush(Vector *vec,void* elem);
int vectorDelete(Vector *vec);
void vectorDisplay(Vector *vec);


Vector vectorCreate(VType type,int init_size,int factor){
    
    if (&init_size==NULL) init_size=1;
    if (&factor==NULL) factor = 2;

    Vector vec;
    void *DArr;

    vec.type = type;
    vec.totalSize = init_size;
    vec.size = 0; // curren size of array
    vec.factor = 2; // double the array on full space
    

    switch (type){

        case VINT:
            DArr = calloc(init_size,sizeof(int)); 
            break;
            
        case VFLOAT:
            DArr = calloc(init_size,sizeof(float)); 
            break;

        case VCHAR:
            DArr = calloc(init_size,sizeof(char)); 
            break;

        default:
            perror("invalid type passed");
            exit(1);
    }

    if (DArr==NULL){
        perror("Allocation Falied");
        exit(1);
    }

    vec.arr = DArr;
    return vec;
}

int vectorPushInt(Vector *vec,int elem){

    int *arr = (int*)vec->arr;
    arr[vec->size] = elem;

    return 0;
}

int vectorPushFloat(Vector *vec,float elem){

    float *arr = (float*)vec->arr;
    arr[vec->size+1] = elem;

    return 0;
}

int vectorPushChar(Vector *vec,char elem){
    
    char *arr = (char*)vec->arr;
    arr[vec->size+1] = elem;

    return 0;
}


int vectorResize(Vector *vec){
    vec->arr = realloc(vec->arr,sizeof(void *)*(vec->factor*vec->totalSize)); 
    vec->totalSize = (vec->factor*vec->totalSize);
    return 0;
}

int vectorPush(Vector *vec,void* elem){

    VType type = vec->type;

    if(vec->size==vec->totalSize){
        // if size is full then realloc
        vec->arr = realloc(vec->arr,sizeof(void *)*(vec->factor*vec->totalSize)); 
        vec->totalSize = (vec->factor*vec->totalSize);
    }

    if (type==VINT){
        vectorPushInt(vec,*((int*)elem));
    }

    else if (type==VFLOAT){
        vectorPushFloat(vec,*((float*)elem));
    }

    else if (type==VCHAR){
        vectorPushChar(vec,*((char*)elem));
    }

    vec->size +=1;

    return 0;
}


void vectorDisplay(Vector *vec){

    int len = vec->size;

    for(int i=0;i<len;i++){
        printf("%d\n",((int*)vec->arr)[i]);
    }

}

int vectorDelete(Vector *vec){
    
    vec->factor = 0;
    vec->size = 0;
    vec->totalSize = 0;
    // vec->type = NULL;
    free(vec->arr);

    return 0; // success
}

