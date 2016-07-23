#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "../utils/list.h"

int main(int argc, char** argv) {
    int total_test_number = 10, successes = 0;
    char buffer[1024];
    int i, result;
    int expected_results[10] = { 3, 2, 2, 4, 1, 3, 3, 2, 1, 3 };
    for(i = 0; i < total_test_number; ++i) {
        printf("Test number %d out of %d\n", i + 1, total_test_number);

        sprintf(buffer, "data/source_list_%d.txt", i);
        TipoSCL source_list = TipoSCL_load(buffer);
        printf("source list ");
        TipoSCL_print(source_list);

	printf("expected result %d\n", expected_results[i]);
        
        result = count_vowels(source_list);
        printf("output %d\n", result);

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

        TipoSCL_free(source_list);
    }

    printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

    return 0;
}
