// Program	: UVA 725 - Division
// Author	: Timothy William
// Compiled	: 03/23/2021

#include <stdio.h>
#include <stdlib.h>

int is_distinct(int a, int b){
	int digit_dict[10] = {0}, i, temp;

	if(a < 10000 && b < 10000) return 0;
	if(a < 10000 || b < 10000) digit_dict[0] = 1;

	while(a > 0){
		if(digit_dict[a % 10] == 1) return 0;
		else digit_dict[a % 10] = 1;
		
		a = a / 10;
	}

	while(b > 0){
		if(digit_dict[b % 10] == 1) return 0;
		else digit_dict[b % 10] = 1;
		
		b = b / 10;
	}
	
	return 1;
}

int main(void){
	int N, i, a, b, distinct_flag = 0, n_solution = 0;

	while(1){
		scanf("%d", &N);
		if(N == 0) break;

		// Find a / b = N or a = N * b
		// minimum for b is 01234, while its maximum is 98765
		n_solution = 0;
		for(b = 1234; b <= 49876; b++){
			a = N * b;
			if(a > 98765) continue;

			distinct_flag = is_distinct(a, b);
			if(distinct_flag == 0) continue;
			else{
				if(b < 10000) printf("%d / 0%d = %d\n", a, b, N);
				else printf("%d / %d = %d\n", a, b, N);

				n_solution++;
			}
		}

		if(n_solution == 0) printf("There are no solutions for %d\n", N);
	}
}
