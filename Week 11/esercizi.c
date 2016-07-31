#include "set.h"

#include <stdio.h>
#include <stdlib.h>

// Data una rappresentazione degli insiemi mediante SCL
// (vedi definizione nel file set.h), implementare le seguenti funzioni
// con side-effect


// stampa gli elementi dell'insieme set
void set_print_test(SetElem *set) {
if (set==NULL)  {
    printf("La stringa è vuota");}
    else{
SetElem * test=set;
while (test->next!=NULL){
printf("%d",test->info);
test=test->next;
}
printf("%d",test->info);
}
}

void set_print(SetElem *set) {
    if (set==NULL){
        printf("La stringa è vuota \n");
        }
    else{
        if (set->next!=NULL){
            printf("%d",set->info);
            set_print(set->next);
            }
        else{
            printf("%d \n",set->info);}

        }
     }




// dato un insieme set, restituisce un valore non nullo (true) se l'insieme e' vuoto,
// 0 (false) altrimenti
int is_empty(SetElem *set) {
    if(set==NULL){
    return 1;}
    else{
        return 0; }
}


// dato un insieme set ed un valore intero info, restituisce un valore non nullo (true)
// se info e' un elemento di set, 0 (false) altrimenti
int is_element(SetElem *set, int info) {
    if (set==NULL){
        printf("La stringa + vuota \n");
        return 0;
        }
    else{
        if (set->next!=NULL){
            if(set->info==info){
                return 1;
                }
            else{
                return is_element(set->next,info);}

            }
        else{
            if(set->info==info){
                return 1; }
            else{return 0;}
            }
     }
}


// dato un insieme set, restituisce un valore non nullo (true) se set rappresenta un insieme
// (ovvero non contiene elementi duplicati), 0 (false) altrimenti
int aid_is_set(SetElem *set) {
    if (set==NULL) {
        printf("L'insieme � vuoto");
        return 0;}
    else {
        if(set->next!=NULL){
            int ris=is_element(set->next,set->info);

            if (ris>=1){

                return 0;}
            else{
                return aid_is_set(set->next);}
                }
        else{

            return 1;}

        }
    }
int is_set(SetElem *set){
    int ris=aid_is_set(set);
    if (ris==1){
        return 1;
         }
    else { return 0;}
     }
// dati gli insiemi sub e set, restituisce un valore non nullo (true) se sub e' un
// sottoinsieme di set, 0 (false) altrimenti
int is_subset(SetElem *sub, SetElem *set) {
    if (sub==NULL){
        return 1;}
        if (set==NULL){
        return 0;}
    int ris=is_element(set,sub->info);
    if(ris==1){
        if (sub->next==NULL){
            return 1;}
        return is_subset(sub->next,set);
        }
    else{
        return 0;}
}

SetElem* reach_the_end(SetElem *set){
    SetElem* prova=set;
    while (prova->next!=NULL) {
        prova=prova->next;}
    return prova;}


// dato un insieme set e un valore intero, modifica set aggiungendovi l'elemento info
// se non e' gia' presente
void set_add(SetElem **set, int info) {
    if ((*set)!=NULL){
        int ris=is_element((*set), info);
        if (ris==0){
            SetElem* right=reach_the_end((*set));
            SetElem* new;
            new=(SetElem*)malloc(sizeof(SetElem));
            right->next=new;
            new->info=info;
            new->next=NULL;
        }

    }
    else{
        SetElem* right;
        right=(SetElem*)malloc(sizeof(SetElem));
        right->info=info;
        right->next=NULL;
        (*set)=right;
        }
}

// dato un insieme set e un valore intero, rimuove dall'insieme l'elemento info
// (se presente)

SetElem* reach_the_right_ptr(SetElem *set,int info){
    SetElem* prova=set;
    if(set->info==info){
        return set;}
    while (prova->next->info!=info) {
        prova=prova->next;}
    return prova;}


void set_del(SetElem **set, int info) {
    if ((*set)!=NULL){
        int ris=is_element((*set), info);

        if (ris==1){

            SetElem* right=reach_the_right_ptr((*set),info);

            SetElem* save=right->next->next;
            free(right->next);
            right->next=save;

}
}
}

// dato un insieme src e un insieme dest, inserisce nell'insieme dest gli elementi di src
// che non sono gia' presenti in dest
void set_union(SetElem *src, SetElem **dest) {
        SetElem* clone=src;
    if (src==NULL || (*dest)==NULL ){);}
    else{
        while(clone->next!=NULL){
            if (is_element((*dest), clone->info)==0){
                set_add(dest, clone->info);
                }
            clone=clone->next;

        }
    }
}


// dato un insieme src e un insieme dest, elimina dall'insieme dest gli eventuali elementi
// presenti anche in src
void set_difference(SetElem *src, SetElem **dest) {
    SetElem* clone=src;
    if (src==NULL || (*dest)==NULL ){}
    else{
        while(clone->next!=NULL){
            if (is_element((*dest), clone->info)==1){
                set_del(dest, clone->info);
                }
            clone=clone->next;

        }
    }
}
