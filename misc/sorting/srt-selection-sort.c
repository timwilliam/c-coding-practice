// Problem  : Selection Sort
// Author   : timwilliam
// Compiled : 07/05/2021

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    return;
}

// return index of min element
int find_min(int *array, int start_index, int array_size){
    int min = INT_MAX, min_index, i;
    for(i = start_index; i < array_size; i++){
        if(array[i] <= min){
            min = array[i];
            min_index = i;
        }
    }

    return min_index;
}

void swap(int *array, int index1, int index2){
    int temp;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;

    return;
}

void selection_sort(int *array, int array_size){
    int i, min_index;

    for(i = 0; i < array_size-1; i++){
        min_index = find_min(array, i+1, array_size);
        swap(array, i, min_index);
    }

    return;
}

int main(void){
    int array[] = {2, 7, 4, 1, 5, 3};
    int array_size = sizeof(array) / sizeof(int);

    print_array(array, array_size);
    selection_sort(array, array_size);
    print_array(array, array_size);

    return 0;
}