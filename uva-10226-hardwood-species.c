#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int A[], int n){
	int i;
	printf("Array: ");
	for(i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

// sort the array ascendingly using insertion sort
void sort_array(int A[], int n){
	int key, value, temp, i;
	
	for(i = 1; i < n; i++){
		key = i;
		value = A[key];

		while(key > 0 && value < A[key-1]){
			A[key] = A[key-1];
			key--;	
		}

		A[key] = value;
	}
}

int main(void){
	int A[] = {7, 4, 1, 5, 3};
	int n = 5;
	
	sort_array(A, n);
	print_array(A, n);
}
