// Program	: UVA 10093 - An Easy Problem!
// Author	: timwilliam
// Compiled	: 04/28/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	int N, R, t, len, i, j, decimal, power, flag;
	char alpha[62] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char buffer[100];

	while(1){
		fgets(buffer, 100, stdin);
		if(buffer[0] == '0')
			break;

		// trim \n newline
		buffer[strcspn(buffer, "\n")] = 0;

		// find the lowest starting base of N
		N = 0;
		for(i = 0; i < strlen(buffer); i++){
			for(j = 0; j < 62; j++){
				if(buffer[i] == alpha[j])
					if(j > N)
						N = j;
			}
		}
		N += 1;
	
		while(N < 62){
			// convert buffer to decimal
			flag = 0;
			R = 0;
			power = 0;
			for(i = strlen(buffer) - 1; i >= 0; i--){
				for(j = 0; j < 62; j++){
					if(buffer[i] == alpha[j]){
						decimal = j;
						break;
					}
				}
				R += decimal * (int) pow(N, power);
				power++;
			}

			// check if it fulfills the condition
			if(R % (N - 1) == 0 && N <=62){
				printf("%d\n", N);
				break;
			}

			N++;
			
			if(N == 62){
				printf("such number is impossible\n");
				break;
			}
		}

	}
}
