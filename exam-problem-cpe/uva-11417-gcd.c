// Problem	: UVA 11417 - GCD
// Author	: timwilliam
// Compiled	: 05/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int i, int j){
	int gcd, i_factor[1000], j_factor[1000], k, l, n_factor_i, n_factor_j;
	memset(i_factor, 0, sizeof(i_factor));
	memset(j_factor, 0, sizeof(j_factor));

	// NOTE: Might not be the most efficient GCD algorithm

	// get the factor of i and j
	n_factor_i = 0;
	for(k = 1; k <= i; k++){
		if(i % k == 0){
			i_factor[n_factor_i] = k;
			n_factor_i++;
		}
	}

	n_factor_j = 0;
	for(k = 1; k <= j; k++){
		if(j % k == 0){
			j_factor[n_factor_j] = k;
			n_factor_j++;
		}
	}

	// calculate gcd
	gcd = 1;
	for(k = 1; k <= n_factor_i; k++){
		for(l = 1; l <= n_factor_j; l++){
			if(i_factor[k] == j_factor[l]){
				if(gcd <= i_factor[k]){
					gcd = i_factor[k];
				}
			}
		}
	}

	return gcd;
}

int main(void){
	int N, G, i, j;

	while(1){
		scanf("%d", &N);
		if(N == 0)
			break;

		G = 0;
		for(i = 1; i < N; i++){
			for(j = i + 1; j <= N; j++){
				G += GCD(i, j);
			}
		}

		printf("%d\n", G);
	}
}
