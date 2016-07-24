#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double* conversion;
    conversion=(double *)malloc(4*sizeof(double));
    double* a;
    double* b;
    double* ris;
    double* contatore;
    a=(double *)(conversion);
    b=(double *)(conversion+1);
    ris=(double *)(conversion+2);
    contatore=(double *)(conversion+3);
    printf("Inserisci il primo numero:  ");
    scanf("%lf",a);
    printf("Inserisci il secondo numero:  ");
    scanf("%lf",b);
    *ris=*a+*b;
    printf("\n");
    *contatore=1;
    while (*(b)!=0){
        printf("\n");
        printf("Inserisci il secondo numero:  ");
        scanf("%lf",b);
        *ris+=*b;
        printf("\n");
        printf("%lf",*ris);
        *contatore+=1;
        }
    if (*(b)==0){
        printf("\n");
        printf("Terminato");
        printf("\n");
        *ris=(*ris)/(*contatore);
        printf("La media aritmetica è : %f",*ris);
        
        
    
    
    
    
    
    
    
}
return 0;
}
