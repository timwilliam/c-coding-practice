// Problem	: UVA 11192 - Group Reverse
// Author	: timwilliam
// Compiled	: 06/28/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int G, str_len, i, j, k;
	char input[101], **str_group;

	while(1){
		scanf("%d", &G);
		if(G == 0)
			break;

		scanf("%s", input);
		str_len = strlen(input);

		// allocate memory to store the group of strings	
		str_group = malloc(G  * sizeof(char*));
		for(i = 0; i < G; i++)
			str_group[i] = malloc((str_len / G) * sizeof(char));

		// chop the strings into groups
		j = 0;
		k = 0;
		for(i = 0; i < str_len; i++){
			// change to the next one once a group is fully filled
			if(i % (str_len / G) == 0 && i > 0){
				j++;
				k = 0;
			}

			str_group[j][k] = input[i];
			k++;
		}

		// print each group of strings in reverse order
		for(i = 0; i < G; i++){
			for(j = (str_len / G) - 1; j >= 0; j--)
				printf("%c", str_group[i][j]);
		}
		printf("\n");


		// free the previously allocated memory
		for(i = 0; i < G; i++)
			free(str_group[i]);
		free(str_group);
	}
}
