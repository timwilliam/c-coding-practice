// Problem  : Compute the factorial value of n
// Author   : timwilliam
// Compiled : 06/19/2021
// Tag      : recursive

#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n == 1)
        return 1;

    return n * factorial(n-1);
}

int main(void){
    int n;

    while(1){
        scanf("%d", &n);
        
        if(n == 0)
            break;

        printf("%d\n", factorial(n));
    }
}
