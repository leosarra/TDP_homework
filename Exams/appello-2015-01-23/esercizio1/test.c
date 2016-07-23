#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "../libtest/libtest.h"
#include "esercizio.h"


void read_input(char* filename,int* r,int* c,int*** in,int** exp);

const int NTEST = 6;

int main(int argc, char** argv){
    
	test_reset();
	
    char filename[20];
    
	for (int k = 1; k <= NTEST; k++) {
        sprintf(filename,"file%d.txt",k);
        int r,c,i,j;
        int **in, *exp;
        
        read_input(filename,&r,&c,&in,&exp);
        
		print_test_start(k);
		printf("Funzione: sommaColonne\n\n");
		printf("Input:\n");
        print_mat_int(in,r,c);
		printf("\n");
        
        int* res = sommaColonne(in,r,c);
        
        test_compare_array_int(exp,c,res,c);
        
		print_test_end();
		print_n_success("#Test superati: ");
	}
	print_test_result("Percentuale test corretti:");
}


void read_input(char* filename, int* r,int* c,int*** in,int** exp){
    FILE* f = fopen(filename,"r");
    if (f == NULL) {
        printf("ERROR opening file %s",filename);
        exit(1);
    }
    fscanf(f,"%d ",r);
    fscanf(f,"%d ",c);
    
    *in = (int**) malloc((*r)*sizeof(int*));
    *exp = (int*) malloc((*c)*sizeof(int));
    
    for (int i = 0; i < *r; i++) {
        (*in)[i] = (int*) malloc((*c)*sizeof(int));
    }
    
    for (int i=0; i < *r; i++) {
        for (int j=0; j<*c; j++) {
            fscanf(f,"%d",&((*in)[i][j]));
        }
    }
    
    for (int i=0; i < *c; i++) {
        fscanf(f,"%d",&((*exp)[i]));
    }
    fclose(f);
}

