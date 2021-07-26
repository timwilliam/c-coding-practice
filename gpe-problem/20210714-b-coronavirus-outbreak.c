// Problem  : GPE Exam 20210714 Problem B - Coronavirus Outbreak
// Author   : timwilliam
// Compiled : 07/26/2021

// TODO: Need more work and change the code to use biginteger mode for super large int input

#include <stdio.h>
#include <stdlib.h>

int infection(int x, int r, int b){
    if(x == 0)
        return 1;

    return r * infection(x - 1, r, b) + b;
}

int main(void){
    int n, r, b, x;

    scanf("%d %d %d", &n, &r, &b);
    while(n--){
        scanf("%d", &x);
        printf("%d\n", infection(x, r, b));
    }

    return 0;
}