#include "addOperation/addOperation.h"
#include "subtractOperation/subtractOperation.h"
#include "src/makeArray.h"
#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    float** testArray = makeArray(2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", testArray[i][j]);
        }
        printf("\n");
    }

    clearArray(testArray, 2);


    return 0;
}
