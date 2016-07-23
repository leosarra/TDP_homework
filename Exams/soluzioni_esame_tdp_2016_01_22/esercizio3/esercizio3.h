#ifndef _ESERCIZIO3_H_
#define _ESERCIZIO3_H_

struct NodoSCL {
  int i;
  char c;
  struct NodoSCL* next;
};
typedef NodoSCL* TipoSCL;

int count_vowels(TipoSCL l);

#endif
