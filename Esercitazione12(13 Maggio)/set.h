#ifndef SET_H
#define SET_H

struct SetElem {
  int info;
  struct SetElem *next;
};
typedef struct SetElem SetElem;

SetElem* set_load(char *filename);
SetElem* set_alloc();
void     set_free(SetElem *set);

// Funzioni da svolgere come esercizio nel file esercizi.c

void set_print(SetElem *set);

int is_empty(SetElem *set);

int is_element(SetElem *set, int info);

int is_set(SetElem *set); 

int is_subset(SetElem *sub, SetElem *set);

void set_add(SetElem **set, int info);

void set_del(SetElem **set, int info);

void set_union(SetElem *src, SetElem **dest);

void set_difference(SetElem *src, SetElem **dest);

#endif
