// Program  : UVA 490 - Rotating Sentences
// Author   : timwilliam
// Compiled : 04/11/2021

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char buffer[100][100], output[10000], temp[2];
    int n_line, i, j, max_len, cur_len;

    memset(buffer, 0, sizeof(buffer[0][0]) * 100 * 100);
    i = max_len = 0;

    while(fgets(buffer[i], 100, stdin) != NULL){
        buffer[i][strcspn(buffer[i], "\n")] = 0; // remove trailing "\n"

        cur_len = strlen(buffer[i]);
        if(max_len < cur_len)
            max_len = cur_len;

        i++;
    }
    
    n_line = i - 1;
    memset(output, 0, sizeof(output));

    j = 0;
    while(1){
        // Put each character in each row of the buffer to the "output" array
        for(i = n_line; i >= 0; i--){
            if(buffer[i][j] == 0){
                sprintf(temp, "%c", ' ');
                strcat(output, temp);
            }
            else{
                sprintf(temp, "%c", buffer[i][j]);
                strcat(output, temp);
            }
        }

        if(j + 1 >= max_len)
            break;

        j++;
        
        // First character in each "output" array row is completed, go to next line
        sprintf(temp, "%c", '\n');
        strcat(output, temp);
    }
    printf("%s", output);
}
