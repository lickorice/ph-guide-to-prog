#include <stdio.h>
#include <stdlib.h>

int main() {
    int* my_array; // Array of ints = pointer to int
    my_array = (int *) malloc(5 * sizeof(int)); // Allocate 5 int-sized bytes

    for (int i = 0; i < 5; ++i) {
        my_array[i] = (i+1) * (i+1); // Assign (i+1)^2
    }

    for (int i = 0; i < 5; ++i) {
        printf("value at %d: %d\n", i, my_array[i]); // Print:
    }

    int** mult_table;
    mult_table = (int **) malloc(5 * sizeof(int*));
    
    for (int i = 0; i < 5; ++i) {
        // This is an int* type. Allocate again with malloc (see line 6)
        mult_table[i] = (int *) malloc(5 * sizeof(int));
        for (int j = 0; j < 5; ++j) {
            mult_table[i][j] = (i+1) * (j+1); // Our multiplication table cell value
        }
    }

    printf("\nMultiplcation table:\n");
    // Print our multiplication table:
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d\t", mult_table[i][j]);
        }
        printf("\n");
    }
}