// Problem  : UVA 488 - Triangle Wave
// Author   : timwilliam
// Compiled : 05/30/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T, A, F, i, j, k, temp;

    scanf("%d", &T);
    while(T--){
        getchar();
        scanf("%d", &A); 
        scanf("%d", &F);
   
        printf("\n"); 
        // frequency
        for(i = 0; i < F; i++){
            // amplitude
            temp = 1;
            for(j = 1; j <= (2 * A - 1); j++){
                for(k = 0; k < temp; k++)
                    printf("%d", temp);
                
                printf("\n");

                if(j < A)
                    temp++;
                else if(j >= A)
                    temp--;
            }
            printf("\n");
        }
    }
}
