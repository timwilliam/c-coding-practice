// Program	: CPE - p11220 Decoding the Message
// Author	: Timothy William
// Compiled	: 03/21/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int T, N, M;
	int i, j, k, n_line, n_letter;
	char input[100][1000], result[1000], *token, delim[2] = " ";

	scanf("%d", &T);
	printf("%c", getchar());

	for(i = 1; i <= T; i++){
		memset(input, 0, sizeof(input[0][0]) * 100 * 1000);

		// Get the input for each line
		n_line = 0;
		while(1){
			fgets(input[n_line], 1000, stdin);

			if(strlen(input[n_line]) == 1 && strcmp(input[n_line], "\n") == 0)
				break; // Exit when empty line is inputted
			else{
				input[n_line][strcspn(input[n_line], "\n")] = 0; // remove \n character
				n_line++;
			}
		}

		printf("Case #%d\n", i);

		for(j = 0; j < n_line; j++){
			memset(result, 0, 1000);
			token = strtok(input[j], delim); // use strtok() to get each words		
			n_letter = 0;
			
			while(token != NULL){
				// Get each letter in the encoded message
				if(strlen(token) >= n_letter + 1){
					result[n_letter] = token[n_letter];		
					n_letter++;
				}

				token = strtok(NULL, delim);
			}

			printf("%s\n", result);
		}
	
		printf("\n");	
	}
}
