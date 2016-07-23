#include <stdlib.h>
#include <stdio.h>

#include "esercizio2.h"


ListNode* merge_elements(ListNode* l1, ListNode* l2) {
  ListNode* inizio=(ListNode*)malloc(sizeof(ListNode));
  inizio->next=NULL;
  ListNode* start=inizio;
  while (l1!=NULL || l2!=NULL){
    inizio->next=(ListNode*)malloc(sizeof(ListNode));
    inizio=inizio->next;
    if (l1==NULL && l2!=NULL){
      inizio->value=l2->value;
      l2=l2->next;
      inizio->next=NULL;
    }
    else if (l1!=NULL && l2==NULL){
      inizio->value=l1->value;
      l1=l1->next;
      inizio->next=NULL;
    }
    else if(l1->value == l2->value){
      inizio->value=l1->value;
      l1=l1->next;
      l2=l2->next;
      inizio->next=NULL;
    }
    else if(l1->value < l2->value){
      inizio->value=l1->value;
      l1=l1->next;
      inizio->next=NULL;
    }
    else if(l1->value > l2->value){
      inizio->value=l2->value;
      l2=l2->next;
      inizio->next=NULL;
    }

  }

  return start->next;



}
