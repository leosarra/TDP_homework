#include <stdio.h>
#include <stdlib.h>
#include "esercizio.h"

int* sommaColonne(int** mat, int n, int m){
	int* array=(int*)malloc(sizeof(int)*m);
	int i=0;
	int riga=0;
	while(i<m){
		array[i]=0;
		while(riga<n){
			array[i]+=(mat[riga][i]);
			printf("Inserisco il valore %d \n",mat[riga][i]);
			riga++;
		}
		riga=0;
		i++;
	}
	return array;
}
