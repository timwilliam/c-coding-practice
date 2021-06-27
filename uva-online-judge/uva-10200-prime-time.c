#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int number){
	int i, count;

	count = 0;
	for(i = 1; i <= number; i++){
		if(number % i == 0)
			count++;
	}

	if(count == 2)
		return 1;
	else
		return 0;
}

int main(void){
	int a, b, i, j, *number, prime_count, range;
	double percentage;

	while(1){
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)
			break;

		// calculate the number based on the formula, and check if it is a prime number
		range = b - a + 1;
		number = malloc(range * sizeof(int));
		prime_count = 0;
		j = 0;
		for(i = a; i <= b; i++){
			number[j] = i * i + i + 41;
			
			if(is_prime(number[j]))
				prime_count++;

			j++;	
		}
		
		// calculate the percentage
		percentage = (double) prime_count / (double) range * 100.0;
		printf("%.2lf\n", percentage);

		free(number);
	}
}
