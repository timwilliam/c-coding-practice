// Program  : UVA 10038 - Jolly Jumpers
// Author   : timwilliam
// Compiled : 04/15/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, n, input[3000], dict[3000], temp, jolly;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }

    // by definition sequence of single integer is Jolly
    if(n == 1){
        printf("Jolly\n");
        exit(0);
    }

    // store in dictionary, which number 
    for(i = 0; i < n - 1; i++){
        temp = abs(input[i+1] - input[i]);
        dict[temp] += 1;
    }

    // check for jolliness ~
    jolly = 0;
    for(i = 1; i < n; i++){
        if(dict[i] > 0)
            jolly++;
    }

    if(jolly == n -1)
        printf("Jolly\n");
    else
        printf("Not Jolly\n");
}
