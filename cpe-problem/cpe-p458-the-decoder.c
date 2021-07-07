// Program	: CPE - p458 The Decoder
// Author	: Timothy William
// Compiled	: 12/15/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	// The number of the shift in the ASCII code, manually check by printing the ASCII code number
	// e.g.: '1' - '*' = 7
	int key = 7;

	int len, i;
	char buffer[100];

	while(fgets(buffer, 100, stdin) != NULL){
		if(buffer[0] == '\n') break;
		buffer[strcspn(buffer, "\n")] = 0;

		// Get the input string length
		len = strlen(buffer);

		// Decode the message
		for(i = 0; i < len; i++){
			printf("%c", buffer[i] - key);
		}
		printf("\n");
	}
}
