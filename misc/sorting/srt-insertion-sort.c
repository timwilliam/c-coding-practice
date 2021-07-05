// Problem      : Insertion Sort
// Author       : timwilliam
// Compiled     : 07/05/2021
// Complexity   : O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    return;
}

void insertion_sort(int *array, int array_size){
    int i, pos, temp;

	for(i = 1; i < array_size - 1; i++){
		pos = i;
		temp = array[i];

		while(pos > 0 && array[pos-1] > temp){
			array[pos] = array[pos-1];
			pos--;
		}

		array[pos] = temp;
	}
	
    return;
}

int main(void){
    int array[] = {7, 2, 4, 1, 5, 3};
    int array_size = sizeof(array) / sizeof(int);

    print_array(array, array_size);
    insertion_sort(array, array_size);
    print_array(array, array_size);

    return 0;
}