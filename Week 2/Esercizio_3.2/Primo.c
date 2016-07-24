#include <stdio.h>
#include <math.h>
int main(){
int M=2,N=4;
int i=0,j=0,k=0,l=0;
for (i=0;i<N;i++){
	for (k=0;k<M;k++){
		for (j=0;j<N;j++){
			if ((i+j)%2==0){
				for(l=0;l<M;l++){
					printf("x");
					}
				}
				else {
					for(l=0;l<M;l++){
					printf("-");
					}
				}
		}
	printf("\n");
	}
	
}
				

                    

return 0;}
