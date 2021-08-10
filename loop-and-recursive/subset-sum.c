// Problem  : Subset Sum
// Author   : timwilliam
// Compiled : 08/10/2021

#include <stdio.h>
#include <stdlib.h>

// array is processed from the last element down to the first element
int getNumOfSubsetSum(int *array, int target_sum, int marker){
    if(target_sum == 0) // take nothing from the array to construct the subset
        return 1;
    else if(target_sum < 0) // input is positive integer, impossible to construct a negative subset
        return 0;
    else if(marker < 0) // no more element in the array can be used to construct the subset
        return 0;
    else if(array[marker] > target_sum) // current element exceed the target_sum, carry on to the next element 
        getNumOfSubsetSum(array, target_sum, marker - 1);
    
    // target_sum w/ array[marker] + target_sum w/out array[marker]
    return getNumOfSubsetSum(array, target_sum, marker - 1) + \
        getNumOfSubsetSum(array, target_sum - array[marker], marker - 1);
}

int main(void){
    int array[4] = {2, 4, 6, 10};
    int target_sum = 16;
    int num_of_possible_subset;

    num_of_possible_subset = getNumOfSubsetSum(array, target_sum, sizeof(array) / sizeof(int) - 1);
    printf("%d\n", num_of_possible_subset);

    return 0;
}