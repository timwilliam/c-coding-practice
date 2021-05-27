// Program	: UVA 10929 - You can say 11
// Author	: Timothy William
// Compiled	: 03/28/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, divisor = 11;

	while(1){
		scanf("%d", &N);
		if(N == 0) break;

		if(N % divisor == 0) printf("%d is a multiple of %d.\n", N, divisor);
		else printf("%d is not a multiple of %d.\n", N, divisor);
	}
}
