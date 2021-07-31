// Problem  : Greatest Common Factor
// Author   : timwilliam
// Compiled : 07/09/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void print_array(int *array, int len){
    int i;

    for(i = 0; i < len; i++)
        printf("%d ", array[i]);

    printf("\n");

    return;
}

int get_factor(int n, int *factor){
    int i, j, n_factor;
    
    n_factor = 0;
    j = 0;
    for(i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n / i == i){
                factor[j] = i;
                j++;
            }
            else{
                factor[j] = i;
                factor[j+1] = n / i;
                j+=2;
            }
        }
    }
    
    return j;
}

void get_gcf(int *n1_factor, int n1_factor_count, int *n2_factor, int n2_factor_count){
    int i, j, gcf = 0;
    print_array(n1_factor, n1_factor_count);
    printf("n1 count = %d\n", n1_factor_count);
    for(i = n1_factor_count - 1; i >= 0 ; i--){
        for(j = n2_factor_count - 1; j >= 0 ; j--){
            if(n1_factor[i] == n2_factor[j]){
                gcf = n1_factor[i];
                break;
            }

        }

        if(gcf > 0)
            break;
    }

    printf("GCF = %d\n", gcf);
    return;
}

int cmpfunc(const void *a, const void *b){
    return *(int*) a - *(int*)b;
}

int main(void){
    int n1, n2, *n1_factor, n1_factor_count, *n2_factor, n2_factor_count;

    n1_factor = malloc(100 * sizeof(int));
    n2_factor = malloc(100 * sizeof(int));

    while(scanf("%d %d", &n1, &n2)){
        n1_factor_count = get_factor(n1, n1_factor);
        qsort(n1_factor, n1_factor_count, sizeof(int), cmpfunc);
        n2_factor_count= get_factor(n2, n2_factor);
        qsort(n2_factor, n2_factor_count, sizeof(int), cmpfunc);

        get_gcf(n1_factor, n1_factor_count, n2_factor, n2_factor_count);

        memset(n1_factor, 0, sizeof(n1_factor));
        memset(n2_factor, 0, sizeof(n2_factor));
    }

    return 0;
}