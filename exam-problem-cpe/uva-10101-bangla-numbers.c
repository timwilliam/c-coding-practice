// Problem  : UVA 10101 - Bangla Numbers
// Author   : timwilliam
// Compiled : 05/17/2021

#include <stdio.h>
#include <stdlib.h>

void bangla(unsigned long long number){
    if(number >= 10000000){
        bangla(number / 10000000);
        printf(" kuti");
        number %= 10000000;
    }
    
    if(number >= 100000){
        bangla(number / 100000);
        printf(" lakh");
        number %= 100000;
    }

    if(number >= 1000){
        bangla(number / 1000);
        printf(" hajar ");
        number %= 1000;
    }

    if(number >= 100){
        bangla(number / 100);
        printf(" shata");
        number %= 100;
    }

    if(number)
        printf(" %llu", number);

    return;    
}

int main(void){
    int i;
    unsigned long long n;

    i = 1;
    while(scanf("%llu", &n) != EOF){
        if(n == 0){
            printf("%d. %llu\n", i, n);
        }

        printf("%4d. ", i);        
        bangla(n);
        printf("\n");
        i++;
    }
}
