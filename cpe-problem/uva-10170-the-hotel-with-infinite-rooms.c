// Program  : UVA 10170 - The Hotel with Infinite Rooms
// Author   : Timothy William
// Compiled : 04/19/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, S, D, n, temp;

    while(1){
        scanf("%d %d", &S, &D);
        if(S == 0 && D == 0)
            exit(0);
        
        n = S;
        temp = 1;
        for(i = 1; i <= D; i++){
            if(i == 1)
                continue;

            if(temp < n)
                temp++;
            else{
                temp = 1;
                n++;
            }   
        }

        printf("%d\n", n);
    }
}
