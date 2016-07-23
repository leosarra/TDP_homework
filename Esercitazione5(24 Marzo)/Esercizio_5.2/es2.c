#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double* q;
    q=(double *)malloc(5*sizeof(double));
    double* numero;
    numero=(double *)(q+1);
    double* howmany;
    howmany=(double *)(q);
    double* approx;
    approx=(double *)(q+3);
    double* betterapprox;
    betterapprox=(double *)(q+2);
    double* i;
    i=(double *)(q+4);
    printf("Inserire numero: ");
    scanf("%lf",numero);
    printf("Inserire n. ripetizioni: ");
    scanf("%lf",howmany);
    *(approx)=0.5*(*(numero));
    *(i)=0;
    for(;*(i)<*(q);*(i)+=1){
        *(betterapprox)=0.5*(*(approx)+(*(numero))/(*(approx)));
        *(approx)=*(betterapprox);
        }
    printf("La radice è:  %lf",*(approx));
return 0;		
	}
	
