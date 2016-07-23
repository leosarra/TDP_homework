#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
Esercizio 1:
Realizzare una funzione che, dati due array A e B di caratteri, di dimensioni n, rispettivamente, restituisce un nuovo array C di dimensione 2n contenente la concatenazione degli elementi contenuti in A e in B alternando gli elementi come segue: A[0] B[0] A[1] B[1] ...
Il nuovo array C deve essere opportunamente allocato in memoria all'interno della funzione.
*/


void esercizio1(char *A, char *B, int n, char **C) {
int j=0;
     (*C)=(char *)calloc(2*n,sizeof(char));
for (int i=0;i<(2*n);i+=2){

    (*C)[i]=A[j];
    (*C)[i+1]=B[j];
    j++;
    printf("%d",i);
    
    }
}

/*
Esercizio 2:
Realizzare una funzione che, data una matrice quadrata di float mat e le sue dimensioni n, restituisca il massimo valore contenuto nella diagonale principale come valore di ritorno della funzione e la sua posizione (indici di riga e di colonna) nei parametri di output r e c.
*/

float esercizio2(float **mat, int n, int *r, int *c) {
    float massimo;
    massimo=mat[0][0];
    int i=0;
	for (int j=0;j<n;j++){
        if (mat[i][j]>massimo){
            *r=i;
            *c=j;
            massimo=mat[i][j];
            
        }
    i++;
    }

return massimo;
}
