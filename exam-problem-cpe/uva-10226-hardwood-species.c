// Problem  : UVA 10226 - Hardwood Species
// Author   : timwilliam
// Compiled : 07/12/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_POP = 1000000;
int MAX_SPECIES_NAME_LEN = 30;

int cmpfunc(const void *a, const void*b){
    return strcmp(*(char**) a, *(char**) b);
}

void print_result(char **list_of_trees, int pop_count){
    int i, species_count;
    char current_species[30];
    double percentage;

    species_count = 1;
    for(i = 0; i < pop_count; i++){
        strcpy(current_species, list_of_trees[i]);

        if(strcmp(current_species, list_of_trees[i+1]) == 0 && i+1 < pop_count){
            species_count++;
        }
        else{
            percentage = (double) species_count / (double) pop_count * 100.0;
            printf("%s %.4lf\n", current_species, percentage);

            species_count = 1;
        }
    }

    return;
}

int main(void){
    int i, T, pop_count;
    char **list_of_trees, input[32];
    
    list_of_trees = malloc(MAX_POP * sizeof(char*));
    for(i = 0; i < MAX_POP; i++)
        list_of_trees[i] = malloc(MAX_SPECIES_NAME_LEN * sizeof(char));

    scanf("%d", &T);
    getchar();

    while(T--){
        getchar();

        pop_count = 0;
        while(1){
            fgets(input, 30, stdin);
            if(input[0] == '\n')
                break;

            input[strcspn(input, "\n")] = 0;
            strcpy(list_of_trees[pop_count], input);
            pop_count++;
        }

        qsort(list_of_trees, pop_count, sizeof(*list_of_trees), cmpfunc);
        print_result(list_of_trees, pop_count);
        
        for(i = 0; i < MAX_POP; i++)
            memset(list_of_trees[i], 0, MAX_SPECIES_NAME_LEN * sizeof(char));
    }

    return 0;
}