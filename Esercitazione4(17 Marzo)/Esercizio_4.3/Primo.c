#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
int* x;
x=(int *)malloc(1*sizeof(int));
int* check;
check=(int *)malloc(1*sizeof(int));
*check=0;


int* q;
q=(int *)malloc(1*sizeof(int));
printf("Inserire numeri separati da spazi");
scanf("%d",x);
while (*x!=0){
    if (*check==0){
        *q=*x;
        }
    else {
        printf("\n");
        int* p;
        p=(int *)malloc(1*sizeof(int));
        *p=*x;
        if (*p<*q){
            *q=*p;
            }
        free(p);
        }
    *check=1;
    scanf("%d",x);
    }
    printf("%d",*q);
    free(x);
    free(check);
    
return 0;		
}
