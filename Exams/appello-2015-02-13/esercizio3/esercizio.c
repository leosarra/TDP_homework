#include "esercizio.h"
	int diagonalePrincipale2(int** mat,int n){
		if(n==0){return mat[n][n];}
		else{return mat[n][n] + diagonalePrincipale2(mat,n-1);}
		}

int diagonalePrincipale(int** mat, int n){
	if (n==1){return mat[0][0];}
	int valore=diagonalePrincipale2(mat,n-1);
	return valore;
}
