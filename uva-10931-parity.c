// Problem	: UVA 10931 - Parity
// Author	: timwilliam
// Compiled	: 05/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dec_to_bit_count(int decimal){
	int pwr_lv, i, temp, bit_count;
	
	pwr_lv = -1;
	temp = 0;
	bit_count = 0;

	// get the pwr_lv;
	while(temp <= decimal){
		pwr_lv++;
		temp = (int) pow(2, pwr_lv);
	}

	// convert to binary and count the bits
	for(i = 0; i < pwr_lv; i++){
		temp = (int) pow(2, pwr_lv - 1 - i);

		if(temp <= decimal){
			bit_count++;
			decimal -= temp;
			printf("1");
		}
		else{
			printf("0");
		}		
	}
	printf(" ");

	return bit_count;
}

int main(void){
	int I, sum_of_bits;

	while(1){
		sum_of_bits = 0;
		
		scanf("%d", &I);
		if(I == 0)
			break;
		else if(I == 1){
			printf("The parity of 1 is 1 (mod 2).\n");
			continue;
		}

		
		printf("The parity of ");
		sum_of_bits = dec_to_bit_count(I);

		// count & print the parity
		printf("is %d (mod 2).\n", sum_of_bits);
	}
}
