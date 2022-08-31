#include <stdio.h>
#include "vector.h"



int main(int argc,char **argv){

    // vectorCreate(Datatype,initial_size,factor)
    Vector newvec = vectorCreate(VINT,2,2);
    

    int var;
    while(1){
        scanf("%d",&var);
        if(var==-1){
            break;
        }
        // vectorPush(vector ref,var addr)
        vectorPush(&newvec,&var);
    }


    // vectorDisplay(vector ref)
    vectorDisplay(&newvec);

    // vectorDelete(vector ref)
    vectorDelete(&newvec);

    return 0;

}
