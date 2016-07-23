#include <stdio.h>
#include <math.h>

int main(){
char uno;
int due;
long tre;
short quattro;
float cinque;
double sei;

printf("L'int ha indirizzo %p e %lu byte \n ",&due,sizeof(int));
printf("Il char ha indirizzo %p e %lu byte \n",&uno,sizeof(char));
printf("Il long ha indirizzo %p e %lu byte \n",&tre,sizeof(long));
printf("Lo short  ha indirizzo %p  e %lu byte \n",&quattro,sizeof(short));
printf("Il float  ha indirizzo %p  e %lu byte \n",&cinque,sizeof(float));
printf("Il double  ha indirizzo %p e %lu byte \n",&sei,sizeof(double));
return 0;		
	}
