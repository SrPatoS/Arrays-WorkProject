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

Matrix createColumnMatrix() {
    Matrix matrix;
    int lines = 0;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &lines);

    matrix.columns = 1;
    matrix.lines = lines;

    matrix.data = (float **) malloc(matrix.lines * sizeof(float *));
    matrix.data[0] = (float *) malloc(matrix.lines * sizeof(float));

    for (int i = 0; i < matrix.lines; i++) {
        matrix.data[i] = matrix.data[0] + i;
        printf("Defina um valor para (linha, coluna): (%d, %d)\n", i + 1, 1);
        scanf("%f", &matrix.data[i][0]);
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createNullMatrix(int rows, int columns) {
    Matrix matrix;

    matrix.lines = rows;
    matrix.columns = columns;

    matrix.data = (float **) malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (float *) calloc(columns, sizeof(float));  // Use calloc para inicializar com zeros
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createSquareMatrix() {
    Matrix matrix;
    int size;

    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &size);

    matrix.lines = size;
    matrix.columns = size;

    matrix.data = (float **) malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) {
        matrix.data[i] = (float *) calloc(size, sizeof(float));  // Inicializa com zeros
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Defina um valor para (linha, coluna): (%d, %d)\n", i + 1, j + 1);
            scanf("%f", &matrix.data[i][j]);
        }
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createDiagonalMatrix() {
    Matrix matrix;
    int size;

    printf("Digite o tamanho da matriz diagonal: ");
    scanf("%d", &size);

    matrix.lines = size;
    matrix.columns = size;

    matrix.data = (float **) malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) {
        matrix.data[i] = (float *) calloc(size, sizeof(float));  // Inicializa com zeros
    }

    for (int i = 0; i < size; i++) {
        printf("Defina um valor para a diagonal principal (linha, coluna): (%d, %d)\n", i + 1, i + 1);
        scanf("%f", &matrix.data[i][i]);
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createIdentityMatrix() {
    Matrix matrix;
    int size;

    printf("Digite o tamanho da matriz identidade: ");
    scanf("%d", &size);

    matrix.lines = size;
    matrix.columns = size;

    matrix.data = (float **) malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) {
        matrix.data[i] = (float *) calloc(size, sizeof(float));  // Inicializa com zeros
    }

    for (int i = 0; i < size; i++) {
        matrix.data[i][i] = 1.0;
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createAndPrintTransposedMatrix() {
    Matrix originalMatrix;
    Matrix transposedMatrix;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &originalMatrix.lines);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &originalMatrix.columns);

    originalMatrix.data = (float **) malloc(originalMatrix.lines * sizeof(float *));
    for (int i = 0; i < originalMatrix.lines; i++) {
        originalMatrix.data[i] = (float *) malloc(originalMatrix.columns * sizeof(float));
        for (int j = 0; j < originalMatrix.columns; j++) {
            printf("Digite o valor para (linha, coluna): (%d, %d)\n", i + 1, j + 1);
            scanf("%f", &originalMatrix.data[i][j]);
        }
    }

    printf("Matriz Original:\n");
    printMatrix(&originalMatrix);

    transposedMatrix.lines = originalMatrix.columns;
    transposedMatrix.columns = originalMatrix.lines;

    transposedMatrix.data = (float **) malloc(transposedMatrix.lines * sizeof(float *));
    for (int i = 0; i < transposedMatrix.lines; i++) {
        transposedMatrix.data[i] = (float *) malloc(transposedMatrix.columns * sizeof(float));
        for (int j = 0; j < transposedMatrix.columns; j++) {
            transposedMatrix.data[i][j] = originalMatrix.data[j][i];
        }
    }

    printf("Matriz Transposta:\n");
    printMatrix(&transposedMatrix);

    for (int i = 0; i < originalMatrix.lines; i++) {
        free(originalMatrix.data[i]);
    }
    free(originalMatrix.data);

    return transposedMatrix;
}

Matrix createSymmetricMatrix() {
    Matrix matrix;
    int size;

    printf("Digite a ordem da matriz simétrica: ");
    scanf("%d", &size);

    matrix.lines = size;
    matrix.columns = size;

    matrix.data = (float **) malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) {
        matrix.data[i] = (float *) malloc(size * sizeof(float));  // Sem inicialização, pois o usuário vai preencher
    }

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                printf("Digite o valor para a diagonal principal (linha, coluna): (%d, %d)\n", i + 1, j + 1);
            } else {
                printf("Digite o valor para (linha, coluna): (%d, %d) e (%d, %d)\n", i + 1, j + 1, j + 1, i + 1);
            }
            scanf("%f", &matrix.data[i][j]);
            matrix.data[j][i] = matrix.data[i][j];
        }
    }

    printMatrix(&matrix);

    return matrix;
}

Matrix createAndPrintOppositeMatrix() {
    Matrix originalMatrix;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &originalMatrix.lines);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &originalMatrix.columns);

    originalMatrix.data = (float **) malloc(originalMatrix.lines * sizeof(float *));
    for (int i = 0; i < originalMatrix.lines; i++) {
        originalMatrix.data[i] = (float *) malloc(originalMatrix.columns * sizeof(float));
        for (int j = 0; j < originalMatrix.columns; j++) {
            printf("Digite o valor para (linha, coluna): (%d, %d)\n", i + 1, j + 1);
            scanf("%f", &originalMatrix.data[i][j]);
        }
    }

    printf("Matriz Original:\n");
    printMatrix(&originalMatrix);

    Matrix oppositeMatrix;

    oppositeMatrix.lines = originalMatrix.lines;
    oppositeMatrix.columns = originalMatrix.columns;

    oppositeMatrix.data = (float **) malloc(oppositeMatrix.lines * sizeof(float *));
    for (int i = 0; i < oppositeMatrix.lines; i++) {
        oppositeMatrix.data[i] = (float *) malloc(oppositeMatrix.columns * sizeof(float));
        for (int j = 0; j < oppositeMatrix.columns; j++) {
            oppositeMatrix.data[i][j] = -originalMatrix.data[i][j];
        }
    }

    printf("Matriz Oposta:\n");
    printMatrix(&oppositeMatrix);

    for (int i = 0; i < originalMatrix.lines; i++) {
        free(originalMatrix.data[i]);
    }
    free(originalMatrix.data);

    for (int i = 0; i < oppositeMatrix.lines; i++) {
        free(oppositeMatrix.data[i]);
    }
    free(oppositeMatrix.data);

    return originalMatrix;
}

Matrix createUpperTriangularMatrix() {
    Matrix upperTriangularMatrix;

    printf("Digite a ordem da matriz triangular superior: ");
    scanf("%d", &upperTriangularMatrix.lines);

    upperTriangularMatrix.columns = upperTriangularMatrix.lines;

    upperTriangularMatrix.data = (float **) malloc(upperTriangularMatrix.lines * sizeof(float *));
    for (int i = 0; i < upperTriangularMatrix.lines; i++) {
        upperTriangularMatrix.data[i] = (float *) malloc(upperTriangularMatrix.columns * sizeof(float));
        for (int j = 0; j < upperTriangularMatrix.columns; j++) {
            if (i > j) {
                upperTriangularMatrix.data[i][j] = 0.0;
            } else {
                printf("Digite o valor para (linha, coluna): (%d, %d)\n", i + 1, j + 1);
                scanf("%f", &upperTriangularMatrix.data[i][j]);
            }
        }
    }

    printMatrix(&upperTriangularMatrix);

    return upperTriangularMatrix;
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

void multiplyOperation() {
    if (globalMatrixA.columns != globalMatrixB.lines) {
        printf("As matrizes não são compatíveis para multiplicação!");
        return;
    }

    Matrix result;

    result.lines = globalMatrixA.lines;
    result.columns = globalMatrixB.columns;

    result.data = (float **) malloc(result.lines * sizeof(float *));
    for (int i = 0; i < result.lines; i++) {
        result.data[i] = (float *) malloc(result.columns * sizeof(float));
    }

    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.columns; j++) {
            result.data[i][j] = 0;

            for (int k = 0; k < globalMatrixA.columns; k++) {
                result.data[i][j] += globalMatrixA.data[i][k] * globalMatrixB.data[k][j];
            }
        }
    }

    printf("Resultado: \n");
    printMatrix(&result);

    for (int i = 0; i < result.lines; i++) {
        free(result.data[i]);
    }

    free(result.data);
}

void scalarMultiplyOperation(float scalar) {
    Matrix result;

    result.lines = globalMatrixA.lines;
    result.columns = globalMatrixA.columns;

    result.data = (float **) malloc(result.lines * sizeof(float *));
    for (int i = 0; i < result.lines; i++) {
        result.data[i] = (float *) malloc(result.columns * sizeof(float));
    }

    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.columns; j++) {
            result.data[i][j] = globalMatrixA.data[i][j] * scalar;
        }
    }

    printf("Resultado: \n");
    printMatrix(&result);

    for (int i = 0; i < result.lines; i++) {
        free(result.data[i]);
    }

    free(result.data);
}

void subtractOperation() {
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

    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.columns; j++) {
            result.data[i][j] = globalMatrixA.data[i][j] - globalMatrixB.data[i][j];
        }
    }

    printf("Resultado: \n");
    printMatrix(&result);

    for (int i = 0; i < result.lines; i++) {
        free(result.data[i]);
    }

    free(result.data);
}

Matrix createLowerTriangularMatrix() {
    Matrix lowerTriangularMatrix;

    printf("Digite a ordem da matriz triangular inferior: ");
    scanf("%d", &lowerTriangularMatrix.lines);

    lowerTriangularMatrix.columns = lowerTriangularMatrix.lines;

    lowerTriangularMatrix.data = (float **) malloc(lowerTriangularMatrix.lines * sizeof(float *));
    for (int i = 0; i < lowerTriangularMatrix.lines; i++) {
        lowerTriangularMatrix.data[i] = (float *) malloc(lowerTriangularMatrix.columns * sizeof(float));
        for (int j = 0; j < lowerTriangularMatrix.columns; j++) {
            if (i < j) {
                lowerTriangularMatrix.data[i][j] = 0.0;
            } else {
                printf("Digite o valor para (linha, coluna): (%d, %d)\n", i + 1, j + 1);
                scanf("%f", &lowerTriangularMatrix.data[i][j]);
            }
        }
    }

    printMatrix(&lowerTriangularMatrix);

    return lowerTriangularMatrix;
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
                    globalMatrixA = createColumnMatrix();
                    matrixSelected = 1;
                    break;
                }

                globalMatrixB = createColumnMatrix();
                matrixSelected = 2;
                break;
        }
    }

    int operationChoice = 0;

    printf("[1] - Adição\n");
    printf("[2] - Multiplicação entre matrizes\n");
    printf("[3] - Multiplicação por escalar\n");
    printf("[4] - Subtração\n");

    printf("Selecione o tipo de operação: \n");
    scanf("%d", &operationChoice);

    switch (operationChoice) {
        case 1:
            addOperation();
            break;
        case 2:
            multiplyOperation();
            break;
        case 3:
            scalarMultiplyOperation(2);
        case 4:
            subtractOperation();
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
