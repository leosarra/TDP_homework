#ifndef _ESERCIZIO1_H_
#define _ESERCIZIO1_H_

struct ElemSCL{
  int info;
  struct ElemSCL* next;
};
typedef struct ElemSCL NodoSCL;
typedef NodoSCL* TipoSCL;

int delete_occurrences(TipoSCL* scl, int info);

#endif
