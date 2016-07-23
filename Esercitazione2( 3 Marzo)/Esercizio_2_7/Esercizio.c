#include <stdio.h>
int main() {
	int lato;
	int counter=1;
	int addizione=1;
	int conto=0;
	int numero=1;
	printf("Inserisci lato del triangolo rettangolo:");
	scanf("%d",&lato);
	while (counter!=lato) {
		for (int conto=0;conto < addizione;conto+=1){
			printf("%d  ",numero);
			numero++;
			}
		counter+=1;
		addizione+=1;
		printf("\n");
		} 
	return 0;
		}
