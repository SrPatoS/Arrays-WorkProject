#include <stdio.h>
#include <math.h>
#include <malloc.h>

int globalLinesA = 0;
int globalLinesB = 0;
int globalColumnsA = 0;
int globalColumnsB = 0;

int arraysSelected = 0;

void printArray(float **array, int lines, int columns) {
    printf("[\n");
    for (int i = 0; i < lines; i++) {
        printf("  [ ");
        for (int j = 0; j < columns; j++) {
            printf("%.2f", (fabs(array[i][j]) < 0.005) ? 0.0 : array[i][j]);
            if (j < columns - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
    printf("]\n");
}

void **add(float **arrayA, float **arrayB) {
    //printArray(arrayA, globalLinesA, globalColumnsA);
    printf("%d", globalColumnsA);
}

float **lineArray() {
    int lines = 1;
    int columns = 0;

    printf("=== Matriz Linha ===\n");
    printf("Digite a Quantidade de Colunas: ");
    scanf("%d", &columns);

    if (arraysSelected == 1) {
        globalColumnsB = columns;
        globalLinesB = lines;
    } else {
        globalColumnsA = columns;
        globalLinesA = lines;
    }

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

float **identityArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Identidade ===\n");
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
                array[i][c] = 1;
            } else {
                array[i][c] = 0;
            }
        }
    }

    printArray(array, lines, columns);

    return array;
}

float **transposedArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Transposta ===\n");
    printf("Digite a Quantidade de linhas: ");
    scanf("%d", &lines);

    printf("Digite a Quantidade de colunas: ");
    scanf("%d", &columns);

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

    float **transposedArray = (float **) malloc(columns * sizeof(float *));

    for (int c = 0; c < columns; c++) {
        transposedArray[c] = (float *) malloc(lines * sizeof(float));
        for (int i = 0; i < lines; i++) {
            transposedArray[c][i] = array[i][c];
        }
    }

    printf("\nMatriz Original:\n");
    printArray(array, lines, columns);

    printf("\nMatriz Transposta:\n");
    printArray(transposedArray, columns, lines);

    return transposedArray;
}

float **symmetricalArray() {
    int size;

    printf("=== Matriz Simétrica ===\n");
    printf("Digite o Tamanho: ");
    scanf("%d", &size);

    float **array = (float **) malloc(size * sizeof(float *));

    for (int i = 0; i < size; i++) {
        array[i] = (float *) malloc(size * sizeof(float));
    }

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, j + 1);
            scanf("%f", &array[i][j]);

            array[j][i] = array[i][j];
        }
    }

    printArray(array, size, size);

    return array;
}

float **oppositeArray() {
    int lines = 0;
    int columns = 0;

    printf("=== Matriz Transposta ===\n");
    printf("Digite a Quantidade de linhas: ");
    scanf("%d", &lines);

    printf("Digite a Quantidade de colunas: ");
    scanf("%d", &columns);

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

    float **oppositeArray = (float **) malloc(lines * sizeof(float *));
    for (int i = 0; i < lines; i++) {
        oppositeArray[i] = (float *) malloc(columns * sizeof(float));
        for (int c = 0; c < columns; c++) {
            oppositeArray[i][c] = -array[i][c];
        }
    }

    printf("\nMatriz Original:\n");
    printArray(array, lines, columns);

    printf("\nMatriz Oposta:\n");
    printArray(oppositeArray, lines, columns);

    return oppositeArray;
}

float **upperTriangularArray() {
    int size;

    printf("=== Matriz Triangular Superior ===\n");
    printf("Digite o Tamanho: ");
    scanf("%d", &size);

    float **array = (float **) malloc(size * sizeof(float *));

    for (int i = 0; i < size; i++) {
        array[i] = (float *) malloc(size * sizeof(float));
    }

    for (int i = 0; i < size; i++) {
        for (int c = i; c < size; c++) {
            if (c >= i) {
                printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, c + 1);
                scanf("%f", &array[i][c]);
            }
        }
    }

    printArray(array, size, size);

    return array;
}

float **lowerTriangular() {
    int size;

    printf("=== Matriz Triangular Inferior ===\n");
    printf("Digite o Tamanho: ");
    scanf("%d", &size);

    float **array = (float **) malloc(size * sizeof(float *));

    for (int i = 0; i < size; i++) {
        array[i] = (float *) malloc(size * sizeof(float));
    }

    for (int i = 0; i < size; i++) {
        for (int c = 0; c <= i; c++) {
            printf("Escolha o valor para o item: (linha, coluna) [%d, %d]\n", i + 1, c + 1);
            scanf("%f", &array[i][c]);
        }
    }

    printArray(array, size, size);

    return array;
}

int main() {
    printf(" 1 - Matriz Linha\n");
    printf(" 2 - Matriz Coluna\n");
    printf(" 3 - Matriz Nula\n");
    printf(" 4 - Matriz Quadrada\n");
    printf(" 5 - Matriz Diagonal\n");
    printf(" 6 - Matriz Identidade\n");
    printf(" 7 - Matriz Transposta\n");
    printf(" 8 - Matriz Simétrica\n");
    printf(" 9 - Matriz Oposta\n");
    printf(" 10 - Matriz Triangular Superior\n");
    printf(" 11 - Matriz Triangular Inferior\n");

    float **arrayA;
    float **arrayB;

    while (arraysSelected < 2) {
        printf("Selecione o Tipo de Matriz: ");

        int choice = 0;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                choice = 0;
                arraysSelected++;
                float **selectedLineArray = lineArray(arraysSelected);

                if (arraysSelected == 0) {
                    arrayA = selectedLineArray;
                } else {
                    arrayB = selectedLineArray;
                }
                break;
            case 2:
                choice = 0;
                arraysSelected++;
                float **selectedColumnArray = columnArray();

                if (arraysSelected == 0) {
                    arrayA = selectedColumnArray;
                } else {
                    arrayB = selectedColumnArray;
                }
                break;
            case 3:
                choice = 0;
                arraysSelected++;
                float **selectedNullArray = nullArray();

                if (arraysSelected == 0) {
                    arrayA = selectedNullArray;
                } else {
                    arrayB = selectedNullArray;
                }
                break;
            case 4:
                choice = 0;
                arraysSelected++;
                float **selectedSquareArray = squareArray();

                if (arraysSelected == 0) {
                    arrayA = selectedSquareArray;
                } else {
                    arrayB = selectedSquareArray;
                }
                break;
            case 5:
                choice = 0;
                arraysSelected++;
                float **selectedDiagonalArray = diagonalArray();

                if (arraysSelected == 0) {
                    arrayA = selectedDiagonalArray;
                } else {
                    arrayB = selectedDiagonalArray;
                }
                break;

            case 6:
                choice = 0;
                arraysSelected++;
                float **selectedIdentityArray = identityArray();

                if (arraysSelected == 0) {
                    arrayA = selectedIdentityArray;
                } else {
                    arrayB = selectedIdentityArray;
                }
                break;
            case 7:
                choice = 0;
                arraysSelected++;
                float **selectedTransposedArray = transposedArray();

                if (arraysSelected == 0) {
                    arrayA = selectedTransposedArray;
                } else {
                    arrayB = selectedTransposedArray;
                }
                break;
            case 8:
                choice = 0;
                arraysSelected++;
                float **selectedSymmetricalArray = symmetricalArray();

                if (arraysSelected == 0) {
                    arrayA = selectedSymmetricalArray;
                } else {
                    arrayB = selectedSymmetricalArray;
                }
                break;
            case 9:
                choice = 0;
                arraysSelected++;
                float **selectedOppositeArray = oppositeArray();

                if (arraysSelected == 0) {
                    arrayA = selectedOppositeArray;
                } else {
                    arrayB = selectedOppositeArray;
                }
                break;
            case 10:
                choice = 0;
                arraysSelected++;
                float **selectedUpperTriangularArray = upperTriangularArray();

                if (arraysSelected == 0) {
                    arrayA = selectedUpperTriangularArray;
                } else {
                    arrayB = selectedUpperTriangularArray;
                }
                break;
            case 11:
                choice = 0;
                arraysSelected++;
                float **selectedUpperLowerTriangular = lowerTriangular();

                if (arraysSelected == 0) {
                    arrayA = selectedUpperLowerTriangular;
                } else {
                    arrayB = selectedUpperLowerTriangular;
                }
                break;
        }
    }

    int operationChoice = 0;

    printf("Escolha a Operação Matricial\n");
    printf(" 1 - Soma\n");

    scanf("%d", &operationChoice);

    switch (operationChoice) {
        case 1:
            add(arrayA, arrayB);

            globalLinesA = 0;
            globalLinesB = 0;
            globalColumnsA = 0;
            globalColumnsB = 0;

            break;
    }

    return 0;
}


