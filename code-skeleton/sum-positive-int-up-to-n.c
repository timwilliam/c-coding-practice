// Problem	: Recursive function that given an input n, sums all nonnegative integers up to n
// Author	: timwilliam
// Compiled	: 06/18/2021
// Tag		: recursive

#include <stdio.h>
#include <stdlib.h>

int get_sum(int n){
	int sum;
	if(n == 1)
		return 1;
	else{
		sum = n + get_sum(n - 1);
		return sum;
	}
}

int main(void){
	int n, sum;

	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		else{
			sum = get_sum(n);
			printf("n = %d, sum up to n = %d\n", n, sum);
		}
	}
}
