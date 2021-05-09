// Problem  : UVA 10062 - Tell Me the Frequencies
// Author   : timwilliam
// Compiled : 05/09/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
    return(*(int*) a - *(int*) b);
}

int main(void){
    char input[1000] = {0}, in_len;
    int result[96], i;

    while(scanf("%s", input) != EOF){
        in_len = strlen(input);

        // get the character occurences frequency
        memset(result, 0, sizeof(result));
        for(i = 0; i < in_len; i++){
            // result is used to store character w/ ASCII code 33-127
            result[input[i] - 32 - 1]++;
        }
        
        // encode it with its ASCII code so that it can be sorted
        for(i = 0; i < 96; i++){
            if(result[i] == 0){
                continue;
            }

            // encode_formula = number of occurences * 100000 + (128 - ASCII) * 1000 + ASCII code
            result[i] =  (result[i] * 100000) + ((128 - 33 - i) * 1000) + (33 + i);
        }
        
        // sort ascending
        qsort(result, 96, sizeof(int), cmpfunc);

        for(i = 0; i < 96; i++){
            if(result[i] == 0){
                continue;
            }

            printf("%d %d\n", result[i] % 1000, result[i] / 100000);
        }

        memset(input, 0, sizeof(input)); 
    }
}
