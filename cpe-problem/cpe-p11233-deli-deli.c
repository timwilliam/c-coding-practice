// Program	: CPE - p11233 Deli Deli
// Author	: Timothy William
// Compiled	: 03/19/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int L, N, i, j, irr_flag, in_len;
	char irr_sngl[20][20], irr_plural[20][20], input[100][20];

	scanf("%d %d", &L, &N);
	getchar();

	// Store the irregular form of words entered
	for(i = 0; i < L; i++){
		scanf("%s %s", irr_sngl[i], irr_plural[i]);
		getchar();
	}

	// Get user input
	for(i = 0; i < N; i++){
		scanf("%s", input[i]);
		getchar();
	}

	// Correct and display the plural form of words
	for(i = 0; i < N; i++){
		// Check if its an irregular word
		irr_flag = 0;
		for(j = 0; j < L; j++){
			if(strcmp(irr_sngl[j], input[i]) == 0){
				irr_flag = 1;	
				break;
			}
		}

		// Case 1: Plural form of an irregular word
		if(irr_flag == 1){
			printf("%s\n", irr_plural[j]);
			continue;
		}
	
		in_len = strlen(input[i]);

		// TODO: Might be better to update the word in the array directly
		// 			rather than fixing it during printf()

		// Case 1: Replace "y" with "ies"
		if(input[i][in_len - 1] == 'y' && 
				(input[i][in_len - 2] != 'a' && input[i][in_len - 2] != 'e' && input[i][in_len - 2] != 'i' &&
				 input[i][in_len - 2] != 'o' && input[i][in_len - 2] != 'u')){
			input[i][in_len - 1] = 0;
			printf("%sies\n", input[i]);
		}
		// Case 2: Append "es"
		else if(input[i][in_len - 1] == 'o' || input[i][in_len - 1] == 's' || input[i][in_len - 1] == 'x') 
			printf("%ses\n", input[i]);
		else if((input[i][in_len - 2] == 'c' && input[i][in_len - 1] == 'h') || 
			(input[i][in_len - 2] == 's' && input[i][in_len - 1] == 'h'))
			printf("%ses\n", input[i]);
		// Case 3: Append "s"
		else
			printf("%ss\n", input[i]);
	}
}
