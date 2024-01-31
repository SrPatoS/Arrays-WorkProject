#include "../printArray/printArray.h"
#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>

float **lineArray() {
    int lines = 1;
    int columns = 0;

    printf("=== Matriz Linha ===\n");
    printf("Digite a Quantidade de Colunas: ");
    scanf("%d", &columns);

    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int c = 0; c < columns; c++) {
            printf("Escolha o valor para o item: [%d, %d]\n", i + 1, c + 1);
            scanf("%f", &array[i][c]);
        }
    }

    printArray(array, lines, columns);

    return array;
}
