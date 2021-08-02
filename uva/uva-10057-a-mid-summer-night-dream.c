// Problem	: UVA 10057 - A Mid-summer Night's Dream (v2)
// Author	: timwilliam
// Compiled	: 07/07/2021

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){
	return *(int*) a - *(int*) b;
}

int main(void){
	int n, i, *numbers, median, count, n_possible;

	while(scanf("%d", &n) != EOF){
		numbers = malloc(n * sizeof(int));
		for(i = 0; i < n; i++)
			scanf("%d", &numbers[i]);

		qsort(numbers, n, sizeof(int), cmpfunc);

		count = 0;

		if(n % 2 == 0){
			median = n / 2 - 1;

			for(i = 0; i < n; i++)
				if(numbers[i] == numbers[median] || numbers[i] == numbers[median+1])
					count++;

			n_possible = numbers[median+1] - numbers[median] + 1;
		}
		else{
			median = n / 2;
			
			for(i = 0; i < n; i++)
				if(numbers[i] == numbers[median])
					count++;
			
			n_possible = 1;
		}


		printf("%d %d %d\n", numbers[median], count, n_possible);

		free(numbers);
	}

	return 0;
}
