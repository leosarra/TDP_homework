#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "../utils/sparse_matrix.h"

int main(int argc, char** argv) {
    int total_test_number = 10, successes = 0;
    
    char buffer[1024];
    int i, result;
    float elements_to_find[10] = { 2.0, 8.0, 0.1, -1.0, 8.0, 3.6, 4.0, 5.1, 1.5, 3.9 };
    int expected_results[10] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };
    for(i = 0; i < total_test_number; ++i) {
        printf("Test number %d out of %d\n", i + 1, total_test_number);

        sprintf(buffer, "data/source_sparse_mat_%d.txt", i);
        SparseMatrix source_sparse_mat = SparseMatrix_load(buffer);
        printf("source sparse matrix: ");
        SparseMatrix_print(source_sparse_mat);
	printf("searching for value: %f\n", elements_to_find[i]);

	printf("expected result: %d\n", expected_results[i]);
        
        result = sparse_matrix_contains_element(source_sparse_mat, elements_to_find[i]);
        printf("output resut: %d\n", result);

        if(result == expected_results[i]) {
	  printf("SUCCESS\n");
	  successes++;
        }
        else {
            printf("FAILURE\n");
        }
        printf("Current success rate: %0.02f%%\n", 
	       (float)(successes) * 100.0f/ (float)(total_test_number));
        printf("\n*************************************************\n\n");

        SparseMatrix_free(source_sparse_mat);
    }

    printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

    return 0;
}
