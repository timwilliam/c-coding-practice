// Problem	: UVA 10409 - Die Game
// Author	: timwilliam
// Compiled	: 05/14/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

int main(void){
	int n_cmd, i;
	char command[1024][6];
	int T = 1, B = 6, N = 2, S = 5, E = 4, W = 3;

	while(1){
		memset(command, 0, sizeof(command[0][0]) * 1024 * 6);

		scanf("%d", &n_cmd);

		if(n_cmd == 0)
			break;

		for(i = 0; i < n_cmd; i++){
			scanf("%s", command[i]);
			getchar();
			
			command[i][strcspn(command[i], "\n")] = 0;
			
			if(strcmp(command[i], "north") == 0){
				swap(&N, &T);
				swap(&T, &S);
				swap(&S, &B);
			}
			else if(strcmp(command[i], "south") == 0){
				swap(&S, &T);
				swap(&T, &N);
				swap(&N, &B);
			}
			else if(strcmp(command[i], "east") == 0){
				swap(&E, &T);
				swap(&T, &W);
				swap(&W, &B);
			}
			else if(strcmp(command[i], "west") == 0){
				swap(&W, &T);
				swap(&T, &E);
				swap(&E, &B);
			}
		}

		printf("%d\n", T);

		// reset the dice
		T = 1; B = 6; N = 2; S = 5; E = 4; W = 3;
	}
}
