#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, m, i, j, k, len, err_count, char_read, temp, run, sol_wht_count, output_wht_count;
	char solution[100][120], team_output[100][120];
	
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

		// Check algorithm
		err_count = 0; char_read = 0;
		sol_wht_count = 0; output_wht_count = 0;
		for(i = 0; i < n; i++){
			len = strlen(solution[i]);

			j = 0; k = 0;
			while(1){
				if(j == len) break;

				// Count how many white space are there
				if(solution[i][j] == ' ') sol_wht_count++;
				if(team_output[i][k] == ' ') output_wht_count++;
	
							
				if(solution[i][j] != team_output[i][k]){
					while(team_output[i][k] != ' '){
						output_wht_count++;
						k++;
					}

					if(solution[i][j] != team_output[i][k])				
						err_count++;
				}

				j++; k++; char_read++;
			}
			
			printf("whte sol %d, whte output %d\n", sol_wht_count, output_wht_count);
		}

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
