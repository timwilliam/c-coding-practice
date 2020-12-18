// Program	: CPE - p10908 Largest Square
// Author	: timwilliam
// Compiled	: 12/18/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int T, Q, M, N, i, j;
	char square[100][100], buffer[101], center;
	int test[21][2], count, r, c, level;

	scanf("%d", &T); // Store the number of squares to be checked

	while(T > 0){
		scanf("%d %d %d", &M, &N, &Q);
		
		// Store the squares to an array, line by line
		j = 0;
		for(i = 0; i < M; i++){
			fflush(stdin);
			fgets(buffer, 100, stdin);
			
			buffer[strcspn(buffer, "\n")] = 0;
			strcpy(square[j], buffer);
			
			j++;
		}

		// Store the test cases
		for(i = 0; i < Q; i++) scanf("%d %d", &test[i][0], &test[i][1]);

		printf("%d %d %d\n", M, N, Q);
		
		// Check for largest square
		for(i = 0; i < Q; i++){
			// TODO Get the char at the center of the square to be checked
			count = 1;
			r = test[i][0]; c = test[i][1];
			center = square[r][c];
			
			// TODO Check the perimeter for the same character
			// 	Note that the size of aquare will always be an odd number
			level = 1;
			while(1){
				if(square[r-level][c+level] == center && square[r-level][c-level] == center){
					level++;
					count += 2;
				}
				else break;
			}

			printf("%d\n", count);
		}

		T--;
	}

}
