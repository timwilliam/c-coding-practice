#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_digit(int N){
	int n_digit = 0;

	while(N > 0){
		N = N / 10;
		n_digit++;
	}

	return n_digit;
}

int* get_new_N(int N, int n_digit){
	int i, j, new_N, *new_N_list, *N_digit, n_pow;

	// store each digit of N in array
	N_digit = malloc(n_digit * sizeof(int));
	for(j = n_digit - 1; j >= 0; j--){
		N_digit[j] = N % 10;
		//printf("[DBG] Got a digit (%d)  %d\n", j, N_digit[j]);
		N = N / 10;	
	}
	
	// remove a digit and iterate through all possible number
	new_N_list = malloc(n_digit * sizeof(int));
	for(i = 0; i < n_digit; i++){
		new_N = 0;
		n_pow = n_digit - 2;
		for(j = 0; j < n_digit; j++){
			if(i == j)
				continue;

			new_N += N_digit[j] * (int) pow(10, n_pow);
			n_pow--;
		}
		
		new_N_list[i] = new_N;
	}	

	free(N_digit);
	return new_N_list;
}

int get_digit_sum(int number, int n_digit){
	int sum, i;

	sum = 0;
	for(i = 0; i < n_digit; i++){
		sum += number % 10;
		number = number / 10;
	}

	return sum;
}

int main(void){
	int i, j, k, temp;
	int turn, N, *new_N_list, n_case, n_digit, sum;

	scanf("%d", &n_case);
	for(i = 0; i < n_case; i++){
		scanf("%d", &N);

		n_digit = get_digit(N);
		if(n_digit == 1){
			printf("Case %d: S\n", i+1);
			continue;
		}

		turn = 1;
		while(n_digit > 0){
			new_N_list = get_new_N(N, n_digit);

			for(j = 0; j < n_digit; j++){
				printf("[DBG] new_N %d: %d\n", j+1, new_N_list[j]);
				sum = get_digit_sum(new_N_list[j], n_digit);

				if(sum % 3 == 0)
					break;
			}

			N = new_N_list[j];
			n_digit = get_digit(N);

			turn++;
		}

		if(turn % 2 == 0)
			printf("Case %d: S\n", i+1);
		else
			printf("Case %d: T\n", i+1);
	}
}
