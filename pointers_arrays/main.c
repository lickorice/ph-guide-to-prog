#include <stdio.h>
#include <stdlib.h>

int main() {
    int* my_array;
    my_array = (int *) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; ++i) {
        my_array[i] = (i+1);
    }

    for (int i = 0; i < 5; ++i) {
        printf("value at i=%d: %d\n", i, my_array[i]);
    }

    int** mult_table;
    mult_table = (int **) malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; ++i) {
        mult_table[i] = (int *) malloc(5 * sizeof(int));
        for (int j = 0; j < 5; ++j) {
            mult_table[i][j] = (i+1) * (j+1);
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