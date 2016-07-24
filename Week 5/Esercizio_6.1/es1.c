#include <stdio.h>
#include <stdlib.h>

void scambia(int *a, int *b){
    int* scambio;
    int valore;
    scambio=&valore;
    *scambio=*a;
    *a=*b;
    *b=*scambio;
    }
int main(){
    int* a;
    int* b;
    int valore1;
    int valore2;
    a=&valore1;
    b=&valore2;
    *a=10;
    *b=20;
    scambia(a,b);
    printf("%d,%d",*a,*b);
    return 0;
    
    
    
    
    
    
    }

