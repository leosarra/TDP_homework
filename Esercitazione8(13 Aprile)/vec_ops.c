#include "vec_ops.h"
#include <stdlib.h>


float* Vec_alloc(int dim){
  return (float*) malloc (sizeof (float) * dim);
}

void Vec_free(float* v){
  free(v);
}

float* Vec_clone(float* v, int dim){
  float* copy=Vec_alloc(dim);
  for (int i=0; i<dim; i++)
    copy[i]=v[i];
  return copy;
}

float* Vec_read(FILE* f, int* dim){
  int dim_read=fscanf(f, "%d", dim);
  if (dim_read<=0)
    return 0;
  float* v=Vec_alloc(*dim);
  for (int i=0; i<*dim; i++){
    if (feof(f)){
      Vec_free(v);
      return 0;
    }
    fscanf(f, "%f",v+i);
  }
  return v;
}

void Vec_write(FILE* f, float* v, int dim){
  fprintf(f, "%d\n", dim);
  for (int i=0; i<dim; i++)
    fprintf(f, "%f ", v[i]);
  fprintf(f, "\n");
}


float Vec_dot(float* v1, float* v2, int dim){
  float sum=0;
  for (int i=0; i<dim; i++)
    sum+=v1[i]*v2[i];
  return sum;
}

void Vec_scaledSum(float* v1, float* v2, int dim, float scale){
  for (int i=0; i<dim; i++)
    v1[i]+=scale*v2[i];
  
}
