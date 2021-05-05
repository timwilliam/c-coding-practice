// Problem	: UVA 10235 - Simply Emirp
// Author	: timwilliam
// Compiled	: 05/05/2021

#include <stdio.h>
#include <stdlib.h>

int get_n_factor(int number){
	int n_factor = 0, i;
	
	for(i = 1; i <= number; i++){
		if(number % i == 0)
			n_factor++;
	}

	return n_factor;
}

int main(void){
	int N, i, n_factor, emirp, temp, reverse_prime, remainder;

	while(scanf("%d", &N) != EOF){
		n_factor = 0;

		// check for prime
		n_factor = get_n_factor(N);
		if(n_factor > 2){
			printf("%d is not prime.\n", N);
			continue;
		}

		// if prime, check for emirp
		temp = N;
		reverse_prime = 0;
		while(temp != 0){
			remainder = temp % 10;
			reverse_prime += remainder;
			reverse_prime *= 10;
			temp /= 10;
		}
		reverse_prime /= 10;

		n_factor = get_n_factor(reverse_prime);
		if(n_factor > 2)
			printf("%d is prime.\n", N);
		else
			printf("%d is emirp.\n", N);
	}
}
