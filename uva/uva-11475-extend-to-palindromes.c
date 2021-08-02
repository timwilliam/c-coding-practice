// Problem  : UVA 11475 - Extend to Palindromes
// Author   : timwilliam
// Compiled : 08/02/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *string){
    int i,  str_len = strlen(string);
    
    char *temp = (char*) malloc(str_len * sizeof(char));
    strcpy(temp, string);

    for(i = 0; i < str_len; i++)
        string[i] = temp[str_len - 1 - i];

    return;
}

int main(void){
    char *pch, buffer[100000], temp[100000];
    int buff_len, palin_len;

    while(scanf("%s", buffer) != EOF){
        palin_len = 0;
        memset(temp, 0, sizeof(temp));

        buff_len = strlen(buffer);

        // assume that every string is constructed by a palindrome with length >= 1
        //   so, we want to find the subset of string in the buffer that is not a palindrome,
        //   and then concatenate that subset of string to the end of the buffer but in reverse
        // e.g.:    amanaplanacanal
        //                lanacanal       --> longest subset of buffer that is already a palindrome of length 9 (palin_len)
        //          amanap                --> subset of string to be concatenated to the end of buffer but in reverse order
        //          amanaplanacanalpanama --> the result
        temp[palin_len] = buffer[buff_len - (1 + palin_len)];
        pch = strstr(buffer, temp);
        while(pch != NULL && (pch - buffer + palin_len) <= buff_len){
            palin_len++;
            temp[palin_len] = buffer[buff_len - (1 + palin_len)];
            pch = strstr(buffer, temp);
        }

        // buffer is already a palindrome, nothing to do here
        if(palin_len > buff_len){
            printf("%s\n", buffer);
        }
        else{
            memset(temp, 0, sizeof(temp));
            strncpy(temp, buffer, buff_len - palin_len);
            reverse_string(temp);
            strcat(buffer, temp);
            printf("%s\n", buffer);
        }
    }

    return 0;
}