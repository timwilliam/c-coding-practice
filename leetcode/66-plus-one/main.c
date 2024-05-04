#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *arr, int n) {
	int i;

	printf("{ ");
	for(i = 0; i < n; i++) {
		printf("%2d", arr[i]);

		if(i < n - 1) {
			printf(", ");
		}
		else {
			printf(" }\n");
		}
	}

	return;
}

void regroup(int *returnDigits, int i) {
	returnDigits[i]		-= 10;
	returnDigits[i-1]	+= 1;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i;

	// create new array to store the results
	*returnSize = digitsSize;
	int *returnDigits = (int*) calloc(digitsSize, sizeof(int));
	memcpy(returnDigits, digits, digitsSize * sizeof(int));

	// do plus one on the least significant digit
	returnDigits[*returnSize-1] += 1;

	// check if regroup is needed after plus one
	for(i = *returnSize - 1; i > 0; i--) {
		if(returnDigits[i] > 9) {
			regroup(returnDigits, i);
		}
	}

	// if most significant digit is > 9, reallocate extra memory to store additional element
	if(returnDigits[0] > 9) {
		*returnSize += 1;
		returnDigits = (int*) realloc(returnDigits, *returnSize * sizeof(int));
	
		// extra element is added to the end of the array, move all element one position to the right
		// use memmove instead of memcpy to copy overlapping memory blocks
		memmove(returnDigits + 1, returnDigits, (*returnSize - 1) * sizeof(int));
		memset(returnDigits, 0, sizeof(int));

		// do regroup for the most significant digit
		regroup(returnDigits, 1);
	}

	return returnDigits;
}

int main(void) {
	// int digits[] = {1, 2, 3};
	// int digits[] = {4, 3, 2, 1};
	// int digits[] = {9};
	// int digits[] = {9, 9, 9};
	int digits[] = {9, 9};
	
	int n = sizeof(digits) / sizeof(digits[0]);

	printArr(digits, n);

	int resultSize;
	int *result = plusOne(digits, n, &resultSize);

	printArr(result, resultSize);

	free(result);

	return 0;
}
