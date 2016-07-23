#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void stampaAsterischi(int n, int fill){
    if (fill>=0){
        for (int i=0;i<n;i++){ //primo caso
            printf("*");
            }
        }
    else {
        printf("*");
        for (int i=0;i<(n-2);i++){ //secondo caso
            printf(" ");
            }
        printf("*");
        }
    }
    
int main(){
int variabile;
    int counter=0;
int fill;
    printf("Inserisci lato quadrato");
    scanf("%d",&variabile);
    while (counter!=variabile){
        if ((counter==0)||(counter==variabile-1)){
            fill=1;
            stampaAsterischi(variabile,fill);
            printf("\n");
            }
                
        else {
            fill=-1;
            stampaAsterischi(variabile,fill);
            printf("\n");
            }
        counter+=1;

            
    

    }
    return 0;
}
