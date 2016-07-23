#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    double* p_mem=(double*)malloc(sizeof(double)*3+sizeof(char));
    double* val;
    char* chr;
    val=p_mem;
    chr=(char*)(val+1);
    printf("Inserire la lettera e poi il valore; ");
    scanf("%c",chr);
    scanf("%lf",val);
    printf("%lf",*val);
    printf("%c",*chr);
    /* *if (*chr=='C') IN QUESTA PARTE INSERIRE LE FORMULE PER LE CONVERSIONI DI F C e K
    {
        printf("Valore di K: %lf\n",*val+273.15);
    } */
	return 0;
}
