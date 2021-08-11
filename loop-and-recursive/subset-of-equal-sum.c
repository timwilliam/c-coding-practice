// Problem  : Subset of Equal Sum (print T/F if possible/impossible)
// Author   : timwilliam
// Compiled : 08/11/2021
// Notes    : Reference YouTube Tutorial https://youtu.be/IsvocB5BJhw

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *list_of_subset_sum;
int num_of_possible_subset;

int getTotal(int *set, int size_of_set){
    int i, total = 0;

    for(i = 0; i < size_of_set; i++)
        total += set[i];

    return total;
}

void resetListOfSubsetSum(){
    int i;

    for(i = 0; i < num_of_possible_subset; i++)
        list_of_subset_sum[i] = 0;
}

void generateListOfSubSetSum(int *set, int size_of_set){
    // e.g.: for set[4] = {1, 5, 11, 5}, this will generate
    //           list_of_subset_sum = {0, 5, 11, 16, 5, 10, 16, 21, 1, 6, 12, 17, 6, 11, 17, 22}
    int i, j, marker;

    marker = 1;
    for(i = size_of_set - 1; i >= 0; i--){
        for(j = 0; j < marker; j++)
            list_of_subset_sum[marker+j] = list_of_subset_sum[j] + set[i];

        marker += 1 * j;
    }
}

void printListOfSubsetSum(){
    int i;

    for(i = 0; i < num_of_possible_subset; i++)
        printf("%d%c", list_of_subset_sum[i], i + 1 == num_of_possible_subset ? '\n' : ' ');

    return;
}

int cmpfunc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(void){
    int set[4] = {1, 5, 11, 5};
    int size_of_set = sizeof(set) / sizeof(int);
    int total = getTotal(set, size_of_set);

    if(total % 2 != 0)
        printf("False\n");
    else{
        int i, j, target_sum = total / 2;

        // create an array to hold the subset sum result
        num_of_possible_subset = (int) (pow(2, size_of_set));
        list_of_subset_sum = (int*) malloc(num_of_possible_subset * sizeof(int));
        
        resetListOfSubsetSum();
        generateListOfSubSetSum(set, size_of_set);
        
        qsort(list_of_subset_sum, num_of_possible_subset, sizeof(*list_of_subset_sum), cmpfunc);
        // printListOfSubsetSum();

        // search in list_of_subset_sum and see if there is any that matches the target_sum
        int *ptr = (int*) bsearch(&target_sum, list_of_subset_sum, \
                        num_of_possible_subset, sizeof(int), cmpfunc);

        if(ptr != NULL)
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }

    return 0;
}