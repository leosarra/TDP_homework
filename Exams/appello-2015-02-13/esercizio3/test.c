#include <stdlib.h>
#include <string.h>
#include "../libtest/libtest.h"
#include "test.h"
#include "esercizio.h"

int main(int argc, char** argv){
    const int NTEST = 5;
    
    int size[5] = {
        1,
        2,
        3,
        4,
        5
    };
    
    int*** input = (int***) malloc(NTEST * sizeof(int**));
    
    for (int i = 0; i < NTEST; i++){
        input[i] = (int**) malloc(size[i]*sizeof(int*));
        for (int j = 0; j<size[i]; j++) {
            input[i][j] = (int*) malloc(size[i]*sizeof(int));
        }
        for (int k=0; k<size[i]; k++) {
            for (int l=0; l<size[i]; l++) {
                input[i][k][l] = k + l;
            }
        }
    }
    
    int exp[10] = {
        0,
        2,
        6,
        12,
        20
    };
    
	test_reset();
	
	for (int i = 0; i < NTEST; i++) {
		print_test_start(i+1);
		printf("Funzione: diagonalePrincipale\n");
		printf("Input: \n");
        
        print_mat_int(input[i],size[i],size[i]);
        printf("\n");
        
        int ris = diagonalePrincipale(input[i],size[i]);
		test_compare_int(exp[i],ris);
		print_test_end();
		print_n_success("#Test superati: ");
	}
	print_test_result("Percentuale test corretti:");
}







