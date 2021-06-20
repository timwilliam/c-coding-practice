// Problem  : Partition n objects using parts up to m
// Author   : timwilliam
// Compiled : 06/20/2021
// Tag      : recursive

#include <stdio.h>
#include <stdlib.h>

int count_partition(int n, int m){
    if(n == 0)
        return 1;
    else if(m == 0 || n < 0)
        return 0;

    return count_partition(n-m, m) + count_partition(n, m-1);
}

int main(void){
    int n, m;

    while(1){
        scanf("%d %d", &n, &m);

        if(n == -1 && m == -1)
            break;

        printf("%d\n", count_partition(n, m));
    }
}
