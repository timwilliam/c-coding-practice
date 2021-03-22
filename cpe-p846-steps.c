#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main (void){
	int T, x, y, target_range;
	int i, j, n_step, range_covered, inc;

	// Create a table containing range_covered, as well as n_step;
	// - Based on the idea of drawing a pyramid, e.g.:
	// 						range_covered	n_step
	// 			1				1			1
	// 		1	2	1			4			3
	//	1	2	3	2	1		9			5

	// Max range to be covered is 2^31
	
	n_step = 1;
	while(range_covered < 10000){
		inc = 1;
		range_covered = 0;

		for(i = 1; i <= n_step; i++){
			range_covered += inc;
			//printf("- step %d, inc %d, range %d\n", n_step, inc, range_covered);

			if(i >= ((n_step + 1) / 2))
				inc -= 1;
			else
				inc += 1;
		}

		
		n_step += 2;
	}

	printf("n_step %d, range %d\n", n_step, range_covered);
	exit(0);

	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &x, &y);

		target_range = y - x;
		
	}
}
