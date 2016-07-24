#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* allocaEdInizializza(int n, int valore){
    int* allocazione;
    allocazione=(int *)malloc(n*sizeof(int));
    *allocazione=valore;
    return allocazione;
    }
    
int main(){
    int n,valore;
    int* puntatore;
    int* risultato;
    printf("Inserire valore di n:  ");
    scanf("%d",&n);
    printf("Inserire il valore:  ");
    scanf("%d",&valore);
    risultato=(int *)malloc(n*sizeof(int));
    puntatore=allocaEdInizializza(n,valore);
    for (int i=0;i<n;i++){
        risultato=puntatore+i;
        printf("La cella di memoria è :  %p \n",risultato);
        }
    free(puntatore);
    return 0;
}
