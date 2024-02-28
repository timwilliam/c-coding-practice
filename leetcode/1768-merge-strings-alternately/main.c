/**
 * @file main.c
 * @author timwilliam (findtimwilliam@gmail.com)
 * @brief LeetCode: 1768. Merge Strings Alternately
 * @version 1.0
 * @date 2024-02-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Merge two string alternately
 * 
 * @remark Time complexity = O(n)
 * 
 * @param word1 Input string 1
 * @param word2 Input string 1
 * @return char* Alternately merged string
 */
char *mergeAlternately(char * word1, char * word2){
    int word1Len = strlen(word1);
    int word2Len = strlen(word2);

    int i = 0; // for tracking index of word1
    int j = 0; // for tracking index of word2
    int k = 0; // for tracking index of mergedWord

    // create char array and initialize it with '/0'
    // notice the extra space for '\0' (terminating NULL character)
    char *mergedWord = malloc((word1Len + word2Len + 1) * sizeof(char));    
    memset(mergedWord, '\0', ((word1Len + word2Len + 1) * sizeof(char)));

    while(1) {
        if(i >= word1Len && j >= word2Len) {
            break;
        }

        if(i < word1Len) {
            mergedWord[k] = word1[i];
            i++;
            k++;
        }

        if(j < word2Len) {
            mergedWord[k] = word2[j];
            j++;
            k++;
        }
    }

    return mergedWord;
}

/**
 * @brief Keep adding char from word1 and word2 to mergedWord until both tracking index
 *          for word1 and word2 are equal to word1Len and word2Len
 * 
 */
int main(void){
    // char word1[] = "abc";
    // char word2[] = "pqr";

    char word1[] = "ab";
    char word2[] = "pqrs";

    // char word1[] = "abcd";
    // char word2[] = "pq";

    // char word1[] = "a";
    // char word2[] = "p";

    printf("%s\n", mergeAlternately(word1, word2));

    return 0;
}