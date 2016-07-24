#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols){
    Mat* matrix=(Mat *)malloc(sizeof(Mat));
    matrix->cols=cols;
    matrix->rows=rows;
    (*matrix).row_ptrs=(float **)calloc(rows,sizeof(float*)); // va bene anche "matrix->values"
        for (int j=0;j<rows;j++){  
            matrix->row_ptrs[j]=(float*)calloc(rows,sizeof(float));
            }
    return matrix;
    }
Mat* Mat_read(char *filename){
    FILE* fp;
    fp=fopen(filename, "r");
    if (fp==NULL){
        printf("errore di lettura");
        }
    int rows=0;
    float valore=0;
    int cols=0;
    fscanf(fp,"%d",&rows);
    fscanf(fp,"%d",&cols);
    Mat* matrix=Mat_alloc(rows,cols);
    for (int i=0;i<rows;i++){  
        for (int j=0;j<cols;j++){  
            fscanf(fp,"%f",&valore);
            (*matrix).row_ptrs[i][j]=valore;
        if (feof(fp)){
            printf("file terminato");
            break; }
        }
    }
            
    return matrix;
 }
 
void Mat_print(Mat *m){
    for (int i=0;i<(*m).rows;i++){  
        for (int j=0;j<(*m).cols;j++){  
            printf("%.2f   ",(*m).row_ptrs[i][j]);
    
        }
    printf("\n");
    }
}
void Mat_write(char *filename, Mat *m){
    FILE* fp;
    fp=fopen(filename,"w");
    fprintf(fp,"%d ",(*m).rows);
    fprintf(fp,"%d",(*m).cols);
    fprintf(fp,"\n");
    for (int i=0;i<(*m).rows;i++){  
        for (int j=0;j<(*m).cols;j++){  
            fprintf(fp,"%.2f ",(*m).row_ptrs[i][j]);
        }
    fprintf(fp,"\n");
    }
}
int  Mat_is_symmetric(Mat *m){
    int ris=1;
    for (int i=0;i<(*m).rows;i++){  
        for (int j=0;j<(*m).cols;j++){  
            if (m->row_ptrs[i][j]!=m->row_ptrs[j][i]){
                ris=0;
                break;  }
            }
    }
    return ris;
}

double vec_module(float* vec,int cols){
    float ris=0;
    float risf=0;
    for (int i=0;i<cols;i++){
        ris+=vec[i]*vec[i];

        }

    risf=sqrt(ris);

    return risf;
}

void Mat_normalize_rows(Mat *m) { 
    float ris=0;
        for (int i=0;i<(*m).rows;i++){
            ris=vec_module((*m).row_ptrs[i],(*m).cols);
            
              
        for (int j=0;j<(*m).cols;j++){  
            m->row_ptrs[i][j]=(m->row_ptrs[i][j])/ris;
            }
        }
}
Mat* Mat_clone(Mat *m){ 
    Mat* clone;
    clone=Mat_alloc(m->rows,m->cols);
    (*clone).rows=m->rows;
    (*clone).cols=m->rows;
    for (int i=0;i<(*m).rows;i++){
        for (int j=0;j<(*m).cols;j++){  
            clone->row_ptrs[i][j]=(m->row_ptrs[i][j]);
        }
    }
    return clone;
 }
void Mat_free(Mat *m){
     for (int i=0;i<(*m).rows;i++){
         free(m->row_ptrs[i]);
     }
     free(m->row_ptrs);
     free(m);
}

int main(int argc, char **argv) {
  /********************************************************
   *             TEST Mat_alloc/Mat_read                  *
   ********************************************************/
  printf("Leggo m1 dal file mat_1.txt...");
  Mat *m1 = Mat_read("mat_1.txt");
  
  printf(" fatto.\n\n");

  /********************************************************
   *                    TEST Mat_print                    *
   ********************************************************/
  printf("m1:\n");
   Mat_print(m1);
  printf("\n");

  /********************************************************
   *                    TEST Mat_write                    *
   ********************************************************/
  printf("Scrivo una copia di m1 in copia_mat_1.txt...");
  Mat_write("copia_mat_1.txt", m1);
  printf(" fatto.\n\n");

  /********************************************************
   *                TEST Mat_is_symmetric                 *
   ********************************************************/
  printf("Leggo m2 dal file mat_2.txt...");
   Mat *m2 = Mat_read("mat_2.txt");
  printf(" fatto.\n");
  printf("m2:\n");
  Mat_print(m2);  
  printf("La matrice m2 e' simmetrica?\n");
  int is_symmmetric = Mat_is_symmetric(m2);
  if(is_symmmetric) {
    printf("Si e' simmetrica.\n");
   }
  else {
printf("No non e' simmetrica.\n");
   }
   printf("\n");

  /********************************************************
   *               TEST Mat_normalize_rows                *
   ********************************************************/
  printf("Leggo m3 dal file mat_3.txt...");
Mat *m3 = Mat_read("mat_3.txt");
   printf(" fatto.\n");
  printf("m3:\n");
   Mat_print(m3);  
  printf("Normalizzo le righe della matrice m3...");
  Mat_normalize_rows(m3);
printf(" fatto.\n");
   printf("La matrice m3 con righe normalizzate e':\n");
   Mat_print(m3);
   printf("\n");

  /********************************************************
   *                    TEST Mat_clone                    *
   ********************************************************/
  printf("Clono m2...");
  Mat *copy_m2 = Mat_clone(m2);
  printf(" fatto.\n");
  printf("Copia m2:\n");
  Mat_print(copy_m2);  

  /********************************************************
   *                    TEST Mat_free                     *
   ********************************************************/
  Mat_free(copy_m2);
  Mat_free(m3);
  Mat_free(m2);
  Mat_free(m1);
  printf("Free compiuta con successo");

  return 0;
}
