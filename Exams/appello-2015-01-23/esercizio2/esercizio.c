#include <stdio.h>
#include <stdlib.h>
#include "esercizio.h"

void accoda(TipoSCL* pscl, int i){
  if (*pscl==NULL){
    (*pscl)=(TipoSCL)malloc(sizeof(NodoSCL));
    (*pscl)->info=i;;
    (*pscl)->next=*pscl;
  }
  else{
  TipoSCL lista=*pscl;
  TipoSCL start=lista;
  while (lista->next!=start){
    lista=lista->next;
    }
  lista->next=(TipoSCL)malloc(sizeof(NodoSCL));
  lista->next->info=i;
  lista->next->next=start;
  }
}
