// Program	: CPE - p11960 Divisor Game
// Author	: timwilliam
// Compiled	: 12/25/2020

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, T, i, j, count, candidate[2];
	scanf("%d", &T);
	
	while(T > 0){
		scanf("%d", &N);
		
		candidate[0] = 0; // 0: For storing which number currently holds the most divisor
		candidate[1] = 0; // 1: For storing the count of the divisor a number has

		// Check from 3 to N
		for(i = N; i > 0; i--){
			count = 0;
			// Check from i down to 1, how many divisor does i has
			for(j = i; j > 0; j--){
				if(i % j == 0) count++;	
			}

			// Update the candidate
			if(count > candidate[0]){
				candidate[0] = count;
				candidate[1] = i;
			}
		}
		printf("%d\n", candidate[1]);
		T--;
	}
}
