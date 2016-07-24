#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
int* x;
x=(int *)malloc(5*sizeof(int));
int* check;
int* numero;
numero=(int *)(x);
check=(int *)(x+1);
*check=0;
int* q;
q=(int *)(x+2);
printf("Inserire numero (inserire 0 per terminare)");
scanf("%d",numero);
while ((*numero)!=0){
    if (*check==0){
        *q=*x;
        }
    else {
        printf("\n");
        int* p;
        p=(int *)(x+3);
        *p=*x;
        if (*p<*q){
            *q=*p;
            }
        }
    *check=1;
    
    scanf("%d",numero);
    }
    printf("Il numero più piccolo è: %d",*q);

    
return 0;		
}
