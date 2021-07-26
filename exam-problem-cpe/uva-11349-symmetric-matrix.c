// Program  : UVA 11349 - Summetric Matrix
// Author   : timwilliam
// Compiled : 04/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i, j, n, t, matrix[10000], flag, step;

    scanf("%d", &t);

    for(i = 1; i <= t; i++){
        scanf("%d", &n);      

        // store the input array 
        j = 0;
        flag = 0; // 0 = symmetric
        memset(matrix, 0, sizeof(matrix));
        while(j < n * n){
            scanf("%d", &matrix[j]);
            j++;
        }

        // check if the matrix is symmetric or not
        j = 0;
        step = n * n - 1;
        while(step >= 1){
            if(matrix[j] == matrix[j + step] && matrix[j] > 0)
                step -= 2;
            else{
                flag = 1;
                break;
            }
            
            j++;
        }
        
        if(n = 1 && matrix[0] < 0)
            printf("Test #%d: Non-symmetric\n", i);
        else if(flag == 1)
            printf("Test #%d: Non-symmetric\n", i);
        else
            printf("Test #%d: Symmetric\n", i);
    }
}
