// Problem  : UVA 10533 - Digit Primes
// Author   : timwilliam
// Compiled : 07/02/2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_sum_of_digit(int num){
    int i, sum;

    sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}   

int main(void){
    int N, t1, t2, i, j, count, sum;
    bool prime[1000000];

    // initialize the prime tables
    prime[0] = prime[1] = false;
    for(i = 2; i < 1000000; i++)
        prime[i] = true;

    for(i = 2; i < 1000000; i++){
        if(prime[i])
            for(j = i+i; j < 1000000; j+=i)
                prime[j] = false;
    }

    // beginning of the meat of the program
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &t1, &t2);
        
        count = 0;
        for(i = t1; i <= t2; i++){
            if(prime[i]){
                sum = get_sum_of_digit(i);
                if(prime[sum])
                    count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}