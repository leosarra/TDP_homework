#ifndef _LIST_TYPE_H_
#define _LIST_TYPE_H_

struct NodoSCL {
  int info;
  struct NodoSCL* next;
};
typedef struct NodoSCL NodoSCL;
typedef NodoSCL* TipoSCL;

#endif
