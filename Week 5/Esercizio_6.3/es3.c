#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void stampaAsterischi(int n){
        for (int i=0;i<n;i++){
            printf("*");
            }
        }
    

int main(){
int n;
printf("Inserire numeri separati da spazi:   ");
scanf("%d",&n);
while (n!=0){
stampaAsterischi(n);
    printf("\n");
    scanf("%d",&n);
    }
return 0;		
	}

