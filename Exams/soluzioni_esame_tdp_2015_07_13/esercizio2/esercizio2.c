#include <stdlib.h>
#include <cstddef>
#include <stdio.h>

#include "esercizio2.h"
SparseVectorElement* SparseVector_getElemat(SparseVectorElement* vec, int pos, int dimension) {
  if(vec==NULL){return NULL;}
  if (pos>dimension){return NULL;}

  while(vec!=NULL){
    if(vec->pos==pos){
      return vec;}
    vec=vec->next;}
  return NULL;}
////////////////////////////////////////////////////////////
float SparseVector_getElem(SparseVector* vec, int pos) {
int dimension=vec->dimension;
SparseVectorElement* result= SparseVector_getElemat(vec->values,pos,dimension);
if (result==NULL){return 0;}
else{
  return result->value;}
}
/////////////////////////////////////////////////////////////////////
int SparseVector_setElem(SparseVector* vec, int pos, float value) {
  if(pos>vec->dimension){return 0;}
  SparseVectorElement* elemento= SparseVector_getElemat(vec->values,pos,vec->dimension);
  if (elemento==NULL){
    SparseVectorElement* nuovo=(SparseVectorElement*)malloc(sizeof(SparseVectorElement));
    SparseVectorElement* backup=vec->values;
    nuovo->value=value;
    nuovo->pos=pos;
    nuovo->next=backup;
    vec->values=nuovo;
  }
  else{
    if( value!=0){
      elemento->value=value;
    }
    else {
      SparseVectorElement* tmp = elemento;
      elemento = elemento->next;
      free(tmp);
    }
  }
return 1;
  }
