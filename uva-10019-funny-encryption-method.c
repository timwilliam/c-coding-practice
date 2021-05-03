#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dec_to_bin(){

}

int main(void){
	int N, pwr_lv, decimal, temp, i, b;
	char M[4];

	scanf("%d", &N);
	getchar();

	while(N--){
		memset(M, 0, sizeof(M));
		fgets(M, 4, stdin);

		decimal = atoi(M);

		// 1. Solve for the decimal representation of M first
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
		
		printf("%d\n", b);

		// 2. Solve for the hex representation of M
		// convert hex to decimal first
		decimal = 0;	

	}
}
