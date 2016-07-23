#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "esercizio1.h"

int insert_word(char* word, char** m, int m_rows, int m_cols,
		int row, int col, int direction) {

			int lunghezza=strlen(word);
			if(row>m_rows||col>m_cols||row<0||col<0){return 0;}
			if (direction==1 && row+lunghezza>m_rows){return 0;}
			if (direction==0 && col+lunghezza>m_cols){return 0;}
			int r=row,c=col;
			for (int i=0;i<lunghezza;i++){
				if(m[r][c]!=word[i] && m[r][c]!='_'){return 0;}
				if (direction==1){r++;}
				else{c++;}
			}
			if(r<m_rows && c<m_cols){
				if (m[r][c]=='_'){
					return 0;
				}
			}

			r=row;
			c=col;
			for (int i=0;i<lunghezza;i++){
				m[r][c]=word[i];
				if (direction==1){r++;}
				else{c++;}
			}


			return 1;
		}
