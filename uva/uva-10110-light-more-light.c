// Problem  : UVA 10110 - Light More Light
// Author   : timwilliam
// compiled : 08/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    unsigned long int i, n, root;
    int state;
    
    while(1){
        scanf("%ld", &n);
        if(n == 0)
            break;

        root = sqrt(n);
        if(root * root == n)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}