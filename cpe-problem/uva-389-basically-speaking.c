// Problem  : UVA 388 - Basically Speaking
// Author   : timwilliam
// Compiled : 07/12/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int char_to_decimal(char input){
    if(input >= 'A' && input <= 'F')
        return input - 'A' + 10;
    else
        return input - '0';
}

int to_decimal(char *input, int input_base){
    int i, len, base_10, temp;
    
    len = strlen(input);
    base_10 = 0 ;
    for(i = 0; i < len; i++){
        temp = char_to_decimal(input[i]);
        if(temp == 0)
            continue;

        base_10 += temp * (int) pow(input_base, (len-i-1));
    }

    return base_10;
}

void to_base(int decimal, char *output, int output_base){
    int i;
    
    memset(output, '0', sizeof(output));

    i = 7; // only 7 digit for the display
    while(decimal > 0){
        output[i] = decimal % output_base;

        // convert the result to char
        if(output[i] >= 0 && output[i] <=9)
            output[i] = output[i] + '0';
        else if(output[i] >= 10)
            output[i] = output[i] - 10 + 'A';

        decimal /= output_base;
        i--;
    }
    
    return;
}

void print_output(char *output){
    int i;
    for(i = 1; i < 8; i++)
        printf("%c", output[i]);

    printf("\n");
    return;
}

int main(void){
    char input[9], output[9];
    int input_base, output_base, decimal;

    while(scanf("%s %d %d", input, &input_base, &output_base)){
        memset(output, 0, sizeof(output));

        decimal = to_decimal(input, input_base);
        to_base(decimal, output, output_base);
        print_output(output);
    }

    return 0;
}