// Program	: UVA 100 - The 3n + 1 problem
// Author	: Timothy William
// Compiled	: 03/28/2021

#include <stdlib.h>
#include <stdio.h>

int main(void){
	int i, j, k, cycle_len, n, max_cycle_len;
	
	while(scanf("%d %d", &i, &j) != EOF){
		max_cycle_len = 1;
		
		for(k = i; k <= j; k++){
			n = k;
			cycle_len = 1;

			// Calculate cycle length based on given algorithm
			while(n != 1){
				if(n % 2 == 0) n = n / 2;
				else n = 3 * n + 1;

				cycle_len++;
			}

			if(cycle_len >= max_cycle_len) max_cycle_len = cycle_len;
		}

		printf("%d %d %d\n", i, j, max_cycle_len);
	}
}
