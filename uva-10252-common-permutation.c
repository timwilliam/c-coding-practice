#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char a[1000], b[1000], str_len, i;
    int prmtn[26];

    while(1){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(prmtn, 0, sizeof(prmtn));

        if(fgets(a, 1000, stdin) == NULL)
            break;

        a[strcspn(a, "\n")] = 0;

        fgets(b, 1000, stdin);
        b[strcspn(b, "\n")] = 0;

        str_len = strlen(a);
        for(i = 0; i < str_len; i++){
            prmtn[a[i] - 'a'] = 1;
        }

        /*
        for(i = 0; i < 26; i++){
            printf("%d, ", prmtn[i]);
        }
        printf("\n");*/

        str_len = strlen(b);
        for(i = 0; i < str_len; i++){
            if(prmtn[b[i] - 'a'] == 2) continue;
            prmtn[b[i] - 'a'] += 1;
        }

        /*
        for(i = 0; i < 26; i++){
            printf("%d, ", prmtn[i]);
        }
        printf("\n");*/
        
        for(i = 0; i < 26; i++){
            if(prmtn[i] > 1)
                printf("%c", i + 'a');
        }
        printf("\n");
    }
}
