// Problem	: For a grid of size n x m, output the number of unique paths from top left to bottom right
// 			  - Can only move down or right 1 unit at a time
// Author	: timwilliam
// Compiled	: 06/18/2021
// Tag		: recursive

#include <stdio.h>
#include <stdlib.h>

int grid_paths(int n, int m){
	int sum;

	if(n == 1 || m == 1)
		return 1;
	
	sum = grid_paths(n, m -1) + grid_paths(m, n - 1);
	return sum;
}

int main(void){
	int n, m, sum;

	while(1){
		scanf("%d %d", &n, &m);

		if(n <=0 || m <= 0)
			break;

		sum = grid_paths(n, m);
		printf("For (%d,%d), we have %d unique paths\n", n, m, sum);
	}
}
