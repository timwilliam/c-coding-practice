// Problem	: UVA 499 - What's The Frequency, Kenneth?
// Author	: timwilliam
// Compiled	: 06/27/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char input[1000] = {0};
	int char_count[52] = {0}, str_len, i, max = 0;

	while(fgets(input, 1000, stdin) != NULL){
		str_len = strlen(input);

		// count frequencies of each char
		for(i = 0; i < str_len; i++){
			if(input[i] >= 65 && input[i] <= 90){
				char_count[input[i] - 65]++;
			}
			else if(input[i] >= 97 && input[i] <= 122){
				char_count[input[i] - 97 + 26]++;
			}
		}

		// get the char with highest frequencies
		for(i = 0; i < 52; i++){
			if(char_count[i] >= max)
				max = char_count[i];
		}

		// print all char with the highest frequencies
		for(i = 0; i < 52; i++){
			if(char_count[i] == max){
				if(i >= 0 && i < 26)
					printf("%c", 65+i);
				else{
					printf("%c", 97+i-26);
				}
			}
		}

		printf(" %d\n", max);

		memset(char_count, 0, sizeof(char_count) / sizeof(char_count[0]) * sizeof(int));
		memset(input, 0, sizeof(input) / sizeof(input[0]) * sizeof(char));
		max = 0;
	}
}
