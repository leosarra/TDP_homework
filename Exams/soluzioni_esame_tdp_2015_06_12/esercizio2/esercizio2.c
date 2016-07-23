#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "esercizio2.h"

int add_word(TipoSCL* array, int dim, char* word) {
  int len=strlen(word);
  if (len>dim){return 0;}
  if (len==0){return 0;}
  TipoSCL lista=array[len-1];
  if (lista==NULL){
    lista=(TipoSCL)malloc(sizeof(NodoSCL));
    array[len-1]=lista;
    lista->info=word;
    lista->next=NULL;
    return 1;
  }
  while(lista->next!=NULL){
    lista=lista->next;
  }
  lista->next=(TipoSCL)malloc(sizeof(NodoSCL));
  lista->next->info=word;
  lista->next->next=NULL;
  return 1;
  }
