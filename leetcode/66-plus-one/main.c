#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDigits(int *digits, int digitsSize) {
    int i;

    for(i = 0; i < digitsSize; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");

    return;
}

int *plusOne(int *digits, int digitsSize, int *returnSize) {
    int *returnDigits = malloc(*returnSize * sizeof(int));
    memcpy(returnDigits + 1, digits, digitsSize * sizeof(int));

    // printDigits(returnDigits, *returnSize);
    returnDigits[*returnSize - 1] += 1;
    // printDigits(returnDigits, *returnSize);

    int i; 
    for(i = *returnSize - 1; i > 0; i--) {
        if(returnDigits[i] > 9) {
            returnDigits[i]     -= 10;
            returnDigits[i - 1] += 1;
        }
    }
    
    // printDigits(returnDigits, *returnSize);

    // printf("debug %d %d %d\n", *returnDigits, *(returnDigits + 1), *(returnDigits + 2));

    if(returnDigits[0] == 0) {
        *returnSize -= 1;

        // printf("before realloc\n");
        // printDigits(returnDigits, *returnSize + 1);
        // printf("%d\n", *(returnDigits + 1));
        memcpy(returnDigits, returnDigits + 1, *returnSize * sizeof(int));
        // printDigits(returnDigits, *returnSize + 1);
        returnDigits = realloc(returnDigits, *returnSize);

        // printf("after realloc\n");
        // printDigits(returnDigits, *returnSize);
        // printDigits(returnDigits, *returnSize);
    }

    return returnDigits;
}

int main(void) {
    // int digits[] = {1, 2, 3};
    int digits[] = {1, 2, 9};
    // int digits[] = {1, 9, 3};
    // int digits[] = {9, 9, 9};

    int *returnDigits, returnSize, digitsSize;
    
    digitsSize = sizeof(digits) / sizeof(digits[0]);
    returnSize = digitsSize + 1;
    returnDigits = plusOne(digits, digitsSize, &returnSize);

    printDigits(returnDigits, returnSize);

    free(returnDigits);

    return 0;
}