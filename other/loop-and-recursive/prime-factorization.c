// Problem  : Prime Factorization
// Author   : timwilliam
// Compiled : 07/09/2021

#include <stdio.h>
#include <stdlib.h>

int BOUNDARY = 100000;
int *PRIME;

int *gen_list_of_prime(int boundary){
    int i, j, *list;

    list = malloc(boundary * sizeof(int));

    list[0] = list[1] = 0;
    for(i = 2; i < boundary; i++)
        list[i] = 1;
    
    for(i = 2; i < boundary; i++){
        if(list[i] == 1){
            for(j = i+i; j < boundary; j+=i) 
                list[j] = 0;
        }
    }

    return list;
}

int is_prime(int number){
    return PRIME[number];
}

void get_prime_factorization(int number){
    int i;
    
    while(is_prime(number) == 0){
        i = 2;
        
        // find the next prime number to be the divisor
        while(1){
            if(is_prime(i) && number % i == 0)
                break;

            i++;
        }

        printf("%d ", i);

        // update the quotient as the next number to be calculated
        number = number / i;
    }

    printf("%d\n", number);
    return;
}

int main(void){
    int n;

    // generate list of prime numbers
    PRIME = gen_list_of_prime(BOUNDARY);

    while(scanf("%d", &n) != EOF){
        // results will be printed in ascending order
        get_prime_factorization(n);
    }

    return 0;
}