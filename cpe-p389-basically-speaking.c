#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void){
    char buffer[100], input[100], output[10], *token, temp;
    int base, target, in_len, i, base_10, digit;

    while(fgets(buffer, 100, stdin) != NULL){
        if(buffer[0] == '\n') break;
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        base_10 = 0;

        //TODO 1. Parse the buffer
        token = strtok(buffer, " ");
        strcpy(input, token); // Get the input number
        token = strtok(NULL, " ");
        base = atoi(token); // Get the base
        token = strtok(NULL, " ");
        target = atoi(token); // Get the target base
        //printf("Buffer: %s %d %d\n", input, base, target);

        //TODO 2. Convert input number to decimal
        in_len = strlen(input); // Get input char length
        for(i = 0; i < in_len; i++){
                //TODO Convert input that is in 'ABCDE' to a decimal number
                temp = input[in_len - 1 - i];
                if(temp >= '0' && temp <= '9') digit = temp - '0'; // Convert char to decimal number
                else if(temp >= 'A' && temp <= 'F') digit = temp - 'A' + 10;

                base_10 += digit * (int) pow(base, i); //Convert input to base 10
        }

        //TODO 3. Convert decimal to target base
        if(target == 10) printf("%d\n", base_10);
        else{
            continue; 
        }
    }
}
