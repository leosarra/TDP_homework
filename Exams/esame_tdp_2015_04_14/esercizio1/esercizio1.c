#include "esercizio1.h"
#include <stdlib.h>
#include <stdio.h>
int isquare(int square_value,int square_size, int** matrix, int m_rows, int m_cols, int m, int c){
		if (square_size==1){
			if (matrix[m][c]==square_value){
					return 1;}
				else{return 0;}
		}
		else{
			if (m+square_size>m_rows){return 0;}
			if (c+square_size>m_cols){return 0;}
			for (int i=m;i<m+square_size-1;i++){
					for (int j=c;j<c+square_size-1;j++){
						if(matrix[i][j]!=square_value){
							return 0;
							}

						}

					}
				}
		return 1;
}


void findSquare(int* square_row, int* square_col,
		int** m, int m_rows, int m_cols,

		int square_size, int square_value) {
				int risultato;
				int trovato=0;
			for (int i=0;i<m_rows;i++){
					for (int j=0;j<m_cols;j++){
						risultato=isquare(square_value,square_size,m,m_rows,m_cols,i,j);
						if (risultato==1 && trovato!=1){
							*square_row=i;
							*square_col=j;
							trovato=1;

						}
					}
			}

			if (trovato==0){
				*square_row=-1;
				*square_col=-1;

			}
}
