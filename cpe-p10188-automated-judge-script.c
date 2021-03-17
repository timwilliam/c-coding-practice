// Program	: CPE - p10188 Automated Judge Script
// Author	: Timothy William
// Compiled	: 03/17/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, m, i, j, k, len, err_count, char_read, temp, run, sol_wht_count, output_wht_count;
	char solution[100][120], team_output[100][120], temp_sol[120], temp_output[120];
	
	run = 0;
	while(1){
		run++;

		// Reset the array
		memset(solution, 0, sizeof(solution[0][0]) * 100 * 120);
		memset(team_output, 0, sizeof(team_output[0][0]) * 100 * 120);

		// Store the input for the solution
		scanf("%d", &n);
		getchar(); // To trim the newline before fgets

		// Exit if input is 0
		if(n == 0) break;

		i = 0;
		temp = n;
		while(temp--){
			fgets(solution[i], 100, stdin);
			solution[i][strcspn(solution[i], "\n")] = 0; // Trim new line
			//printf("solution: %s", solution[i]);
			i++;
		}
	
		// Store the input for the team output
		scanf("%d", &m);
		getchar(); // To trim the newline before fgets

		i = 0;
		temp = m;
		while(temp--){
			fgets(team_output[i], 100, stdin);
			team_output[i][strcspn(team_output[i], "\n")] = 0; // Trim new line
			i++;
		}
	
		err_count = 0; char_read = 0;
		sol_wht_count = 0; output_wht_count = 0;

		// Check algorithm
		// - Read all the character in the string
		// - When reading, remove white space
		// - Then check if solution and team_output is equal by using strcmp()

		i = 0;
		while(1){
			memset(temp_sol, 0, 120);
			memset(temp_output, 0, 120);
			
			len = strlen(solution[i]);
			j = 0;

			// Check solution
			while(len--){
				if(solution[i][len] == ' '){
					sol_wht_count++;
				}
				else{
					temp_sol[j]	= solution[i][len];
					j++;
				}

				char_read ++;
			}

			// Check team_output
			len = strlen(team_output[i]);
			j = 0;
			while(len--){
				if(team_output[i][len] == ' '){
					output_wht_count++;
				}
				else{
					temp_output[j]	= team_output[i][len];
					j++;
				}
			}
			
			if(strcmp(temp_sol, temp_output) != 0) err_count ++;

			i++;
			if(i == n) break;
		}

		//printf("sol %d, output %d\n", sol_wht_count, output_wht_count);		
		// TODO: Implement algorithm to properly check when n != m
		// TODO: Implement algorithm to properly check for Presentation Error case, now, as long as white space count is the same, it will always counted as Accepted eventhough it should be clearly marked as Presentation Error

		// Print the verdict
		if(err_count == 0){
			if(sol_wht_count != output_wht_count)
				printf("Run #%d: Presentation Error %d\n", run, char_read);
			else 
				printf("Run #%d: Accepted %d\n", run, char_read);
		}
		else printf("Run #%d: Wrong Answer %d\n", run, char_read);
	}
}
