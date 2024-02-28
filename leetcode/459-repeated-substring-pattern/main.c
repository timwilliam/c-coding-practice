#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
    int i, substringLen, sLen, j, numOfSubstring, counter;
    sLen = strlen(s);

    if(sLen == 1)
        return false;

    for(i = sLen - 1; i > 0; i--) {
        if(sLen % i == 0) {
            substringLen = i;
            numOfSubstring = sLen / i;
            counter = 0;
            
            for(j = 1; j < numOfSubstring; j++) {
                if(strncmp(&s[0], &s[j * substringLen], substringLen) == 0) {
                    counter++;
                }
            }

            if(counter == sLen / substringLen - 1)
                return true;
        }
    }

    return false;
}

int main(void) {
    // char *s = "abab";            // true
    // char *s = "aba";             // false
    // char *s = "abcabcabcabc";    // true
    // char *s = "abcdefgh";        // false
    // char *s = "abcabcabc";       // true
    // char *s = "abcabdabc";       // false
    char *s = "abaababaab";      // true

    printf("%d\n", repeatedSubstringPattern(s));

    return 0;
}