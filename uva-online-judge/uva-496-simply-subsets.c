// Problem  : UVA 496 - Simply Subsets
// Author   : timwilliam
// Compiled : 07/01/2021 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * a, const void * b){
    return(*(int*) a - *(int*)b);
}

int is_equal(int * A, int len_A, int * B, int len_B){
    int i;
    
    if(len_A != len_B)
        return 0;

    for(i = 0; i < len_A; i++)
        if(A[i] != B[i])
            return 0;

    return 1;
}

int main(void){
    int A[1000] = {0}, B[1000] = {0}, n_A, n_B, i, j, k, match;
    char c;

    while(scanf("%d%c", &A[0], &c) == 2){
        for(i = 1; c != '\n'; i++)
            scanf("%d%c", &A[i], &c);
        n_A = i;
        qsort(A, n_A, sizeof(int), compare);

        c = 0;
        for(i = 0; c != '\n'; i++)
            scanf("%d%c", &B[i], &c);
        n_B = i;
        qsort(B, n_B, sizeof(int), compare);

        if(A[0] == 0 && B[0] == 0)
            break;

        match = 0;
        if(n_B <= n_A){
            for(i = 0; i < n_B; i++){
                for(j = 0; j < n_A; j++){
                    if(B[i] == A[j]){
                        match++;
                        break;      
                    }
                }
            }
        }
        else if (n_A < n_B){
            for(i = 0; i < n_A; i++){
                for(j = 0; j < n_B; j++){
                    if(A[i] == B[j]){
                        match++;
                        break;      
                    }
                }
            }
        }

        if(n_A == n_B){
            if(is_equal(A, n_A, B, n_B))
                printf("A equals B\n");
            else if(match == 0)
                printf("A and B are disjoint\n");
            else
                printf("I'm confused!\n");
        }
        else if(n_B < n_A && match > 0)
            printf("B is a proper subset of A\n");
        else if(n_A < n_B && match > 0)
            printf("A is a proper subset of B\n");
        
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
}
