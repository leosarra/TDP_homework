#include <stdlib.h>
#include <string.h>
#include "../libtest/libtest.h"
#include "test.h"
#include "esercizio.h"

int main(int argc, char** argv){
    const int NTEST = 5;
    
    int input[5][2] = {
        {1,1},
        {2,1},
        {2,2},
        {2,3},
        {2,4}
    };
    
    int exp[10] = {
        1,
        2,
        6,
        14,
        30
    };
    
	test_reset();
	
	for (int i = 0; i < NTEST; i++) {
		print_test_start(i+1);
		printf("Funzione: sommatoria\n");
		printf("Input: ");
        
        print_array_int(input[i],2);
        printf("\n");
        
        int ris = sommatoria(input[i][0],input[i][1]);
		test_compare_int(exp[i],ris);
		print_test_end();
		print_n_success("#Test superati: ");
	}
	print_test_result("Percentuale test corretti:");
}








