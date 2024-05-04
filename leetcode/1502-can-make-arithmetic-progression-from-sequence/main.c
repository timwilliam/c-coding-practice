#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArr(int *arr, int n) {
	int i;

	printf("{ ");
	for(i = 0; i < n; i++) {
		printf("%2d", arr[i]);

		if(i == n - 1) {
			printf("}\n");
		}
		else {
			printf(", ");
		}
	}
}

// return 0 if equal, negative if x < y, positive if x > y
int comparator(const void *x, const void *y) {
	return *((int*)x) - *((int*)y); 
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
	if(arrSize == 2) {
		return true;
	}
	else {
		int i, diff;

		// calculate the diff progression value
		diff = arr[1] - arr[0];

		// sort array ascendingly
		qsort(arr, arrSize, sizeof(int), &comparator);

		for(i = 1; i < arrSize - 1; i++) {
			// stop whenever the diff progression differs
			if((arr[i+1] - arr[i]) != diff) {
				return false;
			}
			else {
				continue;
			}
		}
		
		return true;
	}
}

int main(void) {
	// int arr[] = {3, 5, 1};
	int arr[] = {1, 2, 4};

	int n = sizeof(arr) / sizeof(arr[0]);
	bool canMake = canMakeArithmeticProgression(arr, n);

	if(canMake) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	return 0;
}
