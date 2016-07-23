#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mat.h"

// Data in input una lista di caratteri list , e due caratteri new e old, aggiornare tutti gli
// elementi di list contenenti il carattere old con il carattere new.
void str_update(TipoSCL list, char new, char old)
{
    TipoSCL p0=list;
    while (p0!=NULL){
        if (p0->c==old){
            p0->c=new;}
        p0=p0->next;
        
        }
}

// Data in input una matrice di interi rappresentata nella struttura Mat e un valore intero value, 
// creare e restituire un vettore contenente gli indici lineari
// di tutti gli elementi di mat che sono maggiori di value. Si ricorda che
// l'indice lineare di un elemento (r, c) di una matrice di dimensione
// rows x cols e' uguale a r * cols + c. La funzione deve scrivere la 
// dimensione del vettore di output nel parametro n.
int* mat_find(Mat *mat, int value, int *n){
    *n=0; 
    int grandezza=0;
//HO USATO PRIMA UNA MATRICE PER TROVARE LA DIMENSIONE DEL VETTORE PER ALLOCARLO POI USANDO UN "FOR"
// SIMILE SONO ANDATO A METTERE I VALORI DENTRO IL VETTORE
    for (int i=0;i<mat->rows;i++){
        for (int j=0;j<mat->cols;j++){
            if (mat->row_ptrs[i][j]>value){
                grandezza++;
                *n=*n+1;
                 printf("I valori di righe e colonne %d e %d e grandezza del vettore %d \n", i,j, *n);
                }
        }
    }
    
    int* ris=(int *)malloc(sizeof(int)*(*n));
    grandezza=0;
    for (int i=0;i<mat->rows;i++){
        for (int j=0;j<mat->cols;j++){
            if (mat->row_ptrs[i][j]>value){
                ris[grandezza]=i*(mat->cols) + j;
                grandezza++;
                }
        }
    }


printf("la grandezza è %d \n",*n);
    return ris;
}

// Dato in input un vettore v di dimensione n e un intero value, scrivere
// ricorsivamente zero in tutti gli elementi di v che sono minori di value. 
void vec_wipe(int *v, int n, int value) 
{
    if (n==0){
        printf("Stringa finita");
        }
    else {
        if (v[0]<value){
            v[0]=0;}
    vec_wipe(v+1,n-1,value);
    }
    
}


