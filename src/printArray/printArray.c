#include "printArray.h"
#include <stdio.h>

void printArray(float **array, int lines, int columns) {
    printf("[\n");
    for (int i = 0; i < lines; i++) {
        printf("  [ ");
        for (int j = 0; j < columns; j++) {
            printf("%.2f", array[i][j]);
            if (j < columns - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
    printf("]\n");
}