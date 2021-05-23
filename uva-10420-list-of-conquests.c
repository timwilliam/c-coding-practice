// Problem  : UVA 10420 - List of Conquests
// Author   : timwilliam
// Compiled : 05/23/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// based on insertion sort
void sort_list(char **list, int n){
    int key, i;
    char word[75];

    for(i = 1; i < n; i++){
        memset(word, 0, sizeof(word));

        key = i;
        strcpy(word, list[i]);

        while(key > 0 && strcmp(word, list[i-1]) < 0){
            strcpy(list[key], list[key-1]);
            key--;
        }
        
        strcpy(list[key], word);
    }
}

void get_country(char *buffer, char *country){
    int toggle, len, i, j;
 
    len = strlen(buffer);
    toggle = 0;
    j = 0;

    for(i = 0; i < len; i++){
        if(buffer[i] == ' '){
            if(toggle == 1)
                break;

            continue;
        }
        else{
            toggle = 1;
            country[j] = buffer[i];
            j++;
        }
    } 
}

int main(void){
    int n, len, i, count;
    char buffer[75], country[75], **conquest, current[75];
    
    // NOTE: I made the assumption that a name will only appear once

    scanf("%d", &n);
    getchar();

    conquest = malloc(n * sizeof(char*));

    // store country name in a list
    for(i = 0; i < n; i++){
        memset(buffer, 0, sizeof(buffer));
        memset(country, 0, sizeof(country));        

        fgets(buffer, 75, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        get_country(buffer, country);
        len = strlen(country);
        conquest[i] = malloc(len * sizeof(char));
        strcpy(conquest[i], country);
    }

    // sort the list alphabetically
    sort_list(conquest, n);

    // count each country occurences
    count = 0;
    for(i = 0; i < n; i++){
        strcpy(current, conquest[i]);

        if(i < n - 1 && strcmp(current, conquest[i+1]) == 0){
            count++;
            continue; 
        }
        else{
            printf("%s %d\n", current, count+1);
            count = 0;
        }
    }
}
