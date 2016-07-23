#include <stdio.h>
#include <math.h>
int main(){
int RADIUS=8;
for (int i = RADIUS*(-1); i <=RADIUS; i++)
{
    for (int j=RADIUS*(-1);j<=RADIUS; j++){
         if (i*i+j*j>RADIUS*RADIUS){
               printf(" ");
          } else{
               printf("x");
          }


          }                printf("\n");
    }


return 0;		
	}
