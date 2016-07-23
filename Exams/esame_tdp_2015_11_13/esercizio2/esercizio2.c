#include <stdlib.h>
#include <stdio.h>
#include "esercizio2.h"

TipoSCL lowerValues(Mat* m, float value) {
	int  row= m->rows;
	int col=m->cols;
	TipoSCL risultato=(TipoSCL)malloc(sizeof(NodoSCL));
	risultato->next=NULL;
	TipoSCL start=risultato;
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(m->row_ptrs[i][j]<value){
			risultato->next=(TipoSCL)malloc(sizeof(NodoSCL));
			risultato=risultato->next;
			risultato->next=NULL;
			risultato->v=m->row_ptrs[i][j];
			risultato->row=i;
			risultato->col=j;
		}
		}
		}
	TipoSCL finale=start->next;
	return finale;
}
