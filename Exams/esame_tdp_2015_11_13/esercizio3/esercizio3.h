#ifndef _ESERCIZIO3_H_
#define _ESERCIZIO3_H_

struct NodoSCL {
  int info;
  struct NodoSCL* next;
};
typedef NodoSCL* TipoSCL;

int* integralVector(int* length, TipoSCL src);

#endif
