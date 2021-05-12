#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **str, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%s, ", str[i]);
	}
	printf("\n");
}

// sort the string ascendingly using insertion sort
void sort_str(char **str, int n){
	int key, i;
	char word[30];
	
	for(i = 1; i < n; i++){
		memset(word, 0, sizeof(word));

		key = i;
		strcpy(word, str[i]);

		while(key > 0 && strcmp(word, str[key-1]) < 0){
			strcpy(str[key], str[key-1]);
			key--;	
		}

		strcpy(str[key], word);
	}
}

// count the population of the species

int main(void){
	char **str_list, buffer[30];
	int i, n_pop, POP_MAX, SPEC_MAX, SPEC_NAME_LEN;

	POP_MAX = 1000000;
	SPEC_MAX = 10000;
	SPEC_NAME_LEN = 30;

	// allocate space to store the pointer to each string in the list
	str_list = malloc(POP_MAX * sizeof(char*));
	for(i = 0; i < POP_MAX; i++){
		str_list[i] = malloc(SPEC_NAME_LEN * sizeof(char));
	}
	
	n_pop = 0;
	while(n_pop < 29){
		fgets(str_list[n_pop], 30, stdin);
		str_list[n_pop][strcspn(str_list[n_pop], "\n")] = 0;

		n_pop++;
	}

	printf("Before\n");
	print_str(str_list, 29);

	sort_str(str_list, 29);

	printf("After\n");
	print_str(str_list, 29);

}
