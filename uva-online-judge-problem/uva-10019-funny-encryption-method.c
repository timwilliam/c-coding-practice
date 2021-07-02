// Problem	: UVA 10019 - Funny Encryption Method
// Authorr	: timwilliam
// Compiled	: 05/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dec_to_bin(int decimal){
	int pwr_lv, temp, b, i;

	// get power level
	pwr_lv = -1;
	temp = 0;
	while(temp < decimal){
		pwr_lv++;
		temp = (int) pow(2, pwr_lv);
	}

	// convert decimal to binary
	b = 0;
	for(i = pwr_lv - 1; i >= 0; i--){
		temp = (int) pow(2, i);

		if(temp <= decimal){
			decimal -= temp;
			//printf("1");
			b++;	
		}
		else{
			//printf("0");
		}
	}
	//printf("\n");
	
	return b;
}

int hex_to_dec(char M[]){
	int decimal, str_len, temp, pwr_lv, i;

	str_len = strlen(M);
	pwr_lv = str_len - 1;
	decimal = 0;
	
	for(i = 0; i < str_len; i++){
		if(M[i] >= 'A' && M[i] <= 'F'){
			temp = M[i] - 'A' + 10;
		}
		else{
			temp = M[i] - '0';
		}

		decimal += temp * (int) pow(16, pwr_lv);
		pwr_lv--;
	}

	return decimal;
}

int main(void){
	int N, pwr_lv, decimal, temp, i, b;
	char M[5];

	scanf("%d", &N);
	getchar();

	while(N--){
		memset(M, 0, sizeof(M));
		fgets(M, 5, stdin);
		M[strcspn(M, "\n")] = 0;

		// Solve for the decimal representation of M first
		decimal = atoi(M);
		b = dec_to_bin(decimal);
		printf("%d ", b);

		// Solve for the hex representation of M
		decimal = hex_to_dec(M);
		b = dec_to_bin(decimal);
		printf("%d\n", b);

		getchar();
	}
}
