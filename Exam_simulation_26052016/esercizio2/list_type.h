#ifndef _LIST_TYPE_H_
#define _LIST_TYPE_H_

struct NodoSCL {
  float v;
  int row;
  int col;
  struct NodoSCL* next;
};
typedef struct NodoSCL NodoSCL;
typedef NodoSCL* TipoSCL;

#endif
