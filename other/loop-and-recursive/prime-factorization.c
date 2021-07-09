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

int get_prime_factorization(int number, int *result){
    int i, n_factor = 0;
    
    while(is_prime(number) == 0){
        i = 2;
        
        // find the next prime number to be the divisor
        while(1){
            if(is_prime(i) && number % i == 0)
                break;
            
            i++;
        }

        result[n_factor] = i;
        n_factor++;
        printf("%d, ", i);
        
        // update the quotient as the next number to be calculated
        number = number / i;
    }

    printf("%d\n", number);
    result[n_factor] = number;
    n_factor++;

    return n_factor;
}

int count_n_possible_factor(int *prime_factor, int n_factor){
    int i, count = 1, temp, prev;

    prev = prime_factor[0];
    temp = 0;
    for(i = 0; i < n_factor; i++){

        if(prev == prime_factor[i]){
            temp++;
        }
        else{
            count *= temp+1;
            temp = 1;
            prev = prime_factor[i];
        }
    }

    count *= temp+1;

    return count;
}

int main(void){
    int n, n_factor, prime_factor[100];

    // generate list of prime numbers
    PRIME = gen_list_of_prime(BOUNDARY);

    // works for n >= 2
    while(scanf("%d", &n) != EOF){
        // results will be printed in ascending order
        printf("Prime Factorization: ");
        n_factor = get_prime_factorization(n, prime_factor);
        //printf("Number of possible factors = %d\n", count_n_possible_factor(prime_factor, n_factor));
    }

    return 0;
}