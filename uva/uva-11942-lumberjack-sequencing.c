// Problem	: UVA 11942 - Lumberjack Sequencing
// Author	: timwilliam
// Compiled	: 06/27/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, length[10], current, prev, flag, i, j;

	scanf("%d", &N);

	for(j = 0; j < N; j++){
		if(i == 0)
			printf("Lumberjacks:\n");

		for(i = 0; i < 10; i++)
			scanf("%d", &length[i]);

		// Check for ascending
		flag = 1;
		for(i = 0; i < 10; i++){
			if(i == 0){
				prev = length[i];
				continue;
			}

			current = length[i];
			if(current < prev){
				flag = 0;
				break;
			}

			prev = current;
		}

		if(flag == 1){
			printf("Ordered\n");
			continue;
		}

		// Check for descending
		for(i = 0; i < 10; i++){
			if(i == 0){
				prev = length[i];
				continue;
			}

			current = length[i];
			if(current > prev)
				break;

			prev = current;
		}

		if(i == 10)
			flag = 1;

		if(flag == 1)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
}
