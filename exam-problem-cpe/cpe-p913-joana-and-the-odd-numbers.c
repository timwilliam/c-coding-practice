// Program	: CPE - p913 Joana and the Odd Numbers
// Author	: Timothy William
// Compiled	: 03/20/2021

#include <stdlib.h>
#include <stdio.h>

int main(void){
	// N can be up to 10^9, so unsigned long long it is
	unsigned long long int N, level, n_odd_nmbr, total_odd_nmbr, i, sum;

	while(scanf("%llu", &N) != EOF){
		level = 1;
		total_odd_nmbr = 1;
		sum = 0;

		// Get the number of level
		// - Reminiscence of drawing a pyramid with star * problem
		while(1){
			n_odd_nmbr = 1 + 2 * level;

			// Total number of digits up until level N
			total_odd_nmbr += n_odd_nmbr;

			if(n_odd_nmbr == N) break;
			else level++;
		}

		// Only need 3 last odd number, 3 can be replace with a variable if needed
		for(i = 0; i < 3; i++){
			// its like counting up to total_odd_number
			// e.g.:	 1	3	5	7
			//		idx	 1	2	3	4
			//			 2 * idx - 1 will yield us the odd number above
			sum = sum + ((total_odd_nmbr - i) * 2) - 1;
		}

		printf("%llu\n", sum);
	}
}
