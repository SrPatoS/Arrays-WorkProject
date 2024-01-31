#include <stdio.h>
#include "src/arrays/arrays.h"

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

    int arraysSelected = 0;

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
                float **selectedLineArray = lineArray();

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

    return 0;
}

