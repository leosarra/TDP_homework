#include "esercizio3.h"
#include <stdlib.h>
#include <stdio.h>


int lunghezza(TipoSCL src){
    if (src->next!=NULL){
        return 1 + lunghezza(src->next);
    }
    else{return 1;}
}
    
void aux(int index, TipoSCL src, int* array){
    if(src->next!=NULL){
        if (index==0){
            array[0]=src->info;
            aux(1, src->next, array+1);}
         else {
            array[0]=src->info + (array-1)[0];
            aux(1, src->next, array+1);}
    }
    else{
        array[0]=src->info + (array-1)[0];
        }
}

int* integralVector(int* length, TipoSCL src) {
    TipoSCL test=src;
    if(src==NULL){
        *length=0;
        return NULL;
        }
    int ris=lunghezza(test);
    *length=ris;
    int* array=(int*)malloc(sizeof(int)*ris);
    int index=0;
    aux(index, src, array);
    return array;
}





