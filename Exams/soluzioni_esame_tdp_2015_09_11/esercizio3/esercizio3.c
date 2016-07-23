#include <stdlib.h>
#include <stdio.h>
#include "esercizio3.h"

void aux(TipoSCL output,TipoSCL l1, TipoSCL l2){
  if (l1==NULL || l2==NULL){
    return;
  }
output->next=(TipoSCL)malloc(sizeof(NodoSCL));
output=output->next;
output->next=NULL;
if (l1->info <= l2->info){
  output->info=l1->info;
}
else if (l1->info > l2->info){
  output->info=l2->info;}
aux(output,l1->next,l2->next);

}

TipoSCL minElements(TipoSCL l1, TipoSCL l2) {
  TipoSCL gen_node=(TipoSCL)malloc(sizeof(NodoSCL));
  gen_node->next=NULL;
  aux(gen_node,l1,l2);
  return gen_node->next;
}
