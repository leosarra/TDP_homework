#include "esercizio3.h"

#include <stdlib.h>


void aux(ListNode* output, ListNode* src, int n){
  if (src==NULL){
    return;}
  else if (src->value%n==0){
    output->next=(ListNode*)malloc(sizeof(ListNode));
    output=output->next;
    output->next=NULL;
    output->value=src->value;
    aux(output, src->next,n);
    }
  else {
    aux(output,src->next,n);
    }
}


ListNode* list_multipliers(ListNode* src, int n) {
  ListNode* lista=(ListNode*)malloc(sizeof(ListNode));
  lista->next=NULL;
  ListNode* finale=lista;
  aux(lista,src,n);
  finale=finale->next;
  return finale;
  }
