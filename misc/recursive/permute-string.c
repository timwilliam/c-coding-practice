#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int factorial(int n){
    if(n == 1)
        return 1;

    return n * factorial(n-1);
}

void permute_string(char *string){
    int str_len = strlen(string);
    
    if(str_len == 1){
        printf("%s\n", string);
        return;
    }

    for(int i = 0; i < str_len; i++){
        printf("%c", string[i]);
        permute_string(create_string(string, i));
    }

    return;
}

int main(void){
    char string[10];

    while(scanf("%s", string) != EOF){
        permute_string(string);
    }
}
