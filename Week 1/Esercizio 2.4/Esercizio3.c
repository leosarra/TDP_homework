#include <stdio.h>
#include <math.h>
int main(){
    int numero,ris;
    int counter=0;
    int a=1;
    int b=1;
    scanf("%d",&numero);
        printf("%d,",a);
        while (counter!=numero){
            ris=a+b;
            b=a;
            printf("%d,",ris);
            a=ris;
            //printf(" A è %d",ris);
            
            counter+=1;
            }
        
    
    
    

    return 0;
    
    
    
    
    
    
}
