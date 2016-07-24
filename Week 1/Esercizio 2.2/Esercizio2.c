#include <stdio.h>
#include <math.h>
int main(){
    float a,b;
    double ris;
    printf("Inserisci il primo numero");
    scanf("%f",&a);
    scanf("%f",&b);
    ris=(a+b)/2;
    printf("%f",ris);
    while (b!=0){
        printf("Inserisci il secondo numero");
        scanf("%f",&b);
        ris=(ris+b)/2;
        printf("%f",ris);
        }
    if (b==0){
        printf("Terminato");
        printf("%f",ris);
        
    
    
    
    
    
    
    
}
return 0;
}
