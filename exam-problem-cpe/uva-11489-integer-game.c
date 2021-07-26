#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int T, str_len, i, j, k, sum, *N_digit, counter;
	char N[1000] = {0};

	scanf("%d", &T);
	for(i = 1; i <= T; i++){
		sum = 0;
		counter = 0;
		memset(N, 0, sizeof(N));

		scanf("%s", N);
		str_len = strlen(N);
		N_digit = malloc(str_len * sizeof(int));
		
		// store each digit in an array, and count the sum of digits
		for(j = 0; j < str_len; j++){
			N_digit[j] = N[j] - '0';
			sum += N_digit[j];
		}

		// count how many digits is divisible by 3
		for(j = 0; j < str_len; j++){
			if(N_digit[j] % 3 == 0)
				counter++;
		}
		
		// 3 possible conditions
		if(sum % 3 == 0){ // 1
			// can only substract for (counter) amount of times
			if(counter % 2 == 0)
				printf("Case %d: T\n", i);
			else
				printf("Case %d: S\n", i);
		}
		else{
			for(j = 0; j < str_len; j++){
				if((sum - N_digit[j]) % 3 == 0){ // 2
					if(counter % 2 == 0)
						printf("Case %d: S\n", i);
					else
						printf("Case %d: T\n", i);
					
					break;
				}
				else if(j == str_len - 1){ // 3
					printf("Case %d: T\n", i);
				}
			}
		}
		
		free(N_digit);
	}
}
