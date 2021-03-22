#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
	int T, x, y, range, i, sum, n_step, increment;

	range = 4;

	n_step = 1;
	for(i = 2; i <= range; i++){
		n_step = n_step + 2; 
	}
	//printf("n_step %d\n", n_step);
	
	sum = 0; increment = 1;
	for(i = 0; i < n_step; i++){
		sum += increment;
	
		//printf("increment %d\n", increment);	
		if(i >= ((n_step + 1) / 2) - 1)
			increment -= 1;
		else
			increment ++;

		//printf("i = %d, sum = %d\n", i, sum);
	}

	printf("sum %d\n", sum);

	
	exit(0);
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &x, &y);

		range = y - x;
		//range = 5;

	}
}
