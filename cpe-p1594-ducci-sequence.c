// Program	: CPE - p1594 Ducci Sequence
// Author	: Timothy William
// Compiled	: 03/22/2021

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	int T, n, i, input[15], temp[15], steps_limit = 1000, steps, tuple_sum;

	scanf("%d", &T);

	while(T--){
		memset(input, 0, sizeof(input));

		scanf("%d", &n);
		
		for(i = 0; i < n; i++){
			scanf("%d", &input[i]);
		}	
	
		for(steps = 0; steps < steps_limit; steps++){
			tuple_sum = 0;
			memset(temp, 0, 15);

			// Perform Ducci Sequence calculation
			for(i = 0; i < n; i++){
				if(i + 1 == n)
					temp[i] = abs(input[i] - input[0]);
				else
					temp[i]	= abs(input[i] - input[i+1]);		

				tuple_sum += temp[i];
			}

			// Update the original input array to carry in the Ducci Sequence calculation
			memcpy(input, temp, 15 * sizeof(int));

			if(tuple_sum == 0) break; // Stop early if ZERO condition is met
		}

		if(tuple_sum == 0) printf("ZERO\n");
		else printf("LOOP\n");
	}
}
