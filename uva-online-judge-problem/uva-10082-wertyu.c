// Problem  : UVA 10082 - WERTYU
// Author   : timwilliam
// Compiled : 06/26/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// str here will be the row0 - row3 dictionary
int get_loc(char *str, char key){
    int i, flag;

    flag = 0;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == key){
            flag = 1;
            break;
        }
    }
    
    if(flag == 1)
        return i;
    else
        return -1;
}

int main(void){
    // dictionary
    char row0[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0};
    char row1[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\', 0};
    char row2[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 0};
    char row3[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', 0};

    char input[1000] = {0};
    char output[1000] = {0};
    int str_len, temp, i;

    while(1){
        fgets(input, 1000, stdin);
        str_len = strlen(input);

        for(i = 0; i < str_len; i++){
            if(input[i] == ' '){
                output[i] = ' ';
                continue;
            }

            temp = get_loc(row0, input[i]);
            if(temp >= 0) output[i] = row0[temp - 1];
            temp = get_loc(row1, input[i]);
            if(temp >= 0) output[i] = row1[temp - 1];
            temp = get_loc(row2, input[i]);
            if(temp >= 0) output[i] = row2[temp - 1];
            temp = get_loc(row3, input[i]);
            if(temp >= 0) output[i] = row3[temp - 1];
        }

        printf("%s\n", output);
        memset(input, 0, sizeof(input) / sizeof(input[0]));
        memset(output, 0, sizeof(output) / sizeof(output[0]));
    }
}
