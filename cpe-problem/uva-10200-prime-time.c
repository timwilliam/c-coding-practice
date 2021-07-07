// Problem 	: UVA 10200 - Prime Time
// Author	: timwilliam
// Compiled	: 06/27/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_prime(int number){
	int i, count;

	if(number % 2 == 0)
		return 0;

	count = 0;
	for(i = 1; i <= number; i++){
		if(number % i == 0)
			count++;

		if(count > 2)
			break;
	}

	if(count == 2)
		return 1;
	else
		return 0;
}

int main(void){
	int a, b, i, j, *number, prime_count, range, memory[10000] = {0};
	double percentage;

	memset(memory, -1, sizeof(memory));
	while(1){
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)
			break;

		// calculate the number based on the formula
		range = b - a + 1;
		number = malloc(range * sizeof(int));
		prime_count = 0;
		j = 0;
		for(i = a; i <= b; i++){
			printf("[DBG] Now at i = %d\n", i);
			number[j] = i * i + i + 41;

			// check if the generated number is prime or not, then save to memory
			if(memory[i] == -1){
				if(is_prime(number[j])){
					memory[i] = 1;
					prime_count++;
				}
				else
					memory[i] = 0;

				//printf("number = %d, no memory, stats %d\n", number[j], memory[i]);
			}
			else{
				//printf("number = %d, has memory, stats %d\n", number[j], memory[i]);
				if(memory[i] == 1)
					prime_count++;
			}

			j++;	
		}
		
		// calculate the percentage
		percentage = (double) prime_count / (double) range * 100.0;
		printf("%.2lf\n", percentage);

		free(number);
	}
}
