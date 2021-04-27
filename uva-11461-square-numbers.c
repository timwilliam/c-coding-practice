// Program	: UVA 11461 - Square Numbers
// Author	: timwilliam
// Compiled	: 04/27/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int i, count, a, b;
	double temp;

	while(1){
		scanf("%d %d", &a, &b);

		if(a == 0 && b == 0)
			break;

		count = 0;
		for(i = a; i <= b; i++){
			temp = sqrt(i);
			if(temp == (int) temp)
				count++;
		}

		printf("%d\n", count);
	}
}
