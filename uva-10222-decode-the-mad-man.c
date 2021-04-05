// Program  : UVA 10222 - Decode the Mad Man
// Author   : Timothy William
// Compiled : 04/05/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char dict[] = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char buffer[1000] = {0}, str[2], temp;
    int i, pos, str_len;

    fgets(buffer, 1000, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    str_len = strlen(buffer);
    
    str[1] = 0;
    for(i = 0; i < str_len; i++){
        if(buffer[i] == ' '){
            printf(" ");
        }
        else{
            str[0] = buffer[i];
            pos = strcspn(dict, str); // locate the first occurence of str
            
            temp = dict[pos - 2]; // shift by 2 keys to the left, on a keyboard
            
            if(temp >= 'A' && temp <= 'Z')
                temp = temp + 32; // convert to low caps
            
            printf("%c", temp);
        }
    }

    printf("\n");
}
