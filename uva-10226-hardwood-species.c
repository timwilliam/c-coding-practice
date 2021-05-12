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
void calculate_pop_percentage(char **str, int n, int n_pop){
	int i, current_species_count;
	double percentage;
	char current_species[30];

	// other possible solution: using a combination of strstr() to get the first occurence of string,
	// 					and using strchr() to get the last occurence of string

	current_species_count = 1;
	for(i = 0; i < n; i++){
		strcpy(current_species, str[i]);

		if(strcmp(current_species, str[i+1]) == 0){
			current_species_count++;
		}
		else{
			percentage = (double) current_species_count / (double) n_pop * 100;			
			printf("%s %.4lf\n", current_species, percentage);

			current_species_count = 1;
		}
	}
}

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

	sort_str(str_list, 29);

	calculate_pop_percentage(str_list, 29, n_pop);
}
