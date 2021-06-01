// Problem  : UVA 10664 - Luggage
// Author   : timwilliam
// Compiled : 06/01/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
    return(*(int*) a - *(int*) b);
}

int main(void){
    int T, w[20], n, i, sum, sum_a, sum_b;
    char temp;
    
    scanf("%d", &T);
    while(T--){
        memset(w, 0, sizeof(w));
        n = 0;

        while(scanf("%d%c", &w[n], &temp)){
            if(temp == '\n')
                break;
        
            n++;
        }

        sum = 0;
        for(i = 0; i < n+1; i++)
            sum += w[i];
    
        if(sum % 2 != 0){
            printf("NO\n");
            continue;
        }

        // sort ascending
        qsort(w, n+1, sizeof(int), cmpfunc);

        // use greedy algorithm loop over all the weights,
        //   put each number in the set whose sum is smallest
        sum_a = sum_b = 0;
        while(n >= 0){
            if(sum_a == 0 && sum_b == 0){
                sum_a = w[n];
                sum_b = w[n-1];
        
                n -= 2;        
            }
            else if(sum_b < sum_a){
                sum_b += w[n];
                n--;
            }
            else{
                sum_a += w[n];
                n--;
            }
        }
    
        if(sum_a == sum_b)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
