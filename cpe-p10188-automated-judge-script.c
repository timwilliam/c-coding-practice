#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, m, i, j, len, err_count, char_read, temp, run;
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
		for(i = 0; i < n; i++){
			len = strlen(solution[i]);

			// Go through each line
			for(j = 0; j < len; j++){
				//printf("sol %c; team %c\n", solution[i][j], team_output[i][j]);
				if(solution[i][j] != team_output[i][j])	err_count++;
				char_read++;
			}
		}

		// Print the verdict
		printf("Run #%d: Result, read = %d, error = %d\n", run, char_read, err_count);
	}
}
