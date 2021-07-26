// Program  : UVA 11332 - Summing Digits
// Author   : timwilliam
// Date     : 04/10/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char input[11], temp[11];
    int input_len, sum, i;

    while(1){
        memset(input, 0, sizeof(input));
        memset(temp, 0, sizeof(temp));

        fgets(input, 11, stdin);
        input[strcspn(input, "\n")] = 0;

        if(input[0] - '0' == 0) break; // Check for exit condition

        input_len = strlen(input);

        // Stop when it becomes a single digit
        if(input_len == 1){
            printf("%d\n", input[0] - '0');
            continue;
        }
        // Sum all of the digits
        else{
            strcpy(temp, input);
            while(input_len > 1){
                sum = 0;
 
                for(i = 0; i < input_len; i++)
                    sum = sum + (temp[i] - '0');
                
                memset(temp, 0, sizeof(temp));
                sprintf(temp, "%d", sum);
                input_len = strlen(temp);
            }
            printf("%d\n", sum);
        }
    }
}
