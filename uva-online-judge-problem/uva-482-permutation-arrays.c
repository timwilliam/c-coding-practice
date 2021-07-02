// Problem  : UVA 482 - Permutation Arrays
// Author   : timwilliam
// Compiled : 07/01/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_n_element(char *string){
    int i, count = 0;
    for(i = 0; i < strlen(string); i++){
        if(string[i] == ' ')
            count++;
    }

    return count+1;
}

int main(void){
    int MAX_ELEM = 20;
    int T, n_input, i, permute_index[MAX_ELEM], n_elem;
    char array_index[1000], array[1000], *token;
    char permute_array[MAX_ELEM][10];

    scanf("%d", &T);
    getchar();

    while(T--){
        getchar();

        memset(array_index, 0, sizeof(array_index));
        memset(array, 0, sizeof(array));
        memset(permute_array, 0, sizeof(permute_array[0][0]) * 20 * 10);
        memset(permute_index, 0, sizeof(permute_index));

        // index array p
        fgets(array_index, 1000, stdin);
        array_index[strcspn(array_index, "\n")] = 0;        
        n_elem = get_n_element(array_index);
        
        i = 0;
        token = strtok(array_index, " ");
        while(token != NULL){
            permute_index[atoi(token) - 1] = i; // where the magic happens
            token = strtok(NULL, " ");
            i++;
        }

        // a list numbers in floating point format
        fgets(array, 1000, stdin);
        array[strcspn(array, "\n")] = 0;

        i = 0;
        token = strtok(array, " ");
        while(token != NULL){
            strcpy(permute_array[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        
        // print out the list in its correct order 
        for(i = 0; i < n_elem; i++)
            printf("%s\n", permute_array[permute_index[i]]);
    }
}
