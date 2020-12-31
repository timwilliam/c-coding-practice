// Program	: CPE - p11960 Divisor Game v3
// Author	: timwilliam
// Compiled	: 12/31/2020

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, T, i, j, count, candidate[2], memory[1000000] = {0}; 
	//scanf("%d", &T);

	int check = 0;

	// For benchmark
	T = 6;
    int N_bench[6] = {999999, 95473, 389384, 9234, 101, 514};

	while(T > 0){
		N = N_bench[T-1];
		//scanf("%d", &N);
		
		candidate[0] = 0; // 0: For storing the count of how many divisor a number has
		candidate[1] = 0; // 1: For storing the number currently being process

		// Check from N to 1
		for(i = N; i > 0; i--){
			count = 0;
			
			// memory = 1: Result has been calculated before and stored in memory
			// memory = 0: Result does not exist yet
			if(memory[i-1] == 0){
				// Check from i down to 1, how many divisor does i has
				for(j = i; j > 0; j--){
					if(i % j == 0) count++;	
				}
				memory[i-1] = count;
				check++;
			}
			else{
				count = memory[i-1];
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
