#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "esercizio3.h"

int aux2(char* v,int dim,char* word,int index){
    if(word[0]=='\0'){
       return 1;}
    if (index>=dim){return 0;}
    if (v[index]!='_'){return 0;}
    return aux2(v,dim,word+1,index+1);
  }


int aux1(char* v,int dim, char* word, int index){
  if(index>=dim){
    return 0;
  }
  return aux2(v,dim,word,index)+aux1(v,dim,word,index+1);

}


int find_spots(char* v, int dim, char* word) {
  return aux1(v,dim,word,0);

}
