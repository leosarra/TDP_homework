#ifndef ESERCIZIO_H
#define ESERCIZIO_H

struct ElemSCL{
    int info;
    struct ElemSCL* next;
};
typedef struct ElemSCL NodoSCL;
typedef NodoSCL* TipoSCL;

void accoda(TipoSCL* pscl, int i);

#endif
