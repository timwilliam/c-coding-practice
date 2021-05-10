#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
    const char *aa = *(const char**) a;
    const char *bb = *(const char**) b;

    return strcmp(aa, bb);
}

void print_array(char array[10000][30], int n){
	int i;
	printf("Array: ");
	for(i = 0; i < n; i++){
		printf("%s ", array[i]);
	}
	printf("\n");
}

int main(void){
	int T, toggle, n_species, n_input, i;
	char buffer[30], list[10000][30];

	scanf("%d", &T);
	getchar();

	while(T--){
		getchar(); // eat the blank line
		memset(list, 0, sizeof(list[0][0]) * 10000 * 30);
		n_species = 0;
		n_input = 0;

		while(1){
			memset(buffer, 0, sizeof(buffer));
			fgets(buffer, 30, stdin);
			
			if(buffer[0] == '\n')
				break;
			else
				buffer[strcspn(buffer, "\n")] = 0;

			strcpy(list[n_input], buffer);
			n_input++;
		}

		// sort alphabetically
		qsort(list, n_input, sizeof(char*), cmpfunc);
		print_array(list, n_input);

		/*
		for(i = 0; i < n_input; i++){
			//printf("i %d\n", i);
			memset(buffer, 0, sizeof(buffer));
		
			strcpy(buffer, list[i]);
			
			// for when there are repetitions of species in the list
			if(strcmp(buffer, list[i]) == 0){
				n_species++;
			}

			printf("%s %d\n", list[i], i);
		}*/
	}
}
