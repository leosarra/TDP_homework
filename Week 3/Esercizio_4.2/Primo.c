#include <stdio.h>
#include <math.h>

int main(){
int i = 100; 
int j = 200; 
int check=0;
char *p, *q;
while (check<sizeof(int)){
p=(char*)&i;
q=(char*)&j;
*q=*p;
p++;
q++;
check++;
}



// Inserire codice qui senza (senza j = ...)
printf("%d == %d\n", i, j); 
return 0;		
	}
