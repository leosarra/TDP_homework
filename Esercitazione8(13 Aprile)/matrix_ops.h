#pragma once
#include <stdio.h>


/******************************* FUNZIONI FORNITE *******************************/
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



/*
  azzera tramite
  - scambi di righe
  - somma di una riga ad un'altra moltiplocata per scale
  tutti gli elementi della colonna "col" che si trovano ad una riga
  superiore alla prima

  restituisce 1 se l'operazione e' possibile
  0 se tutti gli elementi della colonna sono gia' nulli

  suggerimento: 
  trovare il massimo valore assoluto nella colonna
  usare sumAndScaleRows
*/
int Matrix_zeroColumn(float**m, int num_rows, int num_cols, int col);


/*triangolarizza m, usando zero column*/
void Matrix_triangularize(float**m, int num_rows, int num_cols);


/******************************* FUNZIONI DA SCRIVERE *******************************/


/*alloca una matrice di num_rows * num_cols elementi*/
float** Matrix_allocArrayOfArray(int num_rows, int num_cols);

/*dealloca una matrice con num_rows righe
  m: puntatore all'array di righe
  num_rows: numero di righe  (lunghezza di m)
*/
void Matrix_freeArrayOfArray(float** m, int num_rows);

/*NOTA

  dopo aver svolto queste due funzioni,  modificare Matrix_alloc e Matrix_free in modo da invocare
  Matrix_allocArrayOfArray e Matrix_freeArrayOfArray.
*/



/*copia una matrice in memoria
  src: matrice in input
  num_rows: righe
  num_cols: colonne
  restituisce un'array di puntatori alle righe;
*/
float** Matrix_clone(float** src, int num_rows, int num_cols);

/*restuisce una nuova matrice che e' la trasposta della matrice di input*/
float** Matrix_copyTransposed(float** src, int num_rows, int num_cols);


/* scrive in dest (che deve essere preallocato)
   il sottoblocco di src
   che si trova in posizione 
     [block_start_row....block_start_row+block_num_rows],
     [block_start_col....block_start_col+block_num_cols]

     num_rows e num_cols sono le dimensioni di src;
     se il blocco copiato eccede le dimensioni di src
     la funzione ritorna un valore negativo (-1).
     in caso contrario ritorna il numero di elementi copiati
 */
int  Matrix_extractBlock(float** dest, float** src, 
			 int num_rows, int num_cols, 
			 int block_start_row, int block_start_col,
			 int block_num_rows, int block_num_cols);



/*prodotto matrice vettore
  dest: area di memoria preallocata in cui scrivere il risultato
        la dimensione di dest e' pari al numero di righe di m
  m: matrice
  num_rows: numero di righe di m
  num_cols: numero di colonne di m
  v: array di valori da moltiplicare per m;

  SUGGERIMENTO: usare la Vec_dot :)
*/

void Matrix_vectorProduct(float* dest, float** m, int num_rows, int num_cols, float* v);

/*
scambia la riga r1 ed r2 nella matrice m
*/
void Matrix_exchangeRows(float**m , int r1, int r2);

/*
  somma alla riga r1+=r2*scale
*/
void Matrix_sumAndScaleRows(float** m, int r1, int  r2, int num_cols, float scale);


/*
  trova l'indice di riga che contiene il massimo valore (in modulo),
  considerando solo la colonna col
*/
int  Matrix_findMaxIdxInCol(float**m, int num_rows, int col);




