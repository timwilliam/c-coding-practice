// Problem  : qsort() library usage example
// Author   : timwilliam
// Compiled : 07/05/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int * array, int n_elem){
    for(int i = 0; i < n_elem; i++)
        printf("%d ", array[i]);

    printf("\n");

    return;
}

int intcmp(const void * a, const void * b){
    return *(int*) a - *(int*) b;
}

int strcmpfunc(const void * a, const void * b){
    // const char *pa = *(char**) a;
    // const char *pb = *(char**) b;
    // return strcmp(pa, pb);
    return(strcmp(*(char**) a, *(char**) b));
}

int main(void){
    int numbers[] = {7, 2, 4, 1, 5, 3};
    print_array(numbers, sizeof(numbers) / sizeof(*numbers));
    qsort(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(*numbers), intcmp);
    print_array(numbers, sizeof(numbers) / sizeof(*numbers));

    printf("\n");

    const char *str[] = {"apple", "pineapple", "pear", "avocado", "kiwi", "plum"};
    int stringLen = sizeof(str) / sizeof(*str);

    for(int i = 0; i < stringLen; i++)
        printf("%s ", str[i]);
    printf("\n");

    qsort(str, stringLen, sizeof(*str), strcmpfunc);

    for(int i = 0; i < stringLen; i++)
        printf("%s ", str[i]);
    printf("\n");
}