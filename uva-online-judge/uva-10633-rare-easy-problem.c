// Problem  : UVA 10633 - Rare Easy Problem
// Author   : timwilliam
// Compiled : 06/01/2021 (solution v2)

#include <stdio.h>
#include <stdlib.h>

int main(void){
    unsigned long X, N, M, remainder;

    while(1){
        scanf("%ld", &X);
        if(X == 0)
            break;

        // X = 9N / 10
        N = (X * 10) / 9;
        remainder = (X * 10) % 9;

        if(remainder == 0)
            printf("%ld %ld\n", N-1, N);
        else
            printf("%ld\n", N);
    }
}
