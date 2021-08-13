// Problem  : UVA 10465 - Homer Simpson
// Author   : timwilliam
// Compiled : 08/13/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct _COMBO{
    int sum, x_m, x_n, x_beer;
}COMBO;

void swap(int *m, int*n){
    // make sure m < n
    if(*m > *n){
        int temp;
        temp = *m;
        *m = *n;
        *n = temp;
    }

    return;
}

void generateCombo(COMBO *combo_list, int m, int n, int t, int n_combo){
    int i, rem;
    
    // generate all possible combo based on decreasing number of m
    for(i = n_combo; i >= 0; i--){
        combo_list[i].x_m = i;

        rem = t - m * combo_list[i].x_m;
        
        combo_list[i].x_n = rem / n;
        combo_list[i].x_beer = t - (m * combo_list[i].x_m) - (n * combo_list[i].x_n);
        combo_list[i].sum = combo_list[i].x_m + combo_list[i].x_n;
    }

    return;
}

void printCombo(COMBO *combo_list, int n_combo){
    int i;

    printf("  # Sum x_m x_n x_b\n");
    for(i = 0; i <= n_combo; i++)
        printf("%3d %3d %3d %3d %3d\n", i+1, combo_list[i].sum, combo_list[i].x_m, combo_list[i].x_n, combo_list[i].x_beer);

    return;
}

int cmpfunc(const void *a, const void *b){
    // number of beer takes priority
    if(((COMBO*)a)->x_beer < ((COMBO*)b)->x_beer)
        return -1;
    else if(((COMBO*)a)->x_beer > ((COMBO*)b)->x_beer)
        return 1;
    
    // then number of burger eaten
    if(((COMBO*)a)->sum > ((COMBO*)b)->sum)
        return -1;
    else if(((COMBO*)a)->sum < ((COMBO*)b)->sum)
        return 1;
    else
        return 0;
}

int main(void){
    int m, n, t;

    while(scanf("%d %d %d", &m, &n, &t) != EOF){
        // if m > n, then swap m with n
        swap(&m, &n);

        if(t % m == 0){
            printf("%d\n", t / m);
        }
        else{
            int n_combo = t / m;
            COMBO *combo_list = (COMBO*) malloc((n_combo+1) * sizeof(COMBO));

            // generate all possible combo of m and n, and then sort them
            //   sorting is based number of beer (ascending) and sum of burger (descending)
            generateCombo(combo_list, m, n, t, n_combo);
            qsort(combo_list, n_combo+1, sizeof(*combo_list), cmpfunc);
            // printCombo(combo_list, n_combo);

            if(combo_list[0].x_beer == 0)
                printf("%d\n", combo_list[0].sum);
            else
                printf("%d %d\n", combo_list[0].sum, combo_list[0].x_beer);

            free(combo_list);
        }
    }

    return 0;
}