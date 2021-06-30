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
    int T, n_input, i;
    char array_index[1000], array[1000], *token;
    char **
    
    scanf("%d", &T);
    getchar();

    while(T--){
        getchar();

        memset(array_index, 0, sizeof(array_index));
        memset(array, 0, sizeof(array));

        fgets(array_index, 1000, stdin);
        array_index[strcspn(array_index, "\n")] = 0;        

        printf("elem %d\n", get_n_element(array_index));
        exit(0);

        token = strtok(array_index, " ");
        while(token != NULL){
            
        }


        fgets(array, 1000, stdin);
        array[strcspn(array, "\n")] = 0;

         
    }

}
