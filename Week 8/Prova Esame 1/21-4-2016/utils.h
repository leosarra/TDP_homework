#pragma once
#include <stdio.h>



/* esegue l'allocazione di un blocco conttiguo di memoria su cui genera
   un array di puntatori alle righr
*/
float** Matrix_allocContiguous(int num_rows, int num_cols);


/* esegue la deallocazione di un blocco contiguo a partire dai puntatori alle righe.*/
void Matrix_freeContiguous(float**m, int num_rows);



/*scrive una matrice su file
  f: file
  m: array di righe
  num_rows: righe
  num_cols: colonne

  formato
  <num rows> <num_cols>
  m00 m01 m02 ... m0<num_cols>
  m10 m11 m12 ... m1<num_cols>
  ...
  m<num_rows>0 .. m<num_rows><num_cols>

 */
void Matrix_write(FILE* f, float** m, int num_rows, int num_cols);

/*legge da file una matrice nel formato della Matrix_write
  f: file (aperto in lettura)
  num_rows: puntatore alla variabile che contiene il numero di righe
  num_cols: puntatore alla variabile che contiene il numero di colonne
  restituisce un array di puntatori alle righe
 */
float** Matrix_read(FILE* f, int* num_rows, int* num_cols);


/*scrive una matrice su file di cui e' fornita la path
  filename: nome del file
  m: array di righe
  num_rows: righe
  num_cols: colonne

  formato
  <num rows> <num_cols>
  m00 m01 m02 ... m0<num_cols>
  m10 m11 m12 ... m1<num_cols>
  ...
  m<num_rows>0 .. m<num_rows><num_cols>

 */
void Matrix_writeOnPath(const char* filename, float** m, int num_rows, int num_cols);


/*legge da file una matrice nel formato della Matrix_write
  a partire dal nome del file
  filename: nome del file
  num_rows: puntatore alla variabile che contiene il numero di righe
  num_cols: puntatore alla variabile che contiene il numero di colonne
  restituisce un array di puntatori alle righe
 */
float** Matrix_readFromPath(const char* filename, int* num_rows, int* num_cols);

/* esegue l'allocazione di una matrice */
float** Matrix_alloc(int num_rows, int num_cols);


/* esegue la deallocazione di una matrice */
void Matrix_free(float**m, int num_rows);


