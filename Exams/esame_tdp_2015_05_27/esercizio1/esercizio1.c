#include <stdlib.h>
#include <stdio.h>
#include "esercizio1.h"

int delete_occurrences(TipoSCL* scl, int info) {
TipoSCL* lista=(TipoSCL*)malloc(sizeof(TipoSCL));
lista->next=NULL;
TipoSCL* start=lista;
TipoSCL* precedente;
int numero=0;
while(scl==NULL){
  lista->next=(TipoSCL*)malloc(sizeof(TipoSCL));
  precedente=lista;
  lista=lista->next;
  lista->next=NULL;
  if (scl->info!=info){
    lista->info=scl->info;
    }
  else{
    numero++;
    lista=precedente;
    lista->next=NULL;
  }

}
scl=start->next;
free(start);
}
