#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int risolviEquazione(float *x1, float *x2, float a, float b, float c){
double det;
det=(b*b-4*a*c);
det=sqrt(det);
printf("%lf             \n",det);
if (det==0){
    *x1=(-b+det)/(2*a);
    printf("%f",*x1);
    *x2=(-b-det)/(2*a);
    printf("%f",*x2);
    return 0;}
if (det>0){
    *x1=(-b+det)/(2*a);
    *x2=(-b-det)/(2*a);
    return 1;}
else {
    return -1;}
    }
int main(){
    float a,b,c;
    float* x1;
    float* x2;
    int risultato;
    a=1;
    b=2;
    c=-3;
    x1=(float *)malloc(sizeof(double));
    x2=(float *)malloc(sizeof(double));
    risultato=risolviEquazione(x1,x2,a,b,c);
    printf(" Il valore return è %d  \n ",risultato);
    if (risultato==-1){
            printf("nessuna radice \n");
            }
    if (risultato==0){
            printf(" La radice è  %f \n",*x1);
            }
    if (risultato==1){
            printf(" Le radici sono %f e %f \n",*x1,*x2);

        }
    return 0;
    }
