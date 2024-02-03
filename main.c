#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lines;
    int columns;
    float **data;
} Matrix;

Matrix globalMatrixA;
Matrix globalMatrixB;

void printMatrix(Matrix *matrix) {
    printf("[\n");
    for (int i = 0; i < matrix->lines; i++) {
        printf("  [ ");
        for (int j = 0; j < matrix->columns; j++) {
            printf("%.2f", matrix->data[i][j]);
            if (j < matrix->columns - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
    printf("]\n");
}

Matrix createLineMatrix() {
    Matrix matrix;
    int columns = 0;

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &columns);

    matrix.lines = 1;
    matrix.columns = columns;

    matrix.data = (float **) malloc(matrix.lines * sizeof(float *));
    matrix.data[0] = (float *) malloc(columns * sizeof(float));

    for (int i = 0; i < matrix.columns; i++) {
        printf("Defina um valor para (linha, coluna): (%d, %d)\n", 1, i + 1);
        scanf("%f", &matrix.data[0][i]);
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createColumMatrix() {
    Matrix matrix;
    int lines = 0;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &lines);

    matrix.columns = 1;
    matrix.lines = lines;

    matrix.data = (float **) malloc(matrix.lines * sizeof(float *));
    matrix.data[0] = (float *) malloc(lines * sizeof(float));

    for (int i = 0; i < matrix.columns; i++) {
        printf("Defina um valor para (linha, coluna): (%d, %d)\n", 1, i + 1);
        scanf("%f", &matrix.data[0][i]);
    }

    printMatrix(&matrix);

    return matrix;
}

void addOperation() {
    if (!(globalMatrixB.lines == globalMatrixA.lines && globalMatrixB.columns == globalMatrixA.columns)) {
        printf("As matrizes não têm o mesmo tamanho!");
        return;
    }

    Matrix result;

    result.lines = globalMatrixA.lines;
    result.columns = globalMatrixA.columns;

    result.data = (float **) malloc(result.lines * sizeof(float *));

    for (int i = 0; i < result.lines; i++) {
        result.data[i] = (float *) malloc(result.columns * sizeof(float));
    }

    for (int line = 0; line < result.lines; line++) {
        for (int colum = 0; colum < result.columns; colum++) {
            result.data[line][colum] = globalMatrixA.data[line][colum] + globalMatrixB.data[line][colum];
        }
    }

    printf("Resultado: \n");
    printMatrix(&result);

    for (int i = 0; i < result.lines; i++) {
        free(result.data[i]);
    }

    free(result.data);
}

int main() {
    int matrixSelected = 0;

    while (matrixSelected < 2) {
        printf("=== Operações com Matrizes ===\n");

        printf("[1] - Matriz Linha \n");
        printf("[2] - Matriz Coluna \n");

        int choice = 0;

        printf("Selecione o tipo de matriz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (matrixSelected == 0) {
                    globalMatrixA = createLineMatrix();
                    matrixSelected = 1;
                    break;
                }

                globalMatrixB = createLineMatrix();
                matrixSelected = 2;
                break;
            case 2:
                if (matrixSelected == 0) {
                    globalMatrixA = createColumMatrix();
                    matrixSelected = 1;
                    break;
                }

                globalMatrixB = createColumMatrix();
                matrixSelected = 2;
                break;
        }
    }

    int operationChoice = 0;

    printf("[1] - Adição\n");

    printf("Selecione o tipo de operação: \n");
    scanf("%d", &operationChoice);

    switch (operationChoice) {
        case 1:
            addOperation();
            break;

    }

    for (int i = 0; i < globalMatrixA.lines; i++) {
        free(globalMatrixA.data[i]);
    }
    free(globalMatrixA.data);

    for (int i = 0; i < globalMatrixB.lines; i++) {
        free(globalMatrixB.data[i]);
    }
    free(globalMatrixB.data);

    return 0;
}
