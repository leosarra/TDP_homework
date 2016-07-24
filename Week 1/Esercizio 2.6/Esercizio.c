#include <stdio.h>
#include <math.h>
int main() {
    int lunghezza;
    int cifra;
    float base=2;
    float exponential;
    float somma=0,risultato;
    float esponente=0;
    int controllo=0;
    printf("Inserire lunghezza numero in binario: ");
    scanf("%d",&lunghezza);
    for (int counter = 0; counter < lunghezza; counter++){
        printf("Inserire cifra n.%d:  ",counter);
        
        scanf("%d",&cifra);
        if (cifra>1){
            printf("Valore non corretto... \n");
            controllo=1;
            break;
            }
        exponential=powf(base,esponente);
        risultato=cifra*(exponential);
         printf("\n");
        somma+=risultato;
         printf("\n");
        esponente++; }
    if (controllo==0){
    printf("Il risultato è %f",somma);
    }
    return 0;
    
        
        
        
    
    
    
    
    }

