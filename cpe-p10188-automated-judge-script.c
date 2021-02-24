#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, m, i;
	char solution[100][120], team_output[100][120];

	while(1){
		// Reset the array
		memset(solution, 0, sizeof(solution[0][0]) * 100 * 120);
		memset(team_output, 0, sizeof(team_output[0][0]) * 100 * 120);

		// Get the input: solution
		scanf("%d", &n);
		if(n == 0) break;

		for(i = 0; i < n; i++){
			scanf(" %s", solution[i]); // Space is to remove trailing '\n'
			printf("buffer %s\n", solution[i]);
		}

		// Get the input: team_output
		scanf("%d", &m);

		for(i = 0; i < m; i++){
			scanf(" %s", team_output[i]); // Space is to remove trailing '\n'
			printf("buffer %s\n", team_output[i]);
		}
		
		printf("##########\n");
	}
}
