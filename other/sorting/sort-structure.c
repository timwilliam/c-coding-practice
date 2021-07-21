// Problem  : Sorting of structured record
// Author   : timwilliam
// Compiled : 07/21/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int grade;
    char name[10];
}STUDENT_GRADE;

void print_grade(STUDENT_GRADE *grading, int n){
    int i;

    printf("Grading record:\n");
    for(i = 0; i < n; i++)
        printf("%d. %10s %3d\n", i+1, grading[i].name, grading[i].grade);
    
    return;
}

int cmpfunc_int(const void *a, const void *b){
    return ((STUDENT_GRADE*)a)->grade - ((STUDENT_GRADE*)b)->grade ;
}

int cmpfunc_str(const void *a, const void *b){
    return strcmp(((STUDENT_GRADE*)a)->name, ((STUDENT_GRADE*)b)->name);
}

int main(void){
    int n = 3;
    STUDENT_GRADE *grading = malloc(n * sizeof(STUDENT_GRADE));

    grading[0].grade = 100;
    strcpy(grading[0].name, "Budi");
    grading[1].grade = 25;
    strcpy(grading[1].name, "Citra");
    grading[2].grade = 60;
    strcpy(grading[2].name, "Andi");

    printf("[Before Sorting]\n");
    print_grade(grading, n);
    printf("\n");

    // cmpfunc_int can be used to sort by grade, whiile cmpfunc_str can be used to sort by name
    // qsort(grading, n, sizeof(*grading), cmpfunc_int);
    qsort(grading, n, sizeof(*grading), cmpfunc_str);

    printf("[After Sorting]\n");
    print_grade(grading, n);

    return 0;
}