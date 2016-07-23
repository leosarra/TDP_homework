#include <stdlib.h>
#include <stdio.h>

#include "esercizio3.h"
void aux(SparseVectorElement* output,SparseVectorElement* l1,SparseVectorElement* l2 );

SparseVectorElement* recursiveSum(SparseVectorElement* l1, SparseVectorElement* l2) {
  SparseVectorElement* lista=(SparseVectorElement*)malloc(sizeof(SparseVectorElement));
  lista->next=NULL;
  SparseVectorElement* start=lista;
  aux(lista,l1,l2);
  return start->next;
}

void aux(SparseVectorElement* output,SparseVectorElement* l1,SparseVectorElement* l2 ){
  if (l1==NULL && l2==NULL){
    return;
  }
  SparseVectorElement* backup=output;
  output->next=(SparseVectorElement*)malloc(sizeof(SparseVectorElement));
  output=output->next;
  output->next=NULL;

  if(l1 == NULL) {
    output->pos = l2->pos;
    output->value = l2->value;
    aux(output,NULL,l2->next);
  }
  else if(l2 == NULL) {
    output->pos = l1->pos;
    output->value = l1->value;
    aux(output,l1->next,NULL);
  }
  else if(l1->pos < l2->pos) {
    output->pos = l1->pos;
    output->value = l1->value;
    aux(output,l1->next,l2);
  } else if(l1->pos > l2->pos) {
    output->pos = l2->pos;
    output->value = l2->value;
    aux(output,l1,l2->next);
  } else {
    if(l1->value + l2->value != 0.0f) {
      output->pos = l1->pos;
      output->value = l1->value + l2->value;
      aux(output,l1->next,l2->next);
    } else {
      free(output);
      aux(backup,l1->next,l2->next);
    }
  }
}
