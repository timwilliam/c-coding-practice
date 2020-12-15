// Program	: CPE - p389 Basically Speaking
// Author	: Timothy William
// Date		: 12/15/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void){
    char buffer[100], input[100], output[7], *token, temp;
    int base, target, in_len, i, base_10, digit, quotient;

    while(fgets(buffer, 100, stdin) != NULL){
        if(buffer[0] == '\n') break;
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        base_10 = 0; memset(input, 0, 100); memset(output, 0, 7);

        //TODO 1. Parse the buffer
        token = strtok(buffer, " ");
        strcpy(input, token); // Get the input number
        token = strtok(NULL, " ");
        base = atoi(token); // Get the base
        token = strtok(NULL, " ");
        target = atoi(token); // Get the target base

        //TODO 2. Convert input number to decimal
        in_len = strlen(input); // Get input char length
        for(i = 0; i < in_len; i++){
                //TODO Convert input that is in 'ABCDE' to a decimal number
                temp = input[in_len - 1 - i];
                if(temp >= '0' && temp <= '9') digit = temp - '0'; // Convert char to decimal number
                else if(temp >= 'A' && temp <= 'F') digit = temp - 'A' + 10;

                base_10 += digit * (int) pow(base, i); //Convert input to base 10
        }

        //TODO 3. Convert decimal to target base
		i = 0;
		while(base_10 > 0){
			quotient = base_10 % target;
			base_10 = base_10 / target;
			
			// Convert to char representation
			if(quotient >= 10) output[i] = quotient - 10 + 'A';
			else output[i] = quotient + '0';

			i++;
			if(i == 7) break; // Exceed 7-digit display limit
		}

		// Print out the conversion result
		if(i == 7){
			printf("ERROR\n");	
			continue;
		}

		while(i >= 0){
			printf("%c", output[i]);
			i--;
		}
		printf("\n");
	}
}
