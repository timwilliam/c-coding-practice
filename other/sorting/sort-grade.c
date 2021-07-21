// Problem  : Sorting of numbers
// Author   : timwilliam
// Compiled : 07/21/2021

#include <stdio.h>
#include <stdlib.h>

void print_grade(int *grade, int n){
    int i;

    for(i = 0; i < n; i++)
        printf("%d. %d\n", i+1, grade[i]);

    return;
}

int cmpfunc(const void *a, const void *b){
    return *(int*) a - *(int*) b;
}

int main(void){
    int grade[5] = {100, 50, 10, 40, 75};
    int n = 5;

    printf("Before\n");
    print_grade(grade, 5);

    qsort(grade, n, sizeof(*grade), cmpfunc);

    printf("After\n");
    print_grade(grade, 5);

    return 0;
}