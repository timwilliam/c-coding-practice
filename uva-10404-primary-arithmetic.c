// Program	: UVA 10035 - Primary Arrithmetic
// Author	: Timothy William
// Compiled	: 03/27/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i, a, b, num_carry, carry, n_digits, temp_a, temp_b, sum;
	char buffer[20], *token, delim[2] = " ";

	while(1){
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, 20, stdin);

		// Get the first number
		token = strtok(buffer, delim);
		n_digits = strlen(token);
		a = atoi(token);

		// Get the second number
		token = strtok(NULL, delim);
		if(n_digits < strlen(token)) n_digits = strlen(token);
		b = atoi(token);

		// Exit condition
		if(a == 0 & b == 0)
			break;

		// Check the number of carry
		temp_a = a;
		temp_b = b;
		carry = 0;
		num_carry = 0;
		for(i = 0; i < n_digits; i++){
			sum = (temp_a % 10) + (temp_b % 10) + carry;

			// Check if there is a carry
			if(sum >= 10){
				num_carry++;
				carry = 1;
			}
			else{
				carry = 0;
			}

			temp_a = temp_a / 10;
			temp_b = temp_b / 10;
		}

		if(num_carry == 0) 
			printf("No carry operation.\n");
		else if(num_carry == 1)
			printf("%d carry operation.\n", num_carry);
		else
			printf("%d carry operations.\n", num_carry);
	}
}
