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

    printf("Selecione o Tipo de Matriz: ");

    int choice;

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            lineArray();
            break;
        case 2:
            columnArray();
            break;
    }


    /*float **lineTest = makeLineArray(3);

    printArray(lineTest, 1, 3);*/

    /*float** testArray = makeArray(2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", testArray[i][j]);
        }
        printf("\n");
    }

    clearArray(testArray, 2);*/



    return 0;
}


