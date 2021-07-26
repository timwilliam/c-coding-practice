// Problem	: Print all possible string permutation in ascending order
// Author	: timwilliam
// Compiled	: 06/21/2021
// Tag		: recursive

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Remove a char, from a string to create new string
// e.g.: remove 'A' from 'ABC' to create 'BC'
char *create_string(char *string, int pos){
    int str_len = strlen(string), j = 0;
    char *new_string = malloc((str_len-1) * sizeof(char));

    for(int i = 0; i < str_len; i++){
        if(i == (pos))
            continue;

        new_string[j] = string[i];
        j++;
    }

    return new_string;
}

void permute_string(char *string, char *prefix){
    int str_len = strlen(string);
    
    if(str_len == 0){
        printf("%s\n", prefix);
        return;
    }
    
	for(int i = 0; i < str_len; i++){
		strncat(prefix, &string[i], 1);
		permute_string(create_string(string, i), prefix);
		prefix[strlen(prefix) - 1] = 0;		
	}

	return;
}

int main(void){
    char string[20], prefix[20];

    while(scanf("%s", string) != EOF){
		memset(prefix, 0, sizeof(prefix));
        permute_string(string, prefix);
    }
}
