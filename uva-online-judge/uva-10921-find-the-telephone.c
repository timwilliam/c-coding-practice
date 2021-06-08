// Problem	: UVA 10921 - Find the Telephone
// Author	: timwilliam
// Compiled	: 06/08/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char input[30] = {0};
	int i, len, count_caps = 0, count_hyp = 0;

	while(scanf("%s", input) != EOF){
		len = strlen(input);

		for(i = 0; i < len; i++){
			if(input[i] == '-'){
				count_hyp++;
				printf("-");	
				continue;
			}
			else if(input[i] == '1' || input[i] == '0'){
				printf("%c", input[i]);
				continue;
			}
			else if(input[i] >= 'A' && input[i] <= 'C'){
				printf("2");
			}
			else if(input[i] >= 'D' && input[i] <= 'F'){
				printf("3");
			}
			else if(input[i] >= 'G' && input[i] <= 'I'){
				printf("4");
			}
			else if(input[i] >= 'J' && input[i] <= 'L'){
				printf("5");
			}
			else if(input[i] >= 'M' && input[i] <= 'O'){
				printf("6");
			}
			else if(input[i] >= 'P' && input[i] <= 'S'){
				printf("7");
			}
			else if(input[i] >= 'T' && input[i] <= 'V'){
				printf("8");
			}
			else if(input[i] >= 'W' && input[i] <= 'Z'){
				printf("9");
			}
			count_caps++;
		}

		printf(" %d %d\n", count_caps, count_hyp);

		count_caps = count_hyp = 0;
		memset(input, 0, sizeof(input));
	}	
}
