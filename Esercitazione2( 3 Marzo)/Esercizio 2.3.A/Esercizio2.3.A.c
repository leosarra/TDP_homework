#include <stdio.h>
int main(){
    int variabile;
    int conto=0;
    int counter=0;
    printf("Inserisci un valore per il lato del quadrato:   ");
    scanf("%d",&variabile);
    while (counter!=variabile){
        counter+=1;
        conto=0;
        printf("\n");
        while (conto!=variabile){
            printf("x");
            conto+=1;}
        }
    printf("\n");
    
    return 0;



}
