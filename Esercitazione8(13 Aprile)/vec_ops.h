#pragma once
#include <stdio.h>

/*alloca un vettore in memoria 
  dim: dimensione del vettore
  resituisce un'area di memoria allocata
*/
float* Vec_alloc(int dim);

/*dealloca l'area di memoria di un vettore
*/
void Vec_free(float* v);

/*fa una copia in memoria di un vettore un vettore si file
  v: array di valori da copiare
  dim: dimensione
  resituisce un'area di memoria in cui copio i valori
*/
float* Vec_clone(float* v, int dim);


/*
  legge un vettore dal file 
  f: file aperto in lettura
  dim: puntatore alla zona di memoria su cui scrivere la dimensione
  il valore di ritorno e' l'indirizzo di un'area di memoria (da allocare)
  che contiene gli *dim float letti da file.

  se il file e' troppo corto la funzione libera la memoria eventualmente allocata e
  ritorna 0

  formato del file
  <dimensione>
  <valore 1> <valore 2> .... <valore N>
*/
float* Vec_read(FILE* f, int* dim);

/*stampa un vettore si file
  f: file aperto in scrittura
  v: array di valori
  dim: dimensione
*/
void Vec_write(FILE* f, float* v, int dim);

/*restituisce il prodotto scalare (somma di v1[i]*v2[i])*/
float Vec_dot(float* v1, float* v2, int dim);

/*restituisce il prodotto scalare (v1+=v2*scale)*/
void Vec_scaledSum(float* v1, float* v2, int dim, float scale);

