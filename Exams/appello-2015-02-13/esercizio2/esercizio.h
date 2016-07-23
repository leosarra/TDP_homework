#ifndef ESERCIZIO_H
#define ESERCIZIO_H

struct ElemSCL{
    int info;
    struct ElemSCL* next;
};
typedef struct ElemSCL NodoSCL;
typedef NodoSCL* TipoSCL;

void ruota(TipoSCL* pscl, int k);

#endif
