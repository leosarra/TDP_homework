#include "set.h"

#include <stdio.h>
#include <stdlib.h>

SetElem* set_load(char *filename) {
  FILE *f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  int info;
  SetElem *gen_node = set_alloc();
  gen_node->next = NULL;
  SetElem *set = gen_node;
  while(fscanf(f, "%d", &info) == 1) {
    set->next = set_alloc();
    set = set->next;
    set->info = info;
    set->next = NULL;
  }
  set = gen_node->next;
  free(gen_node);

  return set;
}

SetElem* set_alloc() {
  return (SetElem*)malloc(sizeof(SetElem));
}

void set_free(SetElem *set) {
  while(set != NULL) {
    SetElem* tmp = set;
    set = set->next;
    free(tmp);
  }
}
