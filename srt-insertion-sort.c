// Compiled	: 05/10/2021

#include <stdio.h>
#include <stdlib.h>

void print_x(int *x, int n){
	int i;
	printf("X: ");
	for(i = 0; i < n; i++){
		printf("%d ", x[i]);
	}
	printf("\n");
}

void insrt_sort(int *x, int n){
	int i, key, value;
	for(i = 1; i < n; i++){
		key = i;
		value = x[i];
		// move the value to the right one by one
		// 	- only move when key is > 0, since n w/ only 1 element is always in sorted state
		//	- when appropiate position is found, replace the value in that position
		while(key > 0 && x[key - 1] > value){
			x[key] = x[key - 1];
			key--;
		}
		x[key] = value;
	}
}

int main(void){
	int x[6] = {7, 2, 4, 1, 5, 3};
	int n = sizeof(x) / sizeof(x[0]);

	printf("Before, ");
	print_x(x, n);
	insrt_sort(x, n);
	printf("After, ");
	print_x(x, n);
}
