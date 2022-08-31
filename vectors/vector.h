#ifndef VECTOR_H
#define VECTOR_H

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

int vectorPush(Vector *vec,void* elem);

int vectorDelete(Vector *vec);

void vectorDisplay(Vector *vec);

#endif