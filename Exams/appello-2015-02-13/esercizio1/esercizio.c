#include <stdio.h>
#include <stdlib.h>
#include "esercizio.h"

int* accumulaArray(char* nomefile, int* n){
	FILE* fp=fopen(nomefile,"r");
	int numero=0;
    int numero2;
	while(fscanf(fp,"%d",&numero2)!=EOF){
        printf("I valori trovati sono %d \n",numero);
		numero+=1;
	}
	fclose(fp);
	int* ritorno;
    int valore;
    printf("Il valore allocato è %d",numero);
	ritorno=(int*)malloc(sizeof(int)*numero);
	fp=fopen(nomefile,"r");
	for(int i=0;i<numero;i++){
		if (i==0){
			fscanf(fp,"%d",&ritorno[i]);
            printf("Ho inserito %d \n",ritorno[i]);
		}
		else{
			fscanf(fp,"%d",&valore);
			ritorno[i]=valore+ritorno[i-1];
            printf("Ho inserito %d \n",ritorno[i]);
		}
	}
	*n=numero;
	return ritorno;
}
