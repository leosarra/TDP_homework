#include <stdio.h>
#include <math.h>
int main(){
	int primo,secondo,terzo;
	printf("Inserire numero");
	scanf("%d",&primo);
	while (primo!=0){
	printf("Inserire numero in ciclo");
	scanf ("%d",&secondo);
	if (secondo==0){
	break;}
	else if (secondo>primo){
	primo=secondo;}
	else if (secondo>primo){
	continue;}}
	if (0>primo) {
	primo=0;}
	printf("Il numero più grande è %d",primo);

return 0;		
	}
