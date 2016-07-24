#include <stdio.h>
#include <math.h>
int main(){
	float a,b;
	float soluzione;
	printf("Inserire la ""a""\n");
	scanf("%f",&a);
	printf("Inserire la ""b""\n");
	scanf("%f",&b);
	printf("L'equzione è (%f)x + (%f)=0 \n",a,b);
	if (a==0){
		printf("Nessuna soluzione trovata \n");}
	else {
		soluzione= (-b)/a;
		printf("La soluzione è: %f",soluzione);}
return 0;		
	}
	
