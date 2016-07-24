#include <stdio.h>
#include <math.h>
int main(){
    double n=2;
    int howmany=10;
    double betterapprox,approx;
    approx=0.5*n;
    for(int i=0;i<howmany;i++){
        betterapprox=0.5*(approx+n/approx);
        approx=betterapprox;
        }
    printf("%f",approx);
return 0;		
	}
	
