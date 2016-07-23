#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
int i=100,j=200;
int* c;
c=(int *)malloc(1*sizeof(int));
c=&i;
int* d;
d=(int *)malloc(1*sizeof(int));
d=&j;
double dif;
dif=(c-d);
printf("%p e %p",c,d);
 printf("\n");
printf("%lf",dif);
 printf("\n");
c=d;
printf("%p e %p",c,d);
 printf("\n");

return 0;		
}
