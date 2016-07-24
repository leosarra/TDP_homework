#include <stdio.h>
#include <math.h>
int main(){
    int variabile;
    int counter=0;
    printf("Inserisci lato quadrato");
    scanf("%d",&variabile);
    while (counter!=variabile){
        if ((counter==0)||(counter==variabile-1)){
            for (int counter = 0; counter < variabile; counter++){
                printf("x");}
                printf("\n");}
                
        else {
            printf("x");
            for (int counter = 0; counter < variabile-2; counter++){
                printf(" ");}
                printf("x");
                printf("\n");
            }
        counter+=1;

            
    

            }
    return 0;
}
