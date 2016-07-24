#include <stdio.h>
#include <math.h>

int main(){
 unsigned char b,ris5;
 short s;
 int i,ris2,ris7;
 long l,ris;
 float f,ris4;
 double d,ris3,ris6;
 char c;
 ris=b+10*(l);
 printf("%ld",ris);
 ris2=(b+i)*i;
 printf("%d",ris2);
 ris3=(b+i)*l+f;
 printf("%f",ris3);
 ris4= s/f + sin(f);
 printf("%f",ris4);
 ris5= c == 'b';
 printf("%d",ris5);
ris6=l+1.5f;
printf("%f",ris6);
ris7=i<10;
printf("%d",ris7);
return 0;		
	}
