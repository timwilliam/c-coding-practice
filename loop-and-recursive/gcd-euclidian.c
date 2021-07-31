// Problem  : GCD Calculator Using Euclidian Algorithm
// Author   : timwilliam
// Compiled : 07/31/2021

#include <stdio.h>
#include <stdlib.h>

int get_gcd(int a, int b){
    int r, prev_r;

    r = a % b;
    prev_r = b;
    
    while(r > 0){
        //printf("[DBG] %d = %d x %d + %d\n", a, b, a/b, r);
        a = b;
        b = r;
        
        prev_r = r;
        r = a % b;
    }

    return prev_r;
}

int main(void){
    int a, b;

    // assume a >= b
    //a = 3768; b = 1701; 
    a = 45; b = 7; 
    printf("%d\n", get_gcd(a, b));

    return 0;
}