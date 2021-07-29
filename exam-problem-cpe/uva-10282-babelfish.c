// Program  : UVA 10282 - Babelfish
// Author   : timwilliam
// Compiled : 07/29/2021
// Note     : code can be further optimized, at the current state search must be slow for large dataset

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dict{
    char eng[10], alien[10];
}DICT;

int main(void){
    int ENTRIES = 100000, n_entries = 0, i;
    char buffer[23], *pch;

    DICT *my_dict = (DICT*) malloc(ENTRIES * sizeof(DICT));

    while(1){
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 23, stdin);
        if(buffer[0] == '\n')
            break;

        buffer[strcspn(buffer, "\n")] = 0;
        
        pch = strtok(buffer, " ");
        strcpy(my_dict[n_entries].eng, pch);
        pch = strtok(NULL, " ");
        strcpy(my_dict[n_entries].alien, pch);

        n_entries++;
    }
    
    while(1){
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 12, stdin);
        if(buffer[0] == '\n')
            break;

        buffer[strcspn(buffer, "\n")] = 0;
        for(i = 0; i < n_entries; i++)
            if(strcmp(buffer, my_dict[i].alien) == 0){
                printf("%s\n", my_dict[i].eng);
                break;
            }

        if(i == n_entries)
            printf("eh\n");
    }

    return 0;
}