/**
 * @file main.c
 * @author timwilliam (findtimwilliam@gmail.com)
 * @brief LeetCode: 389. Find the Difference
 * @version 1.0
 * @date 2024-02-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NUM_OF_ALPHABET = 26;

/**
 * @brief Count the number of occurences of a character in a string.
 * 
 * @remark Time complexity = O(n)
 * 
 * @param str Input string
 * @param strLen Length of input string
 * @param charOccurences Integer array containing the character occurences count
 */
void countCharOccurences(char *str, int strLen, int *charOccurences) {
    int i;

    for (i = 0; i < strLen; i++) {
        charOccurences[str[i] - 'a'] += 1;
    }

    return;
}

/**
 * @brief Finds the character difference between two lowercase alphabet string s and t.
 * 
 * @remark Time complexity = O(n)
 * 
 * @param s The first string
 * @param t The second string that holds one extra character compared to the first string s
 * @return char The extra character found in second string t, or else NUL if s equals t
 */
char findTheDifference(char *s, char *t) {

    // Edge case where s happens to be an empty string
    if(strlen(s) == 0) {
        return t[0];
    }
    
    int i;
    int charOccurencesOfS[NUM_OF_ALPHABET] = {0};
    int charOccurencesOfT[NUM_OF_ALPHABET] = {0};

    countCharOccurences(s, strlen(s), charOccurencesOfS);
    countCharOccurences(t, strlen(t), charOccurencesOfT);

    for (i = 0; i < NUM_OF_ALPHABET; i++) {
        if (charOccurencesOfT[i] - charOccurencesOfS[i] != 0) {
            return 'a' + i;
        }
    }

    return 0;
}

/**
 * @brief Finds the character difference by counting the difference of character occurences 
 *          between string s and string t. String t should have one character that has an extra
 *          occurences count compared to string s.
 * 
 */
int main(void){
    char difference;
    
    char* s = "abcde";
    char* t = "abcd";

    difference = findTheDifference(s, t);
    printf("%c\n", difference);

    return 0;
}