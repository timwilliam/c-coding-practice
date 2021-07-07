// Problem  : UVA 10922 - 2 the 9s
// Author   : timwilliam
// Compiled : 05/06/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_digits(char *number){
    int num_len, i, sum;
    
    num_len = strlen(number);
    sum = 0;
    for(i = 0; i < num_len; i++){
        sum = sum + (number[i] - '0');
    }

    return sum;
}

int get_nine_degree(char *number){
    int i, nine_degree, sum;

    nine_degree = 1;
    while(1){
        if(number[0] == '9')
            break;

        sum = sum_digits(number);
        if(sum % 9 == 0){
            nine_degree ++;
            memset(number, 0, sizeof(number));
            sprintf(number, "%d", sum);
        }
        else
            break;
    }

    return nine_degree;
}

int main(void){
    char number[1001], temp[1001];
    int sum, nine_degree;

    while(1){
        memset(number, 0, sizeof(number));
        memset(temp, 0, sizeof(temp));

        fgets(number, 1000, stdin);
        number[strcspn(number, "\n")] = 0;

        strcpy(temp, number);

        if(number[0] == '0')
            break;
     
        // NOTE: Although the program works, i think this check section can be further
        //       simplified. As some of the check logic here, also presents in get_nine_degree().
        //       It should be possible to merge them into 1 function.

        // check if input is multiple of 9, if yes, check its 9-degree
        sum = sum_digits(number);
        memset(number, 0, sizeof(number));
        sprintf(number, "%d", sum);

        if(sum % 9 != 0){
            printf("%s is not a multiple of 9.\n", temp);
        }
        else{
            nine_degree = get_nine_degree(number);
            printf("%s is a multiple of 9 and has 9-degree %d.\n", temp, nine_degree);
        }
    }
}
