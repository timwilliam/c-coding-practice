// Program  : UVA 10252 - Common Permutation
// Author   : timwilliam
// Compiled : 04/10/2021  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char a[1000], b[1000], str_len, i;
    int count_a[26], count_b[26], n;

    while(1){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(count_a, 0, sizeof(count_a));
        memset(count_b, 0, sizeof(count_b));

        // Break if EOF is inputted
        if(fgets(a, 1000, stdin) == NULL)
            break;

        // Remove trailing "\n" character
        a[strcspn(a, "\n")] = 0;

        fgets(b, 1000, stdin);
        b[strcspn(b, "\n")] = 0;

        // Count the number of char occurences in a
        str_len = strlen(a);
        for(i = 0; i < str_len; i++){
            count_a[a[i] - 'a'] += 1;
        }

        // Count the number of char occurences in b
        str_len = strlen(b);
        for(i = 0; i < str_len; i++){
            count_b[b[i] - 'a'] += 1;
        }

        // Print out the permutation of a and b if any
        for(i = 0; i < 26; i++){
            // This is to handle case where a character occur more than once
            //  in both a and b  
            if(count_a[i] >= 1 && count_b[i] >= 1){
                n = count_a[i];
                if(count_b[i] < n)
                    n = count_b[i];
            }
            else
                n = 0;

            while(n--)
                printf("%c", i + 'a');
        }
        printf("\n");
    }
}
