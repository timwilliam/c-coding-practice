// Program	: CPE - p1583 Digit Generator
// Author	: timwilliam
// Compiled	: 12/21/2020

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	int T, N, result, n_digits, temp, i, lower_bound, M, temp2;
	
	scanf("%d", &T);
	while(T > 0){
		scanf("%d", &M);
		
		//Get the number of digits in the integer
		temp = M; n_digits = 0;
		while(temp > 0){
			temp = temp / 10;
			n_digits++;
		}
		
		//Calculate the generator
		lower_bound = (int) pow(10, n_digits-1);
		temp = M; result = M + 1;
		while(temp >= lower_bound){
			N = temp; temp2 = temp;
			while(temp2 > 0){
				N += temp2 % 10;
				temp2 = temp2 / 10;
			}

			if(N == M){
				if(temp < result) result = temp;
			}

			temp--;
		}

		if(result > M) printf("0\n");	
		else printf("%d\n", result);

		T--;
	}
}
