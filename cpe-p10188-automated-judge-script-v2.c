// Program	: CPE - p10188 Automated Judge Script v2
// Author	: Timothy William
// Compiled	: 03/23/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i, j, k, n, m, solution_wht, input_wht, len, error_count, char_read, case_count, solution_newline[100], input_newline[100], newline_error;
	char solution[100][120], input[100][120], *token, temp_solution[12000], temp_input[12000], delim[2] = " ";

	case_count = 1;
	while(1){
		scanf("%d", &n);
		getchar();

		if(n == 0) break;

		memset(solution, 0, sizeof(solution[0][0]) * 100 * 120);
		memset(input, 0, sizeof(input[0][0]) * 100 * 120);
		memset(solution_newline, 0, 100); // Store location of newline character
		memset(input_newline, 0, 100);

		for(i = 0; i < n; i++){
			fgets(solution[i], 120, stdin);
			solution_newline[i] = strcspn(solution[i], "\n");
			solution[i][strcspn(solution[i], "\n")] = 0;
		}

		scanf("%d", &m);
		getchar();

		for(i = 0; i < m; i++){
			fgets(input[i], 120, stdin);
			input_newline[i] = strcspn(input[i], "\n");
			input[i][strcspn(input[i], "\n")] = 0;
		}

		// Process the input
		memset(temp_solution, 0, 12000);
		memset(temp_input, 0, 12000);
		solution_wht = input_wht = 0; char_read = 0; error_count = 0; newline_error = 0;
		for(i = 0; i < n; i++){
			// Calculate number of white space
			len = strlen(solution[i]);
			for(j = 0; j < len; j++){
				if(solution[i][j] == ' ')
					solution_wht++;

				char_read++;
			}
			
			// Split the strings and append it to a temporary array for comparison
			
			token = strtok(solution[i], delim);
			while(token != NULL){
				strcat(temp_solution, token);
				token = strtok(NULL, delim);
			}
			
			solution_wht++;
		}

		for(i = 0; i < m; i++){
			len = strlen(input[i]);
			for(j = 0; j < len; j++){
				if(input[i][j] == ' ') input_wht++;
			}

			token = strtok(input[i], delim);
			while(token != NULL){
				strcat(temp_input, token);
				token = strtok(NULL, delim);
			}

			input_wht++;
		}

		// Check if there is any mismatch in the text
		if(strcmp(temp_solution, temp_input) != 0) error_count++;

		// Check if '\n' character position is correct
		for(i = 0; i < 100; i++){
			if(solution_newline[i] != input_newline[i]) newline_error++;
		}

		// Print out the verdict
		if(error_count == 0){
			if(solution_wht == input_wht && newline_error == 0)
				printf("Run #%d: Accepted %d\n", case_count, char_read);
			else
				printf("Run #%d: Presentation Error %d\n", case_count, char_read);
		}
		else
			printf("Run #%d: Wrong Answer %d\n", case_count, char_read);

		case_count++;
	}
}
