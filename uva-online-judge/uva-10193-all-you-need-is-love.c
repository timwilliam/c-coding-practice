#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bin_to_dec(char *bin){
    int decimal, bin_len, i;
   
    bin_len = strlen(bin);
    decimal = 0;
    for(i = 0; i < bin_len; i++){
        decimal += (bin[i] - '0') * (int) pow(2, bin_len - i - 1);
    }
   
    return decimal;
}

int get_gcf(int number, int *factor){
    int i, j;
    
j = -1;
    for(i = 2; i < number; i++){
        if(number % i == 0){
            j++;
            factor[j] = i;            
            //printf("[DBG] A factor for %d is found: %d\n", number, i);
        }
    }

    return j + 1;
}

int main(void){
    int N, n, s1_factor[100], s2_factor[100], s1_n_factor, s2_n_factor, n_common, s1_dec, s2_dec, i, j;
    char s1[30], s2[30];

    scanf("%d", &N);
    getchar();
    for(n = 1; n <= N; n++){
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s1_factor, 0, sizeof(s1_factor));
        memset(s2_factor, 0, sizeof(s2_factor));
        n_common = 0;

        fgets(s1, 30, stdin);
        s1[strcspn(s1, "\n")] = 0; // remove trailing '\n'
        fgets(s2, 30, stdin);
        s2[strcspn(s2, "\n")] = 0; // remove trailing '\n'

        // convert binary to decimal 
        s1_dec = bin_to_dec(s1);
        s2_dec = bin_to_dec(s2);

        // get Greatest Common Factor
        s1_n_factor = get_gcf(s1_dec, s1_factor);
        s2_n_factor = get_gcf(s2_dec, s2_factor);
   
        // see if they have any common factor
        for(i = 0; i < s1_n_factor; i++){
            for(j = 0; j < s2_n_factor; j++){
                if(s1_factor[i] == s2_factor[j]){
                    //printf("[DEBUG] Found a common factor: %d\n", s1_factor[i]);
                    n_common++;
                }
            }
        }
    
        if(n_common > 0)
            printf("Pair #%d: All you need is love!\n", n);
        else
            printf("Pair #%d: Love is not all you need!\n", n);
    }
}
