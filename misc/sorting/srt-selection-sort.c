// Problem  : Selection Sort
// Author   : timwilliam
// Compiled : 07/05/2021

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    return;
}

// return index of min element
int find_min(int *array, int array_size){
    int min = 100, min_index, i;
    for(i = 0; i < array_size; i++){
        if(array[i] <= min){
            min = array[i];
            min_index = i;
        }
    }

    return min_index;
}

int *selection_sort(int *array, int array_size){
    int *sorted_array = malloc(array_size * sizeof(int));
    int i, min_index;

    for(i = 0; i < array_size; i++){
        min_index = find_min(array, array_size);
        sorted_array[i] = array[min_index];
        array[min_index] = 100;
    }

    return sorted_array;
}

int main(void){
    int array[] = {2, 7, 4, 1, 5, 3};
    int array_size = sizeof(array) / sizeof(int);
    int *sorted_array;

    print_array(array, array_size);
    sorted_array = selection_sort(array, array_size);
    print_array(sorted_array, array_size);

    return 0;
}