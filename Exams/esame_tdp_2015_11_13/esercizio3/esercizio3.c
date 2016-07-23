#include <stdlib.h>
#include <stdio.h>

#include "esercizio3.h"
int lunghezza(TipoSCL src);
void aux(int* array,TipoSCL src, int length,int index,int first);



int* integralVector(int   *length, TipoSCL src) {
	if(src==NULL){
			*length=0;
			return NULL;
			}
	*length=lunghezza(src);
	int* array=(int*)malloc(sizeof(int)*(*length));
	aux(array,src,*length,0,1);
	return array;
}

void aux(int* array,TipoSCL src, int length,int index,int first){
	if (index==length){
		printf("Termino");
		}
	else if (first){
		array[index]=src->info;
		aux(array,src->next,length,index+1,0);
	}
	else if (first==0){
		array[index]=src->info + array[index-1];
		aux(array,src->next,length,index+1,0);
	}
}

int lunghezza(TipoSCL src){
    if (src->next!=NULL){
        return 1 + lunghezza(src->next);
    }
    else{return 1;}
}
