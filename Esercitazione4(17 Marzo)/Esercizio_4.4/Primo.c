#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
double* x;
x=(double *)malloc(1*sizeof(double));
char* temp;
temp=(char *)malloc(1*sizeof(char));
double* first_conversion;
first_conversion=(double *)malloc(1*sizeof(double));
double* second_conversion;
second_conversion=(double *)malloc(1*sizeof(double));

printf("Inserire scala:");
scanf("%c",temp);
printf("Inserire valore");
scanf("%lf",x);

if (*temp=='C'){    
    *first_conversion= *x + 273.15;
    printf("In k è %f \n",*first_conversion);
    *second_conversion= (*x)*(9/5) + 32;
    printf("In F è %f \n",*second_conversion);
    free(temp);
    free(x);
    free(first_conversion);
    free(second_conversion);
    }
else if (*temp=='K'){
    *first_conversion= *x - 273.15;
    printf("In c è %f \n",*first_conversion);
    *second_conversion= (*first_conversion)*(9/5) + 32;
    printf("In F è %f \n",*second_conversion);
    free(temp);
    free(x);
    free(first_conversion);
    free(second_conversion);
    }

else if (*temp=='F'){
    *first_conversion= (*x - 32)/(9/5);
    printf("In C è %f \n",*first_conversion);
    *second_conversion= *first_conversion+273.15;
    printf("In K è %f \n",*second_conversion);
    free(temp);
    free(x);
    free(first_conversion);
    free(second_conversion);}
return 0;		
}
