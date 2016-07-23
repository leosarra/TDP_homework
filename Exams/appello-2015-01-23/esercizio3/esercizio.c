#include "esercizio.h"
#include <math.h>

int sommatoria(int n, int m){
  if (m==1){
    return n;
  }
  else{
  int valore= pow(n,m);
  return valore + sommatoria(n,m-1);
  }
}
