#ifndef LIST_H
#define LIST_H

struct NodoSCL {
  char c;
  struct NodoSCL *next;
};
typedef struct NodoSCL NodoSCL;
typedef NodoSCL* TipoSCL;

void    TipoSCL_print(TipoSCL l);
TipoSCL TipoSCL_load(char* filename);
TipoSCL TipoSCL_alloc();
void    TipoSCL_free(TipoSCL l);

#endif
