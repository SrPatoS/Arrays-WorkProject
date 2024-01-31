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

float **columnArray() {
    int lines = 0;
    int columns = 1;

    printf("=== Matriz Coluna ===\n");
    printf("Digite a Quantidade de Linhas: ");
    scanf("%d", &lines);

    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int c = 0; c < columns; c++) {
            printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, c + 1);
            scanf("%f", &array[i][c]);
        }
    }

    printArray(array, lines, columns);

    return array;
}

float **nullArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Nula ===\n");
    printf("Digite a Quantidade de Linhas: ");
    scanf("%d", &lines);

    printf("Digite a Quantidade de Colunas: ");
    scanf("%d", &columns);

    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int c = 0; c < columns; c++) {
            array[i][c] = 0;
        }
    }

    printArray(array, lines, columns);

    return array;
}

float **squareArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Quadrada ===\n");
    printf("Digite o Tamanho: ");
    scanf("%d", &lines);

    columns = lines;

    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int c = 0; c < columns; c++) {
            printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, c + 1);
            scanf("%f", &array[i][c]);
        }
    }

    printArray(array, lines, columns);

    return array;
}

float **diagonalArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Diagonal ===\n");
    printf("Digite o Tamanho: ");
    scanf("%d", &lines);

    columns = lines;

    float **array = (float **) malloc(lines * sizeof(float *));

    for (int i = 0; i < lines; i++) {
        array[i] = (float *) malloc(columns * sizeof(float));
    }

    for (int i = 0; i < lines; i++) {
        for (int c = 0; c < columns; c++) {
            if (i == c) {
                printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, c + 1);
                scanf("%f", &array[i][c]);
            }
        }
    }

    printArray(array, lines, columns);

    return array;
}