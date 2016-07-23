#include "esercizio1.h"
#include <stdlib.h>
#include <stdio.h>

void aux(Card* cards,int index,int size){
  if (size==0){printf("Size uguale a 0 \n");}
  else if (index==size-1 || index==size){
    printf("Finito");
  }
  else{
    Card temp=cards[index];
    cards[index]=cards[index+1];
    cards[index+1]=temp;
    aux(cards,index+2,size);
}
}


void swap_pairs(Card** cards, int size) {
  if (cards==NULL){
    printf("Null trovato");
  }
  else{
  Card* temp=*cards;
  if (size%2!=0) {
    size--;}
  aux(temp,0,size);

  }
}
