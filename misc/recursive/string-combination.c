#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_combination(char *string, int r){
	int str_len = strlen(string);

	//printf("[DBG] str=%s, str_len=%d, r=%d\n", string, str_len, r);
	if(str_len == r){
		printf("%s\n", string);
		return;
	}
	else if(r == 0){
		return;
	}

	char *temp = malloc((str_len - 1) * sizeof(char));
	for(int i = 0; i < (str_len - 1); i++)
		temp[i] = string[i];
	printf("[DBG] temp = %s\n", temp);
	get_combination(temp, r);
	//get_combination(temp, r-1);
	return;
}

int main(void){
	char string[10];
	int r = 1;

	while(scanf("%s", string) != EOF){
		get_combination(string, r);
	}
}
