#ifndef _ESERCIZIO2_H_
#define _ESERCIZIO2_H_

struct NodoSCL {
  int i;
  char c;
  struct NodoSCL* next;
};
typedef NodoSCL* TipoSCL;

TipoSCL fetch_elements(TipoSCL l, char* v, int v_dim);

#endif
