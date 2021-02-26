#include <stdio.h>
#include <stdlib.h>

int main() {
    int*** mult_cube; int N = 3;
    mult_cube = (int ***) malloc(N * sizeof(int**));
    
    for (int i = 0; i < N; ++i) {
        // This is an int** type. Allocate with malloc:
        mult_cube[i] = (int **) malloc(N * sizeof(int*));
        for (int j = 0; j < N; ++j) {
            // This is an int* type. Allocate with malloc:
            mult_cube[i][j] = malloc(N * sizeof(int*));
            for (int k = 0; k < N; ++k) {
                // [i][j][k] is going to be an int. Assign:
                mult_cube[i][j][k] = (i+1) * (j+1) * (k+1);
            }
        }
    }

    printf("Multiplcation cube:\n");
    // Print our multiplication cube:
    int i = 0, j = 0, k = 0;
    while (1) {
        printf("%3d   ", mult_cube[i][j][k]);
        k = ((k + 1) % N);
        if (!k) {
            switch (j) {
                case 0: printf("\n  "); break;
                case 1: printf("\n     "); break;
                case 2: printf("\n"); break;
            }
            j = (j + 1) % N;
            if (!j) {
                i = (i + 1) % N;
                if (!i) return 0;
            }
        }
    }
}