// Program  : UVA 10268 - 498-bis
// Author   : timwilliam
// Compiled : 04/19/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int x, a[1000], n, i, sum;

    while(1){
        scanf("%d", &x);
        if(x == 0)
            exit(0);
        
        memset(a, 0, sizeof(a));
        n = 0;
        sum = 0;

        while(scanf("%d", &a[n]) != EOF)
            n++;

        for(i = 0; i < n; i++)
            sum = sum + a[i] * (n - i - 1) * (int) pow(x, (n - 2 - i));
        
        printf("%d\n", sum);
    }
}
