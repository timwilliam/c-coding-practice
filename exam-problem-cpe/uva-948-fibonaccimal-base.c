// Program	: UVA 948 - Fibonaccimal Base
// Author	: timwilliam
// Compiled	: 04/29/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int sequence[100], n_seq, temp, N, threshold, input, flag, toggle, i;
	char ans[100];

	// generate all of the fibo sequence < threshold
	threshold = 100000000; temp = 0; n_seq = -1;
	while(temp < threshold){
		n_seq++;
	
		if(n_seq == 0)
			sequence[n_seq] = 0;
		else if(n_seq == 1)
			sequence[n_seq] = 1;
		else
			sequence[n_seq] = sequence [n_seq - 1] + sequence [n_seq - 2];

		temp = sequence[n_seq];
	}

	scanf("%d", &N);
	while(N--){
		scanf("%d", &input);
		temp = input;

		flag = 0; i = 0; ans[0] = 0; toggle = 0;
		while(temp >= 0 && i <= n_seq && n_seq - i >= 2){
			if(sequence[n_seq - i] <= temp){
				temp = temp - sequence[n_seq - i];
				flag = 1;
				strcat(ans, "1");
			}
			else if(flag == 1){
				strcat(ans, "0");
			}

			i++;
		}	

		printf("%d = %s (fib)\n", input, ans);
		memset(ans, 0, sizeof(ans));
	}
}
