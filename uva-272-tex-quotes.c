// Program	: UVA 272 - Tex Quotes
// Author	: timwilliam
// Compiled	: 04/13/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char buffer[1000], result[1100], temp[1000];
	int toggle, quote_pos, len, i, j;

	// Initialization
	memset(buffer, 0, sizeof(buffer));
	memset(result, 0, sizeof(result));
	toggle = 0;
	
	while(fgets(buffer, 1000, stdin) != NULL){
		// Processing of the input happens line by line

		memset(temp, 0, sizeof(temp));
		len = strlen(buffer);
		j = 0;

		// Look for " in the buffer, then replace with appropiate quotes
		for(i = 0; i < len; i++){
			// Replace double quote " with single quote '
			if(buffer[i] == '\"'){
				// Left single quote
				if(toggle == 0){
					temp[j] = '`';
					temp[j+1] = '`';

					toggle = 1;
					j += 2;
				}
				// Right single quote
				else{
					temp[j] = '\'';
					temp[j+1] = '\'';

					toggle = 0;
					j += 2;
				}

			}
			else{
				temp[j] = buffer[i];
				j++;
			}
		}
		// Store the modified buffer to the result array
		strcat(result, temp);
	}
	printf("%s", result);
}
