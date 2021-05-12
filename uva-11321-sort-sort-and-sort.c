// Program	: CPE 11321 - Sort Sort and Sort
// Author	: Timothy William
// Compiled	: 03/20/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int N, M, i, j, k, l, temp[10000], input[10000], n_input;

	while(1){
		memset(input, 0, 10000);
		
		scanf("%d %d", &N, &M);
		getchar();

		for(i = 0; i < N; i++){
			scanf("%d", &input[i]);
			getchar();
		}

		printf("%d %d\n", N, M);
		if(N == 0 && M == 0) break;

		/* 1. Start from modulus that give 0 until M - 1
		 * 2. Then find every number in input, that when modulus with M, produce 0 until M - 1
		 * 3. Then print the result
		 * */

		// For each modulo, starting from 0
		for(i = 0; i < M; i++){
			memset(temp, 0, 10000);
			k = 0;
			
			for(j = 0; j < N; j++){
				if(input[j] % M == i){
					temp[k] = input[j];
					//printf("temp %d\n", temp[k]);
					k++;
				}
			}

			// Odd
			for(l = k; l >= 0; l--){
				if(temp[l] % 2 != 0){
					printf("%d\n", temp[l]);
					temp[l] = 0;
				}				
			}
			// Even
			for(l = 0; l < k; l++){
				if(temp[l] == 0) continue;

				if(temp[l] % 2 == 0){
					printf("%d\n", temp[l]);
					temp[l] = 0;
				}				
			}
		}

	}
}
