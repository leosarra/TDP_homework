#include "esercizio.h"
int diagonalePrincipale2(int** mat,int n,int somma){
	if(n==1){
		somma+=mat[0][0];
		return somma;
	}
	else{
		somma+=mat[n-1][n-1];
		return diagonalePrincipale2(mat,n-1,somma);
	}
}
int diagonalePrincipale(int** mat, int n){
	return diagonalePrincipale2(mat,n,0);
}
