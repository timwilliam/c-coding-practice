#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char str[4][30], int n){
	int i;
	printf("Array: ");
	for(i = 0; i < n; i++){
		printf("%s, ", str[i]);
	}
	printf("\n");
}

// sort the array ascendingly using insertion sort
void sort_str(char str[4][30], int n){
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

int main(void){
	char str[4][30] = {"Cherry", "Ash", "Basswood", "Aspen"};
	int n = 4;

	print_str(str, n);
	sort_str(str, n);
	print_str(str, n);
}
