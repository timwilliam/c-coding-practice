// Problem  : UVA 10664 - Luggage
// Author   : timwilliam
// Compiled : 07/30/2021 (v2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
    return *(int*) b - *(int*) a;
}

int main(void){
    int i, m, weight[20], total_weight, n, bucket1, bucket2;
    char c;

    scanf("%d", &m);
    while(m--){
        total_weight = n = 0;
        memset(weight, 0, sizeof(*weight));

        while(1){
            scanf("%d%c", &weight[n], &c);
            total_weight += weight[n];

            n++;
            if(c == '\n')
                break;
        }
        
        if(total_weight % 2 != 0){
            printf("NO\n");
            break;
        }

        qsort(weight, n, sizeof(*weight), cmpfunc); // sort descending

        bucket1 = bucket2 = 0; 
        for(i = 0; i < n; i++){
            if(bucket1 <= bucket2)
                bucket1 += weight[i];
            else
                bucket2 += weight[i];
        }

        if(bucket1 == bucket2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}