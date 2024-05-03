#include <stdio.h>

// sum inclusively from start to end
int sum(int start, int end) {
	int i, sum = 0;
	
	for(i = start; i <= end; i++) {
		sum += i;
	}

	return sum;
}

int pivotInteger(int n) {
	int sumLeft, sumRight = 0;
	int idx = n / 2;
	
	sumLeft = sum(1, idx);
	sumRight = sum(idx, n);

	// keep compare sumLeft of idx, with sumRight of idx
	// increment idx by 1 in every iteration
	while(1) {
		// printf("idx = %d\n", idx);
		// printf("sumLeft = %d\n", sumLeft);
		// printf("sumRight = %d\n", sumRight);

		if(sumLeft == sumRight) {
			return idx;
		}
		else if(sumLeft > sumRight) {
			return -1;
		}
		else {
			idx++;
			sumLeft = sum(1, idx);
			sumRight = sum(idx, n);
		}
	}
}

int main(void) {
	// int n = 8;
	// int n = 4;
	int n = 1;

	printf("%d\n", pivotInteger(n));

	return 0;	
}
