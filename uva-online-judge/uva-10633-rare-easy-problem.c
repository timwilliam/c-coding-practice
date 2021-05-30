// Problem  : UVA 10633 - Rare Easy Problem
// Author   : timwilliam
// Compiled : 05/30/2021

// Note     : Code is not working well for large number, need new algorithm

#include <stdio.h>
#include <stdlib.h>

int main(void){
    unsigned long X, N, M, temp;

    while(1){
        scanf("%ld", &X);
        if(X == 0)
            break;
        
        N = X + 1;
        while(1){
            temp = N - N / 10;

            if(temp > X)
                break;
            
            if(temp == X)
                printf("%ld ", N);
        
            N++;    
        }
        printf("\n");
    }
}
