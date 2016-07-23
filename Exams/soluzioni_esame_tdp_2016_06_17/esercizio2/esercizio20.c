#include <stdlib.h>

#include "esercizio2.h"


ListNode* merge_elements(ListNode* l1, ListNode* l2) {  
  ListNode* inizio = (ListNode*)calloc(1, sizeof(ListNode));
  inizio->next=NULL;
  ListNode* nodo=inizio;
  while (l1!=NULL || l2!=NULL){
    nodo->next=(ListNode*)malloc(sizeof(ListNode));
    nodo=nodo->next;
    if (l1==NULL && l2!=NULL){
      nodo->value=l2->value;
      l2=l2->next;
    }
    else if (l2==NULL && l1!=NULL){
      nodo->value=l1->value;
      l1=l1->next;
    }
    else{
      if (l1->value<l2->value){
        nodo->value=l1->value;
        l1=l1->next;
      }
      if (l1->value>l2->value){
        nodo->value=l2->value;
        l2=l2->next;
      }
    }




  }
      ListNode* finale=inizio->next;
  return finale;
}
