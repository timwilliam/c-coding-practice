/**
 * @file main.c
 * @author timwilliam (findtimwilliam@gmail.com)
 * @brief LeetCode: 13. Roman to Integer
 * @version 1.0
 * @date 2024-02-22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_LEN 15

/**
 * @brief Convert a roman numeral to integer
 * 
 * @remark Time complexity = O(1)
 * 
 * @param numeral A Roman numeral
 * @return int Integer representation of a Roman numeral
 */
int numeralToInt(char numeral){
    switch (numeral)
    {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
        default:
            return 1;
    }
}

/**
 * @brief Convert Roman numerals to integer
 * 
 * @remark Time complexity = O(n)
 * 
 * @param s Roman numerals
 * @return int Integer representation of Roman numerals
 */
int romanToInt(char *s){
    int i;
    char prevRoman;         // store previous roman numeral
    int sLen = strlen(s);
    int integer = 0;

    integer += numeralToInt(s[0]);
    prevRoman = s[0];

    // Go from left to right (largest number to smallest number)
    // If the current Roman numeral is larger than the previous Roman numeral, 
    //   substract the previous Roman numeral integer value and add the current corrected Roman numeral integer value
    // Otherwise, simply add the integer value of each Roman numeral
    for(i = 1; i < sLen; i++){
        if(numeralToInt(s[i]) > numeralToInt(prevRoman))
            integer = (integer - numeralToInt(prevRoman)) + (numeralToInt(s[i]) - numeralToInt(prevRoman));
        else
            integer += numeralToInt(s[i]);

        prevRoman = s[i];
    }

    return integer;
}

int main(void){
    char s[S_LEN];
    memset(s, 0, S_LEN * sizeof(char));

    // strcpy(s, "III"); // 3
    // strcpy(s, "LVIII"); // 58
    // strcpy(s, "IV"); // 4
    strcpy(s, "MCMXCIV"); // 1994

    printf("%d\n", romanToInt(s));
    
    return 0;
}