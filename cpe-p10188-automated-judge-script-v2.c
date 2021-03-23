// Program	: CPE - p10188 Automated Judge Script v2
// Author	: Timothy William
// Compiled	: 03/23/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i, j, k, n, m, solution_wht, input_wht, len, error_count, char_read, case_count;
	char solution[100][120], input[100][120], *token, temp_solution[120], temp_input[120], delim[2] = " ";

	case_count = 1;
	while(1){
		scanf("%d", &n);
		getchar();

		if(n == 0) break;

		memset(solution, 0, sizeof(solution[0][0]) * 100 * 120);
		memset(input, 0, sizeof(input[0][0]) * 100 * 120);

		for(i = 0; i < n; i++){
			fgets(solution[i], 120, stdin);
			solution[i][strcspn(solution[i], "\n")] = 0;
		}

		scanf("%d", &m);
		getchar();

		for(i = 0; i < m; i++){
			fgets(input[i], 120, stdin);
			input[i][strcspn(input[i], "\n")] = 0;
		}

		// Process the input
		solution_wht = input_wht = 0; char_read = 0; error_count = 0;
		for(i = 0; i < n; i++){
			// Calculate number of white space
			len = strlen(solution[i]);
			for(j = 0; j < len; j++){
				if(solution[i][j] == ' ')
					solution_wht++;

				char_read++;
			}
			
			len = strlen(input[i]);
			for(j = 0; j < len; j++){
				if(input[i][j] == ' ') input_wht++;
			}
			
			// Split the strings and append it to a temporary array for comparison
			memset(temp_solution, 0, 120);
			memset(temp_input, 0, 120);

			token = strtok(solution[i], delim);
			while(token != NULL){
				strcat(temp_solution, token);
				token = strtok(NULL, delim);
			}
			
			token = strtok(input[i], delim);
			while(token != NULL){
				strcat(temp_input, token);
				token = strtok(NULL, delim);
			}

			// Check if there is any mismatch in the text
			if(strcmp(temp_solution, temp_input) != 0) error_count++;
		}

		// Print out the verdict
		if(error_count == 0){
			if(solution_wht == input_wht)
				printf("Case #%d: Accepted %d\n", case_count, char_read);
			else
				printf("Case #%d: Presentation Error %d\n", case_count, char_read);
		}
		else
			printf("Case #%d: Wrong Answer %d\n", case_count, char_read);

		case_count++;
	}
}
