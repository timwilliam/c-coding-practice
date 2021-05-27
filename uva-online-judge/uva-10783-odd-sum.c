// Problem	: UVA 10783 - Odd Sum
// Author	: timwilliam
// Compiled	: 04/22/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j, a, b, T, sum;
	
	scanf("%d", &T);

	for(i = 0; i < T; i++){
		scanf("%d", &a);	
		scanf("%d", &b);

		sum = 0;
		for(j = a; j <= b; j++){
			if(j % 2 == 0)
				continue;

			sum += j;
		}

		printf("Case %d: %d\n", i + 1, sum);
	}
}
