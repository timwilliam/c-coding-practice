#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b){
    return *(int*) a - *(int*) b;
}

double average(int* salary, int salarySize) {
    int i, sum = 0;

    qsort(salary, salarySize, sizeof(int), &comparator);

    for(i = 1; i < salarySize - 1; i++){
        sum += salary[i];
    }

    return (double) sum / (salarySize - 2);
}

int main(void){
    int salary[] = {4000, 3000, 1000, 2000};
    int salarySize = sizeof(salary) / sizeof(salary[0]);

    printf("%.4lf\n", average(salary, salarySize));

    return 0;
}
