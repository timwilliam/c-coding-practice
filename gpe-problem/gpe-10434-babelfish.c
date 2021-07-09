// Problem  : GPE 10434 - Babelfish
// Author   : timwilliam
// Compildd : 07/09/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char eng[100], alien[100];
} Dictionary;

int main(void){
    Dictionary my_dict[10000];
    char temp[200], *pch;
    int count, i;

    count = -1;
    while(fgets(temp, 200, stdin)){
        count++;

        pch = strtok(temp, " ");
        if(pch[0] == '\n')
            break;
        strcpy(my_dict[count].eng, pch);
        my_dict[count].eng[strcspn(my_dict[count].eng, "\n")] = 0;

        pch = strtok(NULL, " ");
        strcpy(my_dict[count].alien, pch);
        my_dict[count].alien[strcspn(my_dict[count].alien, "\n")] = 0;
    }

    //printf("Count=%d\n", count);

    int found;
    while(fgets(temp, 12, stdin)){
        found = 0;

        temp[strcspn(temp, "\n")] = 0;
        for(i = 0; i < count; i++){
            if(strcmp(temp, my_dict[i].alien) == 0){
                found = 1;
                break;  
            }
        }

        if(found == 1)
            printf("%s\n", my_dict[i].eng);
        else   
            printf("eh\n");
    }
}
