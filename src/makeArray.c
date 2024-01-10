#include "makeArray.h"
#include <stdlib.h>

float **makeArray(int lines, int columns) {
    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = i * columns + j + 1;
        }
    }

    return array;
}

int clearArray(float **array, int lines) {
    for (int i = 0; i < lines; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}