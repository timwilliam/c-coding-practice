#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int MAX_ID = 3;
    int T, array_index[MAX_ID], i, temp;
    char array[MAX_ID][10];

    scanf("%d", &T);
    getchar();

    while(T--){
        getchar();

        memset(array, 0, sizeof(array));
        memset(array_index, 0, sizeof(array_index));

        for(i = 0; i < MAX_ID; i++){
            scanf("%d", &temp);
            array_index[temp-1] = i;
        }
            
        for(i = 0; i < MAX_ID; i++)
            scanf("%s", array[i]);

        for(i = 0; i < MAX_ID; i++)
            printf("%s\n", array[array_index[i]]);

        printf("\n");
    }

}
