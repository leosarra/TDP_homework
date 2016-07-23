#include <stdio.h>
#include <stdlib.h>
#include "esercizio.h"
void ruota(TipoSCL* pscl, int k){
	TipoSCL nodo=(*pscl);
	TipoSCL nodo2;
	if(k==0 || *pscl==NULL || (*pscl)->next==NULL) return;
	int i;
	for(i=0;i<k-1;++i){
			nodo=nodo->next;
		}
	TipoSCL nodo3=nodo;
	nodo=nodo3->next;
	nodo3->next=NULL;
	nodo2=nodo;
		while(nodo!=NULL){
		nodo=nodo->next;
	}
	nodo->next=(*pscl);
	(*pscl)=nodo2;
}

