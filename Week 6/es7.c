#include <stdio.h>
#include <stdlib.h>
  /********************************************************
   *                    FUNZIONI vec_read                     *
   ********************************************************/
double* vec_read(int *dim, char *filename){
	FILE *myFile;
	myFile=fopen(filename,"r");
	fscanf(myFile,"%d",dim);
    double * vettore;
    vettore=(double *)calloc(*dim,sizeof(double));
    printf("\n");
	for (int i=0;i<*dim;i++){
		fscanf(myFile, "%lf ",&vettore[i]);
		}
    return vettore;
	}
  /********************************************************
   *                    FUNZIONI vec_print                 *
   ********************************************************/
void    vec_print(double *v, int dim){
    printf("\n[");
        for (int i=0;i<dim;i++){
        printf("%.2f,",v[i]);
        }
    printf("]");
    }
      /********************************************************
   *                    FUNZIONI vec_writet                     *
   ********************************************************/
void    vec_write(char *filename, double *v, int dim){
    FILE *myFile;
	myFile=fopen(filename,"w");
	fprintf(myFile,"%d \n",dim);
	for (int i=0;i<dim;i++){
		fprintf(myFile, "%lf ",v[i]);
        printf("%.2lf",v[i]);
        printf(" ");
		}
    }
      /********************************************************
   *                    FUNZIONI vec_scale                     *
   ********************************************************/
void    vec_scale(double *v, int dim, double d){
        for (int i=0;i<dim;i++){
        v[i]=v[i]*d;
        
        printf("%f,",v[i]);
        } }
  /********************************************************
   *                    FUNZIONI vec_dot                  *
   ********************************************************/

double  vec_dot(double *src1, double *src2, int dim){
    double* vettore;
    double ris=0;
    vettore=(double *)malloc(sizeof(double)*dim);
        for (int i=0;i<dim;i++){
        vettore[i]=((src2[i])*(src1[i]));
        printf("\n");
        printf("%lf e %lf",src2[i],src1[i]);
         printf("\n");
        printf("%lf",vettore[i]);
        printf("\n");
        }
        for (int i=0;i<dim;i++){
        ris+=vettore[i];
        }
    return ris;
        
}

  /********************************************************
   *                    FUNZIONI vec_clone                *
   ********************************************************/
        
double* vec_clone(double *v, int dim){
    double* vettore;
    vettore=(double *)calloc(dim,sizeof(double));
    for (int i=0;i<dim;i++){
        vettore[i]=v[i];
        }
    return vettore;
    
    }

int main(int argc, char **argv) {
  int dim1 = 0, dim2 = 0, dim3 = 0;
  
  /********************************************************
   *                    TEST vec_read                     *
   ********************************************************/
  printf("Leggo v1 dal file vec_1.txt...");
  double *v1 = vec_read(&dim1, "vec_1.txt");
  printf(" done.\n\n");
  printf("**********************TERMINATO 1° es********************* \n");

  /********************************************************
   *                    TEST vec_print                    *
   ********************************************************/
   printf("v1: ");
   vec_print(v1, dim1);
  printf("\n\n");
  printf("**********************TERMINATO 2° es********************* \n");

  /********************************************************
   *                    TEST vec_write                    *
   ********************************************************/
    printf("Scrivo una copia di v1 in copia_vec_1.txt...");
    vec_write("copia_vec_1.txt", v1, dim1);
    printf(" done.\n\n");
    printf("**********************TERMINATO 3° es********************* \n");

  /********************************************************
   *                    TEST vec_scale                    *
   ********************************************************/
  printf("\nLeggo v2 dal file vec_2.txt...");
  double *v2 = vec_read(&dim2, "vec_2.txt");
  printf("\n  done.\n");
  printf("\nv 2: ");
  vec_print(v2, dim2);
  printf(" v2: ");
  vec_print(v2, dim2);  
  printf("\n");
  printf("\nLeggo v3 dal file vec_3.txt...");
  double *v3 = vec_read(&dim3, "vec_3.txt");
  printf(" done.\n");
  printf("\n v3: ");
  vec_print(v3, dim3);  
  printf("\n Scalo v3 di un fattore di 0.5... \n");
  vec_scale(v3, dim3, 0.5);
  printf("\n done.\n");
  printf("v3: ");
  vec_print(v3, dim3);  
  printf("\n");
  printf("**********************TERMINATO 4° es********************* \n");

  /********************************************************
   *                    TEST vec_dot                      *
   ********************************************************/
printf("Calcolo il prodotto scalare tra v2 e v3...");
double dot = vec_dot(v2, v3, dim2);
printf(" done.\n");
printf("Il profotto scalare tra v2 e v3 e': %lf\n\n", dot);
printf("**********************TERMINATO 5° es********************* \n");

  /********************************************************
   *                    TEST vec_clone                    *
   ********************************************************/
printf("Clono v2...");
double *copy_v2 = vec_clone(v2, dim2);
printf(" done.\n");
printf("Copia v2: ");
vec_print(copy_v2, dim3);  

free(copy_v2);
free(v3);
free(v2);
free(v1);
printf(" \n**********************TERMINATO 6° es********************* \n");

  return 0;
}
