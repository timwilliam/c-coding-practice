// Problem	: UVA 10189 - Minesweeperr
// Author	: timwilliam
// Compiled	: 05/10/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int M, N, T, i, j, k;
	char input[100][100], minesweep[100][100];

	T = 1;
	while(1){
		scanf("%d %d", &N, &M);

		if(M == 0 && N == 0)
			break;

		memset(input, 0, sizeof(input[0][0]) * M * N);
		memset(minesweep, 0, sizeof(minesweep[0][0]) * M * N);

		for(i = 0; i < N; i++){
			scanf("%s", input[i]);
			input[i][strcspn(input[i], "\n")] = 0;
		}
		
		printf("Field #%d:\n", T);

		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(input[i][j] == '*'){
					minesweep[i][j] = '*';	
					continue;	
				}

				// check all 8 adjacent squares
				if(j + 1 < M && input[i][j+1] == '*') // i, j+1
					minesweep[i][j]++;
			
				if(i + 1 < N && j + 1 < M && input[i+1][j+1] == '*') // i+1, j+1
					minesweep[i][j]++;
		
				if(i + 1 < N && input[i+1][j] == '*') // i+1, j
					minesweep[i][j]++;
			
				if(i + 1 < N && j - 1 >= 0 && input[i+1][j-1] == '*') // i+1, j-1
					minesweep[i][j]++;
			
				if(j - 1 >= 0 && input[i][j-1] == '*') // i, j-1
					minesweep[i][j]++;
			
				if(i - 1 >= 0 && j - 1 >= 0 && input[i-1][j-1] == '*') // i-1, j-1
					minesweep[i][j]++;
			
				if(i - 1 >= 0 && input[i-1][j] == '*') // i-1, j
					minesweep[i][j]++;
			
				if(i - 1 >= 0 && j + 1 < N && input[i-1][j+1] == '*') // i-1, j+1
					minesweep[i][j]++;
			}
		}		

		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(minesweep[i][j] == '*')
					printf("%c", minesweep[i][j]);
				else
					printf("%d", minesweep[i][j]);
			}
			printf("\n");
		}

		T++;
	}
}
