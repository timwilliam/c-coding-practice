// Program  : CPE - p11689 Soda Surpler
// Author   : timwilliam
// Compiled : 12/23/2020

#include<stdio.h>
#include<stdlib.h>

int main(){
    int N, e, f, c, temp, total;
    scanf("%d", &N);
    while(N > 0){
        scanf("%d %d %d", &e, &f, &c);
        
        total = 0;
        while(e + f >= c){
            temp = e + f;
            e = temp / c;
            f = temp % c;
            
            total += e;
        }
        printf("%d\n", total);
        N--;
    }
}
