#include <stdlib.h>
#include <stdio.h>
#include "esercizio1.h"
int pop(TipoSCL lista,int info){
    TipoSCL precedente=lista;
    while (lista->next!=NULL){
        if (lista->info==info){
            TipoSCL temp=lista;
            precedente->next=lista->next;
            free(temp);
            return 1;
            }
        else{
            if(lista->next!=NULL){
            precedente=lista;}
            lista=lista->next;
            }
        }
    if (lista->info==info){
        TipoSCL tempo=lista;
        precedente->next=NULL;
        free(tempo);
        return 1;}

    else{ return 0;}
    }

int delete_occurrences(TipoSCL* scl, int info) {
    int numero=0;
    if ((*scl)==NULL || scl==NULL){
        return 0;
        }
    if ((*scl)->info==info && (*scl)->next==NULL){
        free(*scl);
        (*scl)=NULL;
        return 1;

    }
    TipoSCL temporaneo;
    while ((*scl)->info==info){
        temporaneo=(*scl);
        (*scl)=(*scl)->next;
        free(temporaneo);
        numero++;

    }
    int controllo=-1;
    while (controllo!=0){
        controllo=pop((*scl),info);
        if (controllo!=0){
            numero++;}}



    return numero;
}
