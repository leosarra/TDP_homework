#include <stdlib.h>

#include "esercizio2.h"

TipoSCL fetch_elements(TipoSCL l, char* v, int v_dim) {
  TipoSCL generator_node = (TipoSCL)malloc(sizeof(NodoSCL));
  generator_node->next = NULL;

  TipoSCL it = generator_node;
  while(l != NULL) {
    if(l->i < v_dim) {
    it->next = (TipoSCL)malloc(sizeof(NodoSCL));
    it = it->next;
    it->i = l->i;
    it->c = v[l->i];
    it->next=NULL;
    }
    l = l->next;
  }

  it = generator_node->next;
  free(generator_node);
  return it;
}
