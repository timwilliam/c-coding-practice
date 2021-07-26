// Problem  : Sorting of string
// Author   : timwilliam
// Compiled : 07/21/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_name(char **names, int n){
    int i;

    for(i = 0; i < n; i++)
        printf("%d. %s\n", i+1, names[i]);

    return;
}

int cmpfunc(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}

int main(void){
    char *names[3] = {"Budi", "Andi", "Cinta"};
    int n = 3;

    printf("Before sorting\n");
    print_name(names, n);

    qsort(names, n, sizeof(*names), cmpfunc);

    printf("After sorting\n");
    print_name(names, n);

    return 0;
}